/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "erpc_spi_master_zephyr_transport.hpp"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/util.h>
#include <errno.h>
#include <cstring>

extern "C" {

typedef struct transport_queue_item_t
{
    uint16_t len;
    uint8_t data[];
} transport_queue_item_t;

typedef struct erpc_comms_t
{
    uint32_t rx_queue_in_erpc;
    uint32_t rx_queue_out_erpc;
    uint32_t tx_queue_comms;
    uint32_t rx_queue_comms;
    uint32_t total_rx_bytes;
    uint32_t total_tx_bytes;
    uint32_t nof_malloc;
    uint32_t nof_free;
    uint32_t nof_response_data;
    uint32_t nof_comm_error;
    uint32_t q_send_failed;
    uint32_t erpc_malloc_failed;
    uint32_t size_malloc_failed;
    uint32_t wkup_irq_hit;
    uint32_t wkup_irq_miss;
    uint8_t erpc_rx_state;
} erpc_comms_t;

typedef struct k_msgq *QueueHandle_t;

#define pdTRUE 1
#define pdFALSE 0
#define portMAX_DELAY K_FOREVER
#define pdMS_TO_TICKS(ms) K_MSEC(ms)

static char s_tx_queue_buf[16 * sizeof(void *)];
static char s_rx_queue_buf[16 * sizeof(void *)];
static struct k_msgq s_tx_queue;
static struct k_msgq s_rx_queue;
static struct k_sem s_tx_kick_sem;
static struct k_sem s_drdy_sem;
static struct gpio_callback s_drdy_cb_data;
static struct k_thread s_transport_thread;
K_THREAD_STACK_DEFINE(s_transport_stack, 4096);

static constexpr uint16_t kSpiCmdTxReq = 0x10U;
static constexpr uint16_t kSpiRespAckOk = 0x00AAU;
static constexpr uint32_t kDrdyTimeoutMs = 100U;
static constexpr uint32_t kQueueTimeoutMs = 100U;
static constexpr uint32_t kSpiTimeoutMs = 200U;
static constexpr uint32_t kStuckRetryThreshold = 3U;

typedef struct spi_xch_pkt_t
{
    uint16_t header;
    uint16_t tx_len;
} spi_xch_pkt_t;

QueueHandle_t g_tx_queue = &s_tx_queue;
QueueHandle_t g_rx_queue = &s_rx_queue;
erpc_comms_t erpc_comms_struct;

static inline int xQueueSend(QueueHandle_t q, transport_queue_item_t **item, k_timeout_t timeout)
{
    return (k_msgq_put(q, item, timeout) == 0) ? pdTRUE : pdFALSE;
}

static inline int xQueueReceive(QueueHandle_t q, transport_queue_item_t **item, k_timeout_t timeout)
{
    return (k_msgq_get(q, item, timeout) == 0) ? pdTRUE : pdFALSE;
}

static inline void *pvPortMalloc(size_t size)
{
    return k_malloc(size);
}

static inline void vPortFree(void *ptr)
{
    k_free(ptr);
}

} // extern "C"

using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
#if (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_SPI)
#define ERPC_BOARD_ABS_SLAVE_READY_USE_GPIO
#endif

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

#ifdef ERPC_BOARD_ABS_SLAVE_READY_USE_GPIO
volatile bool s_isSlaveReady = false;
#endif

static AbsMasterTransport *s_abs_master_instance = NULL;
static struct spi_dt_spec *s_spi_spec;
static struct gpio_dt_spec *s_nint_spec;
static uint32_t s_consecutive_failures;
static bool s_transport_thread_started;

static void transport_mark_failure(void)
{
    erpc_comms_struct.nof_comm_error++;
    s_consecutive_failures++;
}

static void transport_mark_progress(void)
{
    s_consecutive_failures = 0;
}

