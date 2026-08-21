/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "erpc_spi_slave_fsp_transport.hpp"

#include <cstdio>
#include <new>
#include <cstring>

#include "bsp_cfg.h"

extern "C" {
#include "ra6w1_data_path.h"
}

extern "C" {
#include "r_gpio_w.h"
#include "r_spi_w.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "semphr.h"
}


using namespace std;
using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

#define ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO

#ifndef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
#define ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN 2U
#define ERPC_BOARD_SPI_SLAVE_READY_MARKER1 0xABU
#define ERPC_BOARD_SPI_SLAVE_READY_MARKER2 0xCDU
#endif

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

static volatile bool s_isTransferCompleted = false;
static SpiSlaveTransport *s_spi_slave_instance = NULL;

enum spi_slave_io_op
{
    kSpiSlaveIoOp_Receive = 0,
    kSpiSlaveIoOp_Send,
};

struct spi_slave_io_req
{
    spi_slave_io_op op;
    const uint8_t *tx;
    uint8_t *rx;
    uint32_t size;
    erpc_status_t result;
    SemaphoreHandle_t done;
};

static QueueHandle_t s_spi_slave_tx_q = NULL;
static QueueHandle_t s_spi_slave_rx_q = NULL;
static TaskHandle_t s_spi_slave_io_task = NULL;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
/* @brief Initialize the GPIO used to notify the SPI Master */
void SpiSlaveTransport::SpiSlaveTransport_NotifyTransferGpioInit(void)
{
	uint32_t pin_cfg = ((uint32_t) IOPORT_CFG_DRIVE_STRENGTH_BA_8MA
					  | (uint32_t) IOPORT_CFG_PORT_DIRECTION_OUTPUT
					  | (uint32_t) IOPORT_CFG_PORT_OUTPUT_LOW
					  | (uint32_t) IOPORT_CFG_SLEW_RATE_SLOW);

	R_GPIO_W_PinCfg(m_ioport_inst->p_ctrl, m_int_pin, pin_cfg);
}

/* @brief Notify the SPI Master that the Slave is ready for a new transfer */
//static inline void SpiSlaveTransport_NotifyTransferGpioReady(void)
void SpiSlaveTransport::SpiSlaveTransport_NotifyTransferGpioReady(void)
{
	R_GPIO_W_PinWrite(m_ioport_inst->p_ctrl, m_int_pin, BSP_IO_LEVEL_HIGH);
}

/* @brief Notify the SPI Master that the Slave has finished the transfer */
//static inline void SpiSlaveTransport_NotifyTransferGpioCompleted(void)
void SpiSlaveTransport::SpiSlaveTransport_NotifyTransferGpioCompleted(void)
{
	R_GPIO_W_PinWrite(m_ioport_inst->p_ctrl, m_int_pin, BSP_IO_LEVEL_LOW);
}

#endif

void SpiSlaveTransport::transfer_cb(void)
{
	SpiSlaveTransport_NotifyTransferGpioCompleted();

#if ERPC_THREADS
    m_txrxSemaphore.putFromISR();
#else
    s_isTransferCompleted = true;
#endif
}

static void SPI_SlaveUserCallback(spi_callback_args_t * p_args)
{
    SpiSlaveTransport *transport = (SpiSlaveTransport *)p_args->p_context;

    if((p_args->event & SPI_EVENT_TRANSFER_COMPLETE) == SPI_EVENT_TRANSFER_COMPLETE)
    {
        transport->transfer_cb();
    }
}

SpiSlaveTransport::SpiSlaveTransport(void * p_spi_instance, void * p_ioport_instance, uint16_t int_pin):
m_spi_inst((spi_instance_t*)p_spi_instance), m_ioport_inst((ioport_instance_t*)p_ioport_instance), m_int_pin((bsp_io_port_pin_t)int_pin), m_isInited(false)
#if ERPC_THREADS
,
m_txrxSemaphore()
#endif
{
    s_spi_slave_instance = this;
}

SpiSlaveTransport::~SpiSlaveTransport(void)
{
    if (m_isInited)
    {
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
        SpiSlaveTransport_NotifyTransferGpioCompleted();
#endif
        R_SPI_W_Close(m_spi_inst->p_ctrl);
        m_isInited = false;
    }
}

