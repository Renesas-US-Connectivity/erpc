/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "erpc_spi_master_zephyr_transport.hpp"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/logging/log.h>
#include <string.h>

#include <cstdio>

using namespace erpc;

LOG_MODULE_REGISTER(erpc_spi_master_transport, CONFIG_WIFI_LOG_LEVEL);

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

// TODO - need to figure out if we can automatically set this definition based
//        on the presence (or otherwise) of the int-gpios property in the device
//        tree node. Alternatively could this be a Kconfig option?
#define ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
#if ERPC_THREADS_IS(NONE)
static volatile bool s_isSlaveReady = false;
#endif
#endif

static SpiMasterTransport *s_spi_master_instance = NULL;

enum spi_master_io_op
{
    kSpiMasterIoOp_Receive = 0,
    kSpiMasterIoOp_Send,
};

struct spi_master_io_req
{
    spi_master_io_op op;
    const uint8_t *tx;
    uint8_t *rx;
    uint32_t size;
    uint32_t trace_id;
    erpc_status_t result;
    struct k_sem done;
};

K_MSGQ_DEFINE(s_spi_master_tx_q, sizeof(spi_master_io_req *), 16, 4);
K_MSGQ_DEFINE(s_spi_master_rx_q, sizeof(spi_master_io_req *), 16, 4);
K_THREAD_STACK_DEFINE(s_spi_master_io_stack, 4096);
static struct k_thread s_spi_master_io_thread;
static k_tid_t s_spi_master_io_tid;
static K_MUTEX_DEFINE(s_spi_master_io_start_lock);
static atomic_t s_spi_master_trace_seq;

void SpiMasterTransport::ioWorker(void *arg1, void *arg2, void *arg3)
{
    ARG_UNUSED(arg1);
    ARG_UNUSED(arg2);
    ARG_UNUSED(arg3);

    while (true)
    {
        spi_master_io_req *req = NULL;

        if (k_msgq_get(&s_spi_master_tx_q, &req, K_NO_WAIT) != 0)
        {
            (void)k_msgq_get(&s_spi_master_rx_q, &req, K_NO_WAIT);
        }

        if (req == NULL)
        {
            k_sleep(K_MSEC(1));
            continue;
        }

        LOG_DBG("SPI worker start: trace=%u op=%d size=%u thread=%s",
                req->trace_id, req->op, req->size,
                k_thread_name_get(k_current_get()));

        if (s_spi_master_instance == NULL)
        {
            req->result = kErpcStatus_Fail;
            k_sem_give(&req->done);
            continue;
        }

        if (req->op == kSpiMasterIoOp_Receive)
        {
            req->result = s_spi_master_instance->underlyingReceiveImmediate(req->rx, req->size, req->trace_id);
        }
        else
        {
            req->result = s_spi_master_instance->underlyingSendImmediate(req->tx, req->size, req->trace_id);
        }

        LOG_DBG("SPI worker done: trace=%u op=%d status=%d",
                req->trace_id, req->op, req->result);

        k_sem_give(&req->done);
    }
}

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
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

erpc_status_t SpiMasterTransport::ensureIoWorkerStarted(void)
{
    if (s_spi_master_io_tid != NULL)
    {
        return kErpcStatus_Success;
    }

    k_mutex_lock(&s_spi_master_io_start_lock, K_FOREVER);

    if (s_spi_master_io_tid == NULL)
    {
        s_spi_master_io_tid = k_thread_create(&s_spi_master_io_thread,
                                              s_spi_master_io_stack,
                                              K_THREAD_STACK_SIZEOF(s_spi_master_io_stack),
                                              SpiMasterTransport::ioWorker,
                                              NULL,
                                              NULL,
                                              NULL,
                                              K_PRIO_PREEMPT(12),
                                              0,
                                              K_NO_WAIT);
        if (s_spi_master_io_tid == NULL)
        {
            k_mutex_unlock(&s_spi_master_io_start_lock);
            return kErpcStatus_InitFailed;
        }

        k_thread_name_set(s_spi_master_io_tid, "erpc_spi_mst_io");
    }

    k_mutex_unlock(&s_spi_master_io_start_lock);

    return kErpcStatus_Success;
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
    erpc_status_t initStatus = ensureIoWorkerStarted();
    if (initStatus != kErpcStatus_Success)
    {
        return initStatus;
    }

    spi_master_io_req *req = static_cast<spi_master_io_req *>(k_malloc(sizeof(spi_master_io_req)));
    if (req == NULL)
    {
        return kErpcStatus_MemoryError;
    }

    req->op = kSpiMasterIoOp_Receive;
    req->tx = NULL;
    req->rx = data;
    req->size = size;
        req->trace_id = (uint32_t)atomic_inc(&s_spi_master_trace_seq);
    req->result = kErpcStatus_Fail;
    k_sem_init(&req->done, 0, 1);

        LOG_DBG("SPI recv queue: trace=%u size=%u caller=%s",
            req->trace_id, req->size, k_thread_name_get(k_current_get()));

    if (k_msgq_put(&s_spi_master_rx_q, &req, K_FOREVER) != 0)
    {
        k_free(req);
        return kErpcStatus_Fail;
    }

    if (k_sem_take(&req->done, K_FOREVER) != 0)
    {
        k_free(req);
        return kErpcStatus_Fail;
    }

    erpc_status_t result = req->result;
    k_free(req);

    return result;
}