static int spi_transfer_wait(struct spi_dt_spec *spec, const uint8_t *tx, uint8_t *rx, size_t len)
{
    if (len == 0U) {
        return 0;
    }

    struct spi_buf tx_buf = {
        .buf = (void *)tx,
        .len = len,
    };
    struct spi_buf rx_buf = {
        .buf = rx,
        .len = len,
    };

    const struct spi_buf_set tx_set = {
        .buffers = &tx_buf,
        .count = 1,
    };
    const struct spi_buf_set rx_set = {
        .buffers = &rx_buf,
        .count = 1,
    };

#if defined(CONFIG_SPI_ASYNC) && defined(CONFIG_POLL)
    struct k_poll_signal sig;
    struct k_poll_event event;
    int signaled = 0;
    int result = 0;

    k_poll_signal_init(&sig);
    k_poll_event_init(&event, K_POLL_TYPE_SIGNAL, K_POLL_MODE_NOTIFY_ONLY, &sig);

    int ret = spi_transceive_signal(spec->bus, &spec->config,
                                    (tx != NULL) ? &tx_set : NULL,
                                    (rx != NULL) ? &rx_set : NULL,
                                    &sig);
    if (ret != 0) {
        return ret;
    }

    ret = k_poll(&event, 1, K_MSEC(kSpiTimeoutMs));
    if (ret != 0) {
        return -ETIMEDOUT;
    }

    (void)k_poll_signal_check(&sig, &signaled, &result);
    if (!signaled) {
        return -ETIMEDOUT;
    }

    return result;
#else
    if ((tx != NULL) && (rx != NULL)) {
        return spi_transceive_dt(spec, &tx_set, &rx_set);
    }
    if (tx != NULL) {
        return spi_write_dt(spec, &tx_set);
    }
    return spi_read_dt(spec, &rx_set);
#endif
}

static bool wait_for_drdy_irq_or_level(struct gpio_dt_spec *ioport, k_timeout_t timeout)
{
    if (gpio_pin_get_dt(ioport) == 0) {
        return true;
    }

    if (k_sem_take(&s_drdy_sem, timeout) != 0) {
        erpc_comms_struct.wkup_irq_miss++;
        return false;
    }

    erpc_comms_struct.wkup_irq_hit++;
    return gpio_pin_get_dt(ioport) == 0;
}

static void transport_recover(struct spi_dt_spec *spec, struct gpio_dt_spec *ioport)
{
    ARG_UNUSED(spec);
    k_msgq_purge(&s_rx_queue);
    while (k_sem_take(&s_drdy_sem, K_NO_WAIT) == 0) {
    }
    (void)gpio_pin_interrupt_configure_dt(ioport, GPIO_INT_DISABLE);
    (void)gpio_pin_interrupt_configure_dt(ioport, GPIO_INT_EDGE_TO_ACTIVE);
    erpc_comms_struct.erpc_rx_state = 0;
    s_consecutive_failures = 0;
}