erpc_status_t SpiSlaveTransport::init(void)
{
    fsp_err_t status;
    status = R_SPI_W_Open(m_spi_inst->p_ctrl, m_spi_inst->p_cfg);

    if (FSP_SUCCESS != status)
    {
            return kErpcStatus_InitFailed;
    }

    status = R_SPI_W_CallbackSet(m_spi_inst->p_ctrl,
                                 SPI_SlaveUserCallback,
                                 this,
                                 NULL);

    if (FSP_SUCCESS != status)
    {
        return kErpcStatus_InitFailed;
    }

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    SpiSlaveTransport_NotifyTransferGpioInit();
    SpiSlaveTransport_NotifyTransferGpioCompleted();
#endif

    m_isInited = true;

    if (s_spi_slave_tx_q == NULL)
    {
        s_spi_slave_tx_q = xQueueCreate(16, sizeof(spi_slave_io_req *));
        if (s_spi_slave_tx_q == NULL)
        {
            return kErpcStatus_InitFailed;
        }
    }

    if (s_spi_slave_rx_q == NULL)
    {
        s_spi_slave_rx_q = xQueueCreate(16, sizeof(spi_slave_io_req *));
        if (s_spi_slave_rx_q == NULL)
        {
            return kErpcStatus_InitFailed;
        }
    }

    if (s_spi_slave_io_task == NULL)
    {
        BaseType_t rc = xTaskCreate(SpiSlaveTransport::ioWorker,
                                    "erpc_spi_slv_io",
                                    4096 / sizeof(StackType_t),
                                    NULL,
                                    tskIDLE_PRIORITY + 3,
                                    &s_spi_slave_io_task);
        if (rc != pdPASS)
        {
            return kErpcStatus_InitFailed;
        }
    }

    return kErpcStatus_Success;
}

void SpiSlaveTransport::ioWorker(void *arg)
{
    FSP_PARAMETER_NOT_USED(arg);

    while (true)
    {
        spi_slave_io_req *req = NULL;

        if (xQueueReceive(s_spi_slave_tx_q, &req, 0) != pdTRUE)
        {
            (void)xQueueReceive(s_spi_slave_rx_q, &req, 0);
        }

        if (req == NULL)
        {
            vTaskDelay(1);
            continue;
        }

        if (s_spi_slave_instance == NULL)
        {
            req->result = kErpcStatus_Fail;
            (void)xSemaphoreGive(req->done);
            continue;
        }

        if (req->op == kSpiSlaveIoOp_Receive)
        {
            req->result = s_spi_slave_instance->underlyingReceiveImmediate(req->rx, req->size);
        }
        else
        {
            req->result = s_spi_slave_instance->underlyingSendImmediate(req->tx, req->size);
        }

        (void)xSemaphoreGive(req->done);
    }
}

erpc_status_t SpiSlaveTransport::receive(MessageBuffer *message)
{
#if defined(CONFIG_DATA_PATH) && (CONFIG_DATA_PATH == 1)
    const uint8_t hdr = reserveHeaderSize();

    for (;;)
    {
        erpc_status_t status = FramedTransport::receive(message);
        if (status != kErpcStatus_Success)
        {
            return status;
        }

        if (message->getUsed() < hdr)
        {
            return kErpcStatus_Success;
        }

        uint8_t *body = message->get() + hdr;
        uint16_t body_len = (uint16_t)(message->getUsed() - hdr);

        if (!ra6w1_dp_is_data_path_frame(body, body_len))
        {
            return kErpcStatus_Success;
        }

        uint16_t cap = (uint16_t)(message->getLength() - hdr);
        uint16_t resp_len = 0;

        int rc = ra6w1_dp_enqueue_and_wait(body,
                                           body_len,
                                           body,
                                           cap,
                                           &resp_len,
                                           10000U);
        if (rc != 0)
        {
            continue;
        }

        message->setUsed((uint16_t)(resp_len + hdr));
        status = FramedTransport::send(message);
        if (status != kErpcStatus_Success)
        {
            return status;
        }
    }
#else
    return FramedTransport::receive(message);
#endif
}

erpc_status_t SpiSlaveTransport::underlyingReceive(uint8_t *data, uint32_t size)
{
    spi_slave_io_req *req = (spi_slave_io_req *)pvPortMalloc(sizeof(spi_slave_io_req));
    if (req == NULL)
    {
        return kErpcStatus_MemoryError;
    }

    req->op = kSpiSlaveIoOp_Receive;
    req->tx = NULL;
    req->rx = data;
    req->size = size;
    req->result = kErpcStatus_Fail;
    req->done = xSemaphoreCreateBinary();
    if (req->done == NULL)
    {
        vPortFree(req);
        return kErpcStatus_MemoryError;
    }

    if (s_spi_slave_rx_q == NULL)
    {
        vSemaphoreDelete(req->done);
        vPortFree(req);
        return kErpcStatus_Fail;
    }

    if (xQueueSend(s_spi_slave_rx_q, &req, portMAX_DELAY) != pdTRUE)
    {
        vSemaphoreDelete(req->done);
        vPortFree(req);
        return kErpcStatus_Timeout;
    }

    if (xSemaphoreTake(req->done, portMAX_DELAY) != pdTRUE)
    {
        vSemaphoreDelete(req->done);
        vPortFree(req);
        return kErpcStatus_Fail;
    }

    erpc_status_t result = req->result;
    vSemaphoreDelete(req->done);
    vPortFree(req);

    return result;
}