erpc_status_t SpiMasterTransport::waitForSlaveReady(void)
{
#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    /*
     * The erpc::Semaphore Zephyr backend currently scales timeout values down
     * far too aggressively for this use case, so use direct GPIO polling for a
     * real wall-clock wait.
     */
    const int64_t start_ms = k_uptime_get();
    const int64_t timeout_ms = 15000;

    while (true)
    {
        int srdy = gpio_pin_get_dt(m_int_pin);
        if (srdy < 0)
        {
            LOG_ERR("SRDY read failed: rc=%d", srdy);
            return kErpcStatus_Fail;
        }

        if (srdy > 0)
        {
            LOG_DBG("SRDY high observed");
#if ERPC_THREADS_IS(NONE)
            s_isSlaveReady = false;
#endif
            return kErpcStatus_Success;
        }

        if ((k_uptime_get() - start_ms) >= timeout_ms)
        {
            LOG_ERR("SRDY wait timeout: elapsed_ms=%lld srdy=%d",
                    (long long)(k_uptime_get() - start_ms), srdy);
            return kErpcStatus_Timeout;
        }

        k_busy_wait(1000U);
    }
#endif

    return kErpcStatus_Success;
}

erpc_status_t SpiMasterTransport::underlyingReceiveImmediate(uint8_t *data, uint32_t size, uint32_t traceId)
{
    int ret = 0;
    struct spi_buf buf[1];
    struct spi_buf_set rx;

    LOG_DBG("SPI recv phase wait: trace=%u size=%u", traceId, size);
    erpc_status_t ready = waitForSlaveReady();
    if (ready != kErpcStatus_Success)
    {
        LOG_ERR("SPI recv SRDY failed: trace=%u status=%d", traceId, ready);
        return ready;
    }

    buf[0].buf = (void *)data;
    buf[0].len = size;

    rx.count = 1;
    rx.buffers = (const spi_buf*)&buf;

    LOG_DBG("SPI read begin: trace=%u size=%u", traceId, size);
    ret = spi_read_dt(m_dev, &rx);
    LOG_DBG("SPI read done: trace=%u rc=%d", traceId, ret);

    return (ret < 0) ? kErpcStatus_ReceiveFailed : kErpcStatus_Success;
}

erpc_status_t SpiMasterTransport::underlyingSend(const uint8_t *data, uint32_t size)
{
    erpc_status_t initStatus = ensureIoWorkerStarted();
    if (initStatus != kErpcStatus_Success)
    {
        return initStatus;
    }

    spi_master_io_req *req = static_cast<spi_master_io_req *>(k_malloc(sizeof(spi_master_io_req)));
    if (req == NULL)
    {
        return kErpcStatus_MemoryError;
    }

    req->op = kSpiMasterIoOp_Send;
    req->tx = data;
    req->rx = NULL;
    req->size = size;
        req->trace_id = (uint32_t)atomic_inc(&s_spi_master_trace_seq);
    req->result = kErpcStatus_Fail;
    k_sem_init(&req->done, 0, 1);

        LOG_DBG("SPI send queue: trace=%u size=%u caller=%s",
            req->trace_id, req->size, k_thread_name_get(k_current_get()));

    if (k_msgq_put(&s_spi_master_tx_q, &req, K_FOREVER) != 0)
    {
        k_free(req);
        return kErpcStatus_Fail;
    }

    if (k_sem_take(&req->done, K_FOREVER) != 0)
    {
        k_free(req);
        return kErpcStatus_Fail;
    }

    erpc_status_t result = req->result;
    k_free(req);

    return result;
}

