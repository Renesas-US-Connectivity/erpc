/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "erpc_spi_master_zephyr_transport.hpp"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <cstdio>

using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//#ifndef ERPC_BOARD_SPI_INT_GPIO
//#error "Please define the ERPC_BOARD_SPI_INT_GPIO used to notify when the SPI Slave is ready to transmit"
//#endif

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

static volatile bool s_isSlaveReady = false;

//static const struct spi_dt_spec bus = SPI_DT_SPEC_INST_GET(
//	0, SPI_OP_MODE_MASTER | SPI_TRANSFER_MSB | SPI_WORD_SET(8), 0);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/* @brief Initialize the GPIO used to notify the SPI Master */
static inline void SpiMasterTransport_NotifyTransferGpioInit()
{
    //gpio_pin_config_t gpioConfig;

    //gpioConfig.pinDirection = kGPIO_DigitalInput;

    //PORT_SetPinInterruptConfig(ERPC_BOARD_SPI_INT_PORT, ERPC_BOARD_SPI_INT_PIN, kPORT_InterruptFallingEdge);
    //(void)EnableIRQ(ERPC_BOARD_SPI_INT_PIN_IRQ);

    //GPIO_PinInit(ERPC_BOARD_SPI_INT_GPIO, ERPC_BOARD_SPI_INT_PIN, &gpioConfig);
    //if (0U == GPIO_PinRead(ERPC_BOARD_SPI_INT_GPIO, ERPC_BOARD_SPI_INT_PIN))
    //{
    //    s_isSlaveReady = true;
    //}
}

static inline void SpidevMasterTransport_WaitForSlaveReadyGpio()
{
    //while (!s_isSlaveReady)
    //{
    //}
}

SpiMasterTransport::SpiMasterTransport(struct spi_dt_spec *spi, struct gpio_dt_spec *gpio) :
m_spi(spi), m_gpio(gpio)
{
}

SpiMasterTransport::~SpiMasterTransport(void)
{
    //SPI_Deinit(m_spiBaseAddr);
}

erpc_status_t SpiMasterTransport::init(void)
{
    //spi_master_config_t spiConfig;

    //SPI_MasterGetDefaultConfig(&spiConfig);
    //spiConfig.baudRate_Bps = m_baudRate;
    //SPI_MasterInit(m_spiBaseAddr, &spiConfig, m_srcClock_Hz);

    SpiMasterTransport_NotifyTransferGpioInit();

    return kErpcStatus_Success;
}

erpc_status_t SpiMasterTransport::underlyingReceive(uint8_t *data, uint32_t size)
{
    //status_t status;
    //spi_transfer_t masterXfer;
    uint8_t buffer_rx[5] = {0};

	int ret = 0;

    const struct spi_buf buf[] = {{
		.buf = buffer_rx,
		.len = ARRAY_SIZE(buffer_rx),
	}};

   	struct spi_buf_set rx = {
		.buffers = buf,
		.count = ARRAY_SIZE(buf)
	};

    //masterXfer.txData = NULL;
    //masterXfer.rxData = data;
    //masterXfer.dataSize = size;

    SpidevMasterTransport_WaitForSlaveReadyGpio();

    //status = SPI_MasterTransferBlocking(m_spiBaseAddr, &masterXfer);
    //ret = spi_read_dt(m_spi, &rx);
    s_isSlaveReady = false;

    //return (status != kStatus_Success) ? kErpcStatus_ReceiveFailed : kErpcStatus_Success;
    return (ret < 0) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}

erpc_status_t SpiMasterTransport::underlyingSend(const uint8_t *data, uint32_t size)
{
    int ret;
    uint32_t header_size = reserveHeaderSize();
    struct spi_buf buf[1];
    struct spi_buf_set tx;

    /* send the header first */
    buf[0].buf = (void *)data;
    buf[0].len = header_size;

    tx.count = 1;
    tx.buffers = (const spi_buf*)&buf;

    SpidevMasterTransport_WaitForSlaveReadyGpio();

	ret = spi_write_dt(m_spi, &tx);
    s_isSlaveReady = false;

    /* send the payload now */
    buf[0].buf = (void *)(data + header_size);
    buf[0].len = size - header_size;

    SpidevMasterTransport_WaitForSlaveReadyGpio();

	ret = spi_write_dt(m_spi, &tx);
    s_isSlaveReady = false;

    return (ret < 0) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}

extern "C" {
void ERPC_BOARD_SPI_INT_PIN_IRQ_HANDLER(void)
{
    /* Clear external interrupt flag. */
    //GPIO_PortClearInterruptFlags(ERPC_BOARD_SPI_INT_GPIO, 1U << ERPC_BOARD_SPI_INT_PIN);
    s_isSlaveReady = true;
}
}