static int transport_exchange_once(void)
{
    transport_queue_item_t *tx_pkt = NULL;
    transport_queue_item_t *rx_pkt = NULL;
    spi_xch_pkt_t tx_hdr = { .header = kSpiCmdTxReq, .tx_len = 0 };
    spi_xch_pkt_t rx_hdr = { 0 };
    int ret;

    if (xQueueReceive(g_tx_queue, &tx_pkt, K_NO_WAIT) == pdTRUE) {
        tx_hdr.tx_len = tx_pkt->len;
        erpc_comms_struct.tx_queue_comms++;
    }

    if (!wait_for_drdy_irq_or_level(s_nint_spec, K_MSEC(kDrdyTimeoutMs))) {
        transport_mark_failure();
        if (tx_pkt != NULL) {
            (void)xQueueSend(g_tx_queue, &tx_pkt, K_NO_WAIT);
        }
        return -ETIMEDOUT;
    }

    ret = spi_transfer_wait(s_spi_spec,
                            reinterpret_cast<const uint8_t *>(&tx_hdr),
                            reinterpret_cast<uint8_t *>(&rx_hdr),
                            sizeof(tx_hdr));
    if (ret != 0) {
        transport_mark_failure();
        if (tx_pkt != NULL) {
            (void)xQueueSend(g_tx_queue, &tx_pkt, K_NO_WAIT);
        }
        return ret;
    }

    if (rx_hdr.header != kSpiRespAckOk) {
        transport_mark_failure();
        if (tx_pkt != NULL) {
            (void)xQueueSend(g_tx_queue, &tx_pkt, K_NO_WAIT);
        }
        return -EIO;
    }

    const uint16_t tx_len = tx_hdr.tx_len;
    const uint16_t rx_len = rx_hdr.tx_len;
    const uint16_t min_len = (tx_len < rx_len) ? tx_len : rx_len;

    if (rx_len > 0U) {
        rx_pkt = reinterpret_cast<transport_queue_item_t *>(
            pvPortMalloc(sizeof(transport_queue_item_t) + rx_len));
        if (rx_pkt == NULL) {
            if (tx_pkt != NULL) {
                vPortFree(tx_pkt);
                erpc_comms_struct.nof_free++;
            }
            erpc_comms_struct.erpc_malloc_failed++;
            erpc_comms_struct.size_malloc_failed = rx_len;
            transport_mark_failure();
            return -ENOMEM;
        }
        erpc_comms_struct.nof_malloc++;
        rx_pkt->len = rx_len;
    }

    if (min_len > 0U) {
        if (!wait_for_drdy_irq_or_level(s_nint_spec, K_MSEC(kDrdyTimeoutMs))) {
            transport_mark_failure();
            goto fail;
        }
        ret = spi_transfer_wait(s_spi_spec,
                                &tx_pkt->data[0],
                                &rx_pkt->data[0],
                                min_len);
        if (ret != 0) {
            transport_mark_failure();
            goto fail;
        }
    }

    if (tx_len > min_len) {
        if (!wait_for_drdy_irq_or_level(s_nint_spec, K_MSEC(kDrdyTimeoutMs))) {
            transport_mark_failure();
            goto fail;
        }
        ret = spi_transfer_wait(s_spi_spec,
                                &tx_pkt->data[min_len],
                                NULL,
                                tx_len - min_len);
        if (ret != 0) {
            transport_mark_failure();
            goto fail;
        }
    }

    if (rx_len > min_len) {
        if (!wait_for_drdy_irq_or_level(s_nint_spec, K_MSEC(kDrdyTimeoutMs))) {
            transport_mark_failure();
            goto fail;
        }
        ret = spi_transfer_wait(s_spi_spec,
                                NULL,
                                &rx_pkt->data[min_len],
                                rx_len - min_len);
        if (ret != 0) {
            transport_mark_failure();
            goto fail;
        }
    }

    if (tx_pkt != NULL) {
        vPortFree(tx_pkt);
        erpc_comms_struct.nof_free++;
    }
    if ((rx_pkt != NULL) && (xQueueSend(g_rx_queue, &rx_pkt, K_MSEC(kQueueTimeoutMs)) != pdTRUE)) {
        vPortFree(rx_pkt);
        erpc_comms_struct.nof_free++;
        erpc_comms_struct.q_send_failed++;
        transport_mark_failure();
        return -EAGAIN;
    }

    erpc_comms_struct.rx_queue_comms += (rx_pkt != NULL) ? 1U : 0U;
    erpc_comms_struct.nof_response_data += (rx_pkt != NULL) ? 1U : 0U;
    erpc_comms_struct.total_tx_bytes += tx_len;
    erpc_comms_struct.total_rx_bytes += rx_len;
    transport_mark_progress();
    return 0;

fail:
    if (tx_pkt != NULL) {
        vPortFree(tx_pkt);
        erpc_comms_struct.nof_free++;
    }
    if (rx_pkt != NULL) {
        vPortFree(rx_pkt);
        erpc_comms_struct.nof_free++;
    }
    return -EIO;
}

