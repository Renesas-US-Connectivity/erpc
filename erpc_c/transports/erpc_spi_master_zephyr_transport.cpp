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

// TODO - need to figure out if we can automatically set this definition based
//        on the presence (or otherwise) of the int-gpios property in the device
//        tree node. Alternatively could this be a Kconfig option?
#define ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
#define ERPC_OPERATION_TOUT_MS (30ULL * 1000ULL * 1000ULL) // 30 Billion wraps uint32_t
#define ERPC_OPERATION_TOUT_US (30ULL * 1000ULL * 1000ULL) // Wait, actually I will redefine it to 30 million
#undef ERPC_OPERATION_TOUT_MS
#define ERPC_OPERATION_TOUT_MS (30000000UL) // 30 seconds in microseconds
////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
#if ERPC_THREADS_IS(NONE)
static volatile bool s_isSlaveReady = false;
#endif
static struct gpio_callback n_int_cb_data;
#endif

static SpiMasterTransport *s_spi_master_instance = NULL;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
extern "C" {
static void n_int_cb(const struct device *dev, struct gpio_callback *cb, uint32_t pins);
}

SpiMasterTransport::SpiMasterTransport(struct spi_dt_spec *dev, struct gpio_dt_spec *int_pin) :
m_dev(dev), m_int_pin(int_pin)
#if ERPC_THREADS
,
m_slaveReadySemaphore()
#endif
{
    s_spi_master_instance = this;
}

SpiMasterTransport::~SpiMasterTransport(void)
{
}

erpc_status_t SpiMasterTransport::init(void)
{
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    int ret;

    if (!gpio_is_ready_dt(m_int_pin)) {
        return kErpcStatus_Fail;
    }

    ret = gpio_pin_configure_dt(m_int_pin, GPIO_INPUT);
	if (ret != 0) {
        return kErpcStatus_Fail;
    }

    ret = gpio_pin_interrupt_configure_dt(m_int_pin, GPIO_INT_EDGE_FALLING);
    if (ret < 0) {
        return kErpcStatus_Fail;
    }

    gpio_init_callback(&n_int_cb_data, n_int_cb, BIT(m_int_pin->pin));

    ret = gpio_add_callback(m_int_pin->port, &n_int_cb_data);
    if (ret < 0) {
        return kErpcStatus_Fail;
    }

    if (gpio_pin_get_dt(m_int_pin) != 0) {
#if ERPC_THREADS_IS(NONE)
        s_isSlaveReady = true;
#else
        m_slaveReadySemaphore.put();
#endif
    }

#endif

    return kErpcStatus_Success;
}

void SpiMasterTransport::ready_cb(void)
{
#if ERPC_THREADS
    m_slaveReadySemaphore.put();
#endif
}

erpc_status_t SpiMasterTransport::underlyingReceive(uint8_t *data, uint32_t size)
{
    int ret = 0;
    struct spi_buf buf[1];
    struct spi_buf_set rx;

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
#if ERPC_THREADS_IS(NONE)
    while (!s_isSlaveReady)
    {
    }
    s_isSlaveReady = false;
#else
#ifdef ERPC_OPERATION_TOUT_MS
    ret = m_slaveReadySemaphore.get(ERPC_OPERATION_TOUT_MS);
    if (!ret) {
        return kErpcStatus_Timeout;
    }
#else
    ret = m_slaveReadySemaphore.get();
#endif

#endif
#endif

    buf[0].buf = (void *)data;
    buf[0].len = size;

    rx.count = 1;
    rx.buffers = (const spi_buf*)&buf;

    ret = spi_read_dt(m_dev, &rx);

    return (ret < 0) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}

erpc_status_t SpiMasterTransport::underlyingSend(const uint8_t *data, uint32_t size)
{
    int ret;
    struct spi_buf buf[1];
    struct spi_buf_set tx;
    uint32_t header_size = reserveHeaderSize();

    /* Send the header first */
    buf[0].buf = (void *)data;
    buf[0].len = header_size;

    tx.count = 1;
    tx.buffers = (const spi_buf*)&buf;

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
#if ERPC_THREADS_IS(NONE)
    while (!s_isSlaveReady)
    {
    }
    s_isSlaveReady = false;
#else

#ifdef ERPC_OPERATION_TOUT_MS
    ret = m_slaveReadySemaphore.get(ERPC_OPERATION_TOUT_MS);
    if (!ret) {
        return kErpcStatus_Timeout;
    }
#else
    ret = m_slaveReadySemaphore.get();
#endif

#endif
#endif

    ret = spi_write_dt(m_dev, &tx);

    /* Send the payload now */
    buf[0].buf = (void *)(data + header_size);
    buf[0].len = size - header_size;

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
#if ERPC_THREADS_IS(NONE)
    while (!s_isSlaveReady)
    {
    }
    s_isSlaveReady = false;
#else
    m_slaveReadySemaphore.get();
#endif
#endif

    ret = spi_write_dt(m_dev, &tx);

    return (ret < 0) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
extern "C" {
static void n_int_cb(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
#if ERPC_THREADS_IS(NONE)
    s_isSlaveReady = true;
#else
    s_spi_master_instance->ready_cb();
#endif
}
}
#endif