erpc_status_t SpiMasterTransport::underlyingSendImmediate(const uint8_t *data, uint32_t size, uint32_t traceId)
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

    LOG_DBG("SPI send header wait: trace=%u hdr=%u total=%u",
            traceId, header_size, size);
    erpc_status_t ready = waitForSlaveReady();
    if (ready != kErpcStatus_Success)
    {
        LOG_ERR("SPI send header SRDY failed: trace=%u status=%d", traceId, ready);
        return ready;
    }

    LOG_DBG("SPI write header begin: trace=%u len=%u", traceId, header_size);
    ret = spi_write_dt(m_dev, &tx);
    if (ret < 0)
    {
        LOG_ERR("SPI write header failed: trace=%u rc=%d", traceId, ret);
        return kErpcStatus_SendFailed;
    }
    LOG_DBG("SPI write header done: trace=%u rc=%d", traceId, ret);

    /* Send the payload now */
    buf[0].buf = (void *)(data + header_size);
    buf[0].len = size - header_size;

    LOG_DBG("SPI send payload wait: trace=%u len=%u", traceId, size - header_size);
    ready = waitForSlaveReady();
    if (ready != kErpcStatus_Success)
    {
        LOG_ERR("SPI send payload SRDY failed: trace=%u status=%d", traceId, ready);
        return ready;
    }

    LOG_DBG("SPI write payload begin: trace=%u len=%u", traceId, size - header_size);
    ret = spi_write_dt(m_dev, &tx);
    LOG_DBG("SPI write payload done: trace=%u rc=%d", traceId, ret);

    return (ret < 0) ? kErpcStatus_SendFailed : kErpcStatus_Success;
}

extern "C" int erpc_transport_zephyr_spi_master_dp_send(struct ErpcTransport *transport,
                          const uint8_t *frame,
                          uint16_t len)
{
    if (transport == NULL || frame == NULL || len == 0U)
    {
        return -EINVAL;
    }

    Transport *t = reinterpret_cast<Transport *>(transport);
    const uint16_t hdr = t->reserveHeaderSize();
    const uint32_t total = (uint32_t)hdr + (uint32_t)len;

    uint8_t *buf = static_cast<uint8_t *>(k_malloc(total));
    if (buf == NULL)
    {
        return -ENOMEM;
    }

    (void)memcpy(&buf[hdr], frame, len);

    MessageBuffer mb(buf, (uint16_t)total);
    mb.setUsed((uint16_t)total);

    erpc_status_t st = t->send(&mb);

    k_free(buf);

    return (st == kErpcStatus_Success) ? 0 : -EIO;
}

extern "C" int erpc_transport_zephyr_spi_master_dp_recv(struct ErpcTransport *transport,
                          uint8_t *out,
                          uint16_t out_cap,
                          uint16_t *out_len)
{
    if (transport == NULL || out == NULL || out_len == NULL)
    {
        return -EINVAL;
    }

    Transport *t = reinterpret_cast<Transport *>(transport);
    const uint16_t hdr = t->reserveHeaderSize();
    const uint32_t total = (uint32_t)hdr + (uint32_t)out_cap;

    uint8_t *buf = static_cast<uint8_t *>(k_malloc(total));
    if (buf == NULL)
    {
        return -ENOMEM;
    }

    MessageBuffer mb(buf, (uint16_t)total);

    erpc_status_t st = t->receive(&mb);
    if (st != kErpcStatus_Success)
    {
        k_free(buf);
        return -EIO;
    }

    uint16_t used = mb.getUsed();
    uint16_t body = (used > hdr) ? (uint16_t)(used - hdr) : 0U;
    if (body > out_cap)
    {
        body = out_cap;
    }

    (void)memcpy(out, &buf[hdr], body);
    *out_len = body;

    k_free(buf);

    return 0;
}
