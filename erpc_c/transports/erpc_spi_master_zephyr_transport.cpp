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

static struct gpio_callback slave_rdy_cb_data;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
extern "C" {
static void slave_rdy_gpio_cb(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
}

static inline void SpidevMasterTransport_WaitForSlaveReadyGpio()
{
    while (!s_isSlaveReady)
    {
    }
}

SpiMasterTransport::SpiMasterTransport(struct spi_dt_spec *spi, struct gpio_dt_spec *rdy, struct gpio_dt_spec *intr) :
m_spi(spi), m_rdy(rdy), m_intr(intr) 
{
}

SpiMasterTransport::~SpiMasterTransport(void)
{
    //SPI_Deinit(m_spiBaseAddr);
}

erpc_status_t SpiMasterTransport::init(void)
{
    //int ret;

    //if (!gpio_is_ready_dt(m_gpio)) {
    //    // TODO - print error message?
    //    return kErpcStatus_Fail;
    //}

	//ret = gpio_pin_configure_dt(m_gpio, GPIO_INPUT);
	//if (ret != 0) {
//		// TODO - print error message?
 //       return kErpcStatus_Fail;
//	}

//	ret = gpio_pin_interrupt_configure_dt(m_gpio, GPIO_INT_EDGE_TO_INACTIVE);
//	if (ret != 0) {
		// TODO - print error message?
  //      return kErpcStatus_Fail;
	//}

	//gpio_init_callback(&slave_rdy_cb_data, slave_rdy_gpio_cb, BIT(m_gpio->pin));
    //gpio_add_callback_dt(m_gpio, &slave_rdy_cb_data);

    //if (gpio_pin_get_dt(m_gpio) != 0) {
        //s_isSlaveReady = true;
    //}

    return kErpcStatus_Success;
}

erpc_status_t SpiMasterTransport::underlyingReceive(uint8_t *data, uint32_t size)
{
	int ret = 0;

    struct spi_buf buf[1];
    struct spi_buf_set rx;

    buf[0].buf = (void *)data;
    buf[0].len = size;

    rx.count = 1;
    rx.buffers = (const spi_buf*)&buf;

    // TODO - Fix me! Make this a wait for a semaphore that is given in GPIO ISR (if threading enabled)
    while (gpio_pin_get_dt(m_intr) != 0)
    {
        k_msleep(10);
    }
    //SpidevMasterTransport_WaitForSlaveReadyGpio();

    ret = spi_read_dt(m_spi, &rx);
    s_isSlaveReady = false;

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

    while (gpio_pin_get_dt(m_rdy) != 0)
    {
        k_msleep(10);
    }

	ret = spi_write_dt(m_spi, &tx);
    s_isSlaveReady = false;

    /* send the payload now */
    buf[0].buf = (void *)(data + header_size);
    buf[0].len = size - header_size;

    //SpidevMasterTransport_WaitForSlaveReadyGpio();
    while (gpio_pin_get_dt(m_rdy) != 0)
    {
        k_msleep(10);
    }

	ret = spi_write_dt(m_spi, &tx);
    s_isSlaveReady = false;

    return (ret < 0) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}

//extern "C" {
//static void slave_rdy_gpio_cb(const struct device *dev, struct gpio_callback *cb,
		    //uint32_t pins)
//{
    //s_isSlaveReady = true;
//}
//}