static void drdy_isr(const struct device *port, struct gpio_callback *cb, uint32_t pins)
{
    ARG_UNUSED(port);
    ARG_UNUSED(cb);
    ARG_UNUSED(pins);
    k_sem_give(&s_drdy_sem);
    if (s_abs_master_instance != NULL) {
        s_abs_master_instance->ready_cb();
    }
}

static void transport_thread_entry(void *arg1, void *arg2, void *arg3)
{
    ARG_UNUSED(arg2);
    ARG_UNUSED(arg3);

    ARG_UNUSED(arg1);
    struct k_poll_event events[2];

    k_poll_event_init(&events[0], K_POLL_TYPE_SEM_AVAILABLE, K_POLL_MODE_NOTIFY_ONLY, &s_tx_kick_sem);
    k_poll_event_init(&events[1], K_POLL_TYPE_SEM_AVAILABLE, K_POLL_MODE_NOTIFY_ONLY, &s_drdy_sem);

    while (true) {
        (void)k_poll(events, ARRAY_SIZE(events), K_FOREVER);

        while (k_sem_take(&s_tx_kick_sem, K_NO_WAIT) == 0) {
        }
        while (k_sem_take(&s_drdy_sem, K_NO_WAIT) == 0) {
        }

        while ((k_msgq_num_used_get(&s_tx_queue) > 0U) || (gpio_pin_get_dt(s_nint_spec) == 0)) {
            if (transport_exchange_once() != 0) {
                if (s_consecutive_failures >= kStuckRetryThreshold) {
                    transport_recover(s_spi_spec, s_nint_spec);
                }
                break;
            }
        }
    }
}

namespace {
    static inline bool pin_is_asserted(struct gpio_dt_spec *ioport)
    {
        return gpio_pin_get_dt(ioport) == 0;
    }
} // namespace

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

AbsMasterTransport::AbsMasterTransport(void * p_abs_instance, void * p_ioport_instance, uint16_t int_pin):
m_abs_inst((struct spi_dt_spec*)p_abs_instance), m_ioport_inst((struct gpio_dt_spec*)p_ioport_instance), m_int_pin(int_pin), m_isInited(false)
#if ERPC_THREADS
    , m_slaveReadySemaphore()
#endif
{
	ARG_UNUSED(m_int_pin);
	k_msgq_init(&s_tx_queue, s_tx_queue_buf, sizeof(void *), 16);
	k_msgq_init(&s_rx_queue, s_rx_queue_buf, sizeof(void *), 16);
    k_sem_init(&s_tx_kick_sem, 0, K_SEM_MAX_LIMIT);
    k_sem_init(&s_drdy_sem, 0, K_SEM_MAX_LIMIT);
    memset(&erpc_comms_struct, 0, sizeof(erpc_comms_struct));
    s_consecutive_failures = 0;
    s_transport_thread_started = false;
    s_abs_master_instance = this;
    s_spi_spec = m_abs_inst;
    s_nint_spec = m_ioport_inst;
}

AbsMasterTransport::~AbsMasterTransport(void)
{
    // FSP instances are owned by the BSP; nothing to free here.
}

erpc_status_t AbsMasterTransport::init(void)
{
    if ((NULL == m_abs_inst) || (NULL == m_ioport_inst))
    {
        return kErpcStatus_Fail;
    }

    if (!spi_is_ready_dt(m_abs_inst) || !gpio_is_ready_dt(m_ioport_inst))
    {
        return kErpcStatus_Fail;
    }

    if (gpio_pin_configure_dt(m_ioport_inst, GPIO_INPUT) != 0)
    {
        return kErpcStatus_Fail;
    }

    gpio_init_callback(&s_drdy_cb_data, drdy_isr, BIT(m_ioport_inst->pin));
    if (gpio_add_callback(m_ioport_inst->port, &s_drdy_cb_data) != 0) {
        return kErpcStatus_Fail;
    }

    if (gpio_pin_interrupt_configure_dt(m_ioport_inst, GPIO_INT_EDGE_TO_ACTIVE) != 0) {
        return kErpcStatus_Fail;
    }

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    // If slave is already asserting ready, unblock immediately.
    if (pin_is_asserted(m_ioport_inst))
    {
    #if ERPC_THREADS_IS(NONE)
        s_isSlaveReady = true;
    #else
        m_slaveReadySemaphore.put();
    #endif
    }
#endif

    if (!s_transport_thread_started) {
        (void)k_thread_create(&s_transport_thread,
                              s_transport_stack,
                              K_THREAD_STACK_SIZEOF(s_transport_stack),
                              transport_thread_entry,
                              this,
                              NULL,
                              NULL,
                              K_PRIO_PREEMPT(8),
                              0,
                              K_NO_WAIT);
                    s_transport_thread_started = true;
    }

    m_isInited = true;
    return kErpcStatus_Success;
}

