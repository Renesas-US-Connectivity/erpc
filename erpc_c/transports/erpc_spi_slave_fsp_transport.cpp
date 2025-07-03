/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "erpc_spi_slave_fsp_transport.hpp"

#include <cstdio>
#include <new>

extern "C" {
#include "r_gpio_w.h"
#include "r_spi_w.h"
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

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
/* @brief Initialize the GPIO used to notify the SPI Master */
static inline void SpiSlaveTransport_NotifyTransferGpioInit(void)
{
    // TODO already opened by call to IOPORT_CFG_OPEN()
    //fsp_err_t R_GPIO_W_Open(ioport_ctrl_t * const p_ctrl, const ioport_cfg_t * p_cfg);

}

/* @brief Notify the SPI Master that the Slave is ready for a new transfer */
//static inline void SpiSlaveTransport_NotifyTransferGpioReady(void)
void SpiSlaveTransport::SpiSlaveTransport_NotifyTransferGpioReady(void)

{
    R_GPIO_W_PinWrite(m_io_ctrl, m_dready_pin, BSP_IO_LEVEL_HIGH);
    //R_BSP_PinWrite(dready_pin, BSP_IO_LEVEL_HIGH);
}

/* @brief Notify the SPI Master that the Slave has finished the transfer */
//static inline void SpiSlaveTransport_NotifyTransferGpioCompleted(void)
void SpiSlaveTransport::SpiSlaveTransport_NotifyTransferGpioCompleted(void)
{
    R_GPIO_W_PinWrite(m_io_ctrl, m_dready_pin, BSP_IO_LEVEL_LOW);
    //R_BSP_PinWrite(dready_pin, BSP_IO_LEVEL_LOW);
}
#endif

void SpiSlaveTransport::transfer_cb(void)
{
#if ERPC_THREADS
    m_txrxSemaphore.putFromISR();
#else
    s_isTransferCompleted = true;
#endif
}

//static void SPI_SlaveUserCallback(SPI_Type *base, spi_slave_handle_t *handle, status_t status, void *userData)
static void SPI_SlaveUserCallback(spi_callback_args_t * p_args)
{
    if((p_args->event & SPI_EVENT_TRANSFER_COMPLETE) == SPI_EVENT_TRANSFER_COMPLETE) {

        SpiSlaveTransport *transport = s_spi_slave_instance;

        transport->transfer_cb();
    }
}

//SpiSlaveTransport::SpiSlaveTransport(SPI_Type *spiBaseAddr, uint32_t baudRate, uint32_t srcClock_Hz) :
//m_spiBaseAddr(spiBaseAddr), m_baudRate(baudRate), m_srcClock_Hz(srcClock_Hz), m_isInited(false)
SpiSlaveTransport::SpiSlaveTransport(void * p_api_ctrl, void * p_cfg, void * p_io_ctrl, uint16_t dready_pin, uint32_t baudRate, uint32_t srcClock_Hz):
m_api_ctrl((spi_ctrl_t*)p_api_ctrl), m_cfg((spi_cfg_t*)p_cfg), m_io_ctrl((ioport_ctrl_t*)p_io_ctrl), m_dready_pin((bsp_io_port_pin_t)dready_pin), m_baudRate(baudRate), m_srcClock_Hz(srcClock_Hz), m_isInited(false)
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
        R_SPI_W_Close(m_api_ctrl);  // TODO pass in m_spiBaseAddr
        m_isInited = false;
    }
}

erpc_status_t SpiSlaveTransport::init(void)
{
    fsp_err_t status;
    status = R_SPI_W_Open(m_api_ctrl, m_cfg); // TODO pass these in to class

    if (FSP_SUCCESS != status)
    {
            return kErpcStatus_InitFailed;
    }
    status = R_SPI_W_CallbackSet(m_api_ctrl, // TODO pass in to class
                                  SPI_SlaveUserCallback,
                                  this,
                                  NULL);

    if (FSP_SUCCESS != status)
    {
        return kErpcStatus_InitFailed;
    }
    //(void)SPI_SlaveInit(m_spiBaseAddr, &spiConfig);
    //(void)SPI_SlaveTransferCreateHandle(m_spiBaseAddr, &s_handle, SPI_SlaveUserCallback, NULL);

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    SpiSlaveTransport_NotifyTransferGpioInit();
#endif

    m_isInited = true;
    return kErpcStatus_Success;
}

erpc_status_t SpiSlaveTransport::underlyingReceive(uint8_t *data, uint32_t size)
{
    fsp_err_t status;
    //uint8_t *txData = NULL;
    uint8_t *rxData = data;
    size_t dataSize = size;
    s_isTransferCompleted = false;

    status = R_SPI_W_Read(m_api_ctrl,  // TODO pass is
                          rxData,
                          dataSize,
                          SPI_BIT_WIDTH_8_BITS); // TODO confirm bus width to use

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

    return (status != FSP_SUCCESS) ? kErpcStatus_ReceiveFailed : kErpcStatus_Success;
}

erpc_status_t SpiSlaveTransport::underlyingSend(const uint8_t *data, uint32_t size)
{
    fsp_err_t status;
    s_isTransferCompleted = false;
    uint32_t header_size = reserveHeaderSize();

    /* send the header first */
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    uint8_t *txData = (uint8_t *)data;
    //uint8_t *rxData = NULL;
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
        //rxData = NULL;
        size_t dataSize = header_size + ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN;
#endif

        status = R_SPI_W_Write(m_api_ctrl,  //TODO pass in
                               txData,
                               dataSize,
                               SPI_BIT_WIDTH_8_BITS); // TODO confirm bus width to use

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
    //rxData = NULL;
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
        //rxData = NULL;
        size_t dataSize = size - header_size + ERPC_BOARD_SPI_SLAVE_READY_MARKER_LEN;
#endif

        status = R_SPI_W_Write(m_api_ctrl,  //TODO pass in
                               txData,
                               dataSize,
                               SPI_BIT_WIDTH_8_BITS); // TODO confirm bus width to use


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