erpc_status_t SpiSlaveTransport::underlyingReceiveImmediate(uint8_t *data, uint32_t size)
{
    fsp_err_t status;
    uint8_t *rxData = data;
    size_t dataSize = size;
    s_isTransferCompleted = false;

    //vTaskSuspendAll();

    status = R_SPI_W_Read(m_spi_inst->p_ctrl,
                          rxData,
                          dataSize,
                          SPI_BIT_WIDTH_8_BITS);

    if (FSP_SUCCESS == status)
    {
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
        SpiSlaveTransport_NotifyTransferGpioReady();
#endif

/* wait until the receiving is finished */
#if ERPC_THREADS
        m_txrxSemaphore.get();
#else
        while (!s_isTransferCompleted)
        {
        }
#endif

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
        SpiSlaveTransport_NotifyTransferGpioCompleted();
#endif
    }

    //xTaskResumeAll();

    return (status != FSP_SUCCESS) ? kErpcStatus_ReceiveFailed : kErpcStatus_Success;
}

erpc_status_t SpiSlaveTransport::underlyingSend(const uint8_t *data, uint32_t size)
{
    spi_slave_io_req *req = (spi_slave_io_req *)pvPortMalloc(sizeof(spi_slave_io_req));
    if (req == NULL)
    {
        return kErpcStatus_MemoryError;
    }

    req->op = kSpiSlaveIoOp_Send;
    req->tx = data;
    req->rx = NULL;
    req->size = size;
    req->result = kErpcStatus_Fail;
    req->done = xSemaphoreCreateBinary();
    if (req->done == NULL)
    {
        vPortFree(req);
        return kErpcStatus_MemoryError;
    }

    if (s_spi_slave_tx_q == NULL)
    {
        vSemaphoreDelete(req->done);
        vPortFree(req);
        return kErpcStatus_Fail;
    }

    if (xQueueSend(s_spi_slave_tx_q, &req, portMAX_DELAY) != pdTRUE)
    {
        vSemaphoreDelete(req->done);
        vPortFree(req);
        return kErpcStatus_Timeout;
    }

    if (xSemaphoreTake(req->done, portMAX_DELAY) != pdTRUE)
    {
        vSemaphoreDelete(req->done);
        vPortFree(req);
        return kErpcStatus_Fail;
    }

    erpc_status_t result = req->result;
    vSemaphoreDelete(req->done);
    vPortFree(req);

    return result;
}

erpc_status_t SpiSlaveTransport::underlyingSendImmediate(const uint8_t *data, uint32_t size)
{
    fsp_err_t status;
    s_isTransferCompleted = false;
    uint32_t header_size = reserveHeaderSize();

    /* send the header first */
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    uint8_t *txData = (uint8_t *)data;
    size_t dataSize = header_size;
    {
#else
    uint8_t *spiData = new (nothrow) uint8_t[header_size + ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN];
    if (spiData != NULL)
    {
        spiData[0] = ERPC_BOARD_SPI_SLAVE_READY_MARKER1;
        spiData[1] = ERPC_BOARD_SPI_SLAVE_READY_MARKER2;
        (void)memcpy(&spiData[ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN], data, header_size);
        uint8_t *txData = spiData;
        size_t dataSize = header_size + ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN;
#endif

        status = R_SPI_W_Write(m_spi_inst->p_ctrl,
                               txData,
                               dataSize,
                               SPI_BIT_WIDTH_8_BITS);

        if (FSP_SUCCESS == status)
        {
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
        	SpiSlaveTransport_NotifyTransferGpioReady();
#endif

/* wait until the sending is finished */
#if ERPC_THREADS
            m_txrxSemaphore.get();
#else
            while (!s_isTransferCompleted)
            {
            }
#endif

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
            SpiSlaveTransport_NotifyTransferGpioCompleted();
#endif
        }
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    }
#else
        delete[] spiData;
    }
    else
    {
        status = kErpcStatus_SendFailed;
    }
#endif

    /* send the payload now */
    s_isTransferCompleted = false;

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    txData = (uint8_t *)data + header_size;
    dataSize = size - header_size;
    {
#else
    uint8_t *spiData = new (nothrow) uint8_t[size - header_size + ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN];
    if (spiData != NULL)
    {
        spiData[0] = ERPC_BOARD_SPI_SLAVE_READY_MARKER1;
        spiData[1] = ERPC_BOARD_SPI_SLAVE_READY_MARKER2;
        (void)memcpy(&spiData[ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN], data + header_size, size - header_size);
        uint8_t *txData = spiData;
        size_t dataSize = size - header_size + ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN;
#endif

        status = R_SPI_W_Write(m_spi_inst->p_ctrl,
                               txData,
                               dataSize,
                               SPI_BIT_WIDTH_8_BITS);

        if (FSP_SUCCESS == status)
        {
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
        	SpiSlaveTransport_NotifyTransferGpioReady();
#endif

/* wait until the sending is finished */
#if ERPC_THREADS
            m_txrxSemaphore.get();
#else
            while (!s_isTransferCompleted)
            {
            }
#endif

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
            SpiSlaveTransport_NotifyTransferGpioCompleted();
#endif
        }
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    }
#else
        delete[] spiData;
    }
    else
    {
        status = kErpcStatus_SendFailed;
    }
#endif

    return (status != FSP_SUCCESS) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}