void AbsMasterTransport::ready_cb(void)
{
#if ERPC_THREADS_IS(NONE)
    s_isSlaveReady = true;
#else
    m_slaveReadySemaphore.put();
#endif
}

void AbsMasterTransport::wait_for_slave_ready()
{
    while (!pin_is_asserted(m_ioport_inst)) {
        (void)k_sem_take(&s_drdy_sem, K_MSEC(kDrdyTimeoutMs));
    }
}

erpc_status_t AbsMasterTransport::underlyingReceive(uint8_t * data, uint32_t size)
 {

    static transport_queue_item_t *p_pkt;
     //GCTODO CHECK LENGTH
    // Block indefinitely until data arrives from the eRPC Communication Task
    if((erpc_comms_struct.erpc_rx_state == 0) && (size==6))
    {

        if (xQueueReceive(g_rx_queue, &p_pkt, portMAX_DELAY) == pdTRUE) {
            erpc_comms_struct.rx_queue_in_erpc++;
            // Copy queue item to internal class buffer
            //memcpy(m_incomingBuffer, item.data, item.len);
            memcpy(data, &p_pkt->data[0], size);
            erpc_comms_struct.erpc_rx_state = 1;
        } else {
            vPortFree(p_pkt);
            erpc_comms_struct.nof_free++;
            erpc_comms_struct.erpc_rx_state = 0;
            return kErpcStatus_Fail; // Should not happen with portMAX_DELAY
        }
    }
    else if( erpc_comms_struct.erpc_rx_state ==1)
    {
         //CHECKS GCTODO
         memcpy(data, &p_pkt->data[6], size);
#if (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_SPI)
         vPortFree(p_pkt);
#endif
         erpc_comms_struct.nof_free++;
         erpc_comms_struct.erpc_rx_state = 0;
//         vTaskDelay(pdMS_TO_TICKS(10));
    }
    else
    {
        return kErpcStatus_Fail;
    }
    return kErpcStatus_Success;
}

erpc_status_t AbsMasterTransport::underlyingSend(const uint8_t * data, uint32_t size)
{

    transport_queue_item_t *p_pkt = (transport_queue_item_t *)pvPortMalloc(sizeof(transport_queue_item_t) + size);

    if(p_pkt == NULL)
    {
        erpc_comms_struct.erpc_malloc_failed++;
        erpc_comms_struct.size_malloc_failed = size;
        return kErpcStatus_MemoryError; // Message too big for our fixed block
    }

    erpc_comms_struct.nof_malloc++;


    //GCTODO CHECK SIZE

     memcpy(p_pkt->data, data, size);

    p_pkt->len = (uint16_t) size;
    if (xQueueSend(g_tx_queue, &p_pkt, pdMS_TO_TICKS(100)) != pdTRUE)
    {

        vPortFree(p_pkt);
        erpc_comms_struct.nof_free++;
        erpc_comms_struct.q_send_failed++;

        return kErpcStatus_Timeout;
    }
    k_sem_give(&s_tx_kick_sem);
    erpc_comms_struct.rx_queue_out_erpc++;

    return kErpcStatus_Success;
}
