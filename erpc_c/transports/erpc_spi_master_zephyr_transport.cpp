/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "erpc_spi_master_zephyr_transport.hpp"
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>



extern "C" {
extern QueueHandle_t g_tx_queue; // Data Master wants to send
extern QueueHandle_t g_rx_queue; // Data Master receives
extern erpc_comms_t erpc_comms_struct;
}

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

namespace {
    static inline bool pin_is_asserted(ioport_instance_t * ioport, bsp_io_port_pin_t pin)
    {
        // nINT is active-low (asserts on falling edge). Adjust if your board differs.
        bsp_io_level_t level = BSP_IO_LEVEL_HIGH;
        (void) R_IOPORT_PinRead(ioport, pin, &level);

        return (level == BSP_IO_LEVEL_LOW);
    }
} // namespace

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

AbsMasterTransport::AbsMasterTransport(void * p_abs_instance, void * p_ioport_instance, uint16_t int_pin):
//m_spi_inst(reinterpret_cast<spi_instance_t *>(p_spi_instance)), m_ioport_inst(reinterpret_cast<ioport_instance_t *>(p_ioport_instance)), m_int_pin(static_cast<bsp_io_port_pin_t>(int_pin)), m_isInited(false)
#if (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_UART)
m_abs_inst((uart_instance_t*)p_abs_instance), m_ioport_inst((ioport_instance_t*)p_ioport_instance), m_int_pin((bsp_io_port_pin_t)int_pin), m_isInited(false) //VTODO,from slave
#elif (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_SPI)
m_abs_inst((spi_instance_t*)p_abs_instance), m_ioport_inst((ioport_instance_t*)p_ioport_instance), m_int_pin((bsp_io_port_pin_t)int_pin), m_isInited(false) //VTODO,from slave
#endif
#if ERPC_THREADS
    , m_slaveReadySemaphore()
#endif
{
    s_abs_master_instance = this;
}

AbsMasterTransport::~AbsMasterTransport(void)
{
    // FSP instances are owned by the BSP; nothing to free here.
}

erpc_status_t AbsMasterTransport::init(void)
{
    if ((NULL == m_abs_inst) || (NULL == m_abs_inst->p_api) || (NULL == m_abs_inst->p_ctrl))
    {
        return kErpcStatus_Fail;
    }

#if (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_UART)
    serial_open(0);
#elif (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_SPI)
    // Open transport (ignore already-open)
    fsp_err_t err = m_abs_inst->p_api->open(m_abs_inst->p_ctrl, m_abs_inst->p_cfg);
    if ((FSP_SUCCESS != err) && (FSP_ERR_ALREADY_OPEN != err))
    {
        return kErpcStatus_Fail;
    }
#endif

#ifdef ERPC_BOARD_SPI_SLAVE_READY_USE_GPIO
    if (NULL == m_ioport_inst)
    {
        return kErpcStatus_Fail;
    }
    // If slave is already asserting ready, unblock immediately.
    if (pin_is_asserted(m_ioport_inst, m_int_pin))
    {
    #if ERPC_THREADS_IS(NONE)
        s_isSlaveReady = true;
    #else
        m_slaveReadySemaphore.put();
    #endif
    }
#endif

#if (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_SPI)
// VTODO, interrupt on DREADY, pin is the same with DELETE_BOND_INFO_SUPPORT, my_app_main.c line 1382
    R_IOPORT_PinWrite(&g_ioport_ctrl, SPI_CS_PIN, BSP_IO_LEVEL_HIGH); //Make sure CS is deasserted on init
#endif
    return kErpcStatus_Success;
}

void AbsMasterTransport::wait_for_slave_ready()
{
    while (!pin_is_asserted(m_ioport_inst, m_int_pin))
    {
        __NOP();
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
    erpc_comms_struct.rx_queue_out_erpc++;

    return kErpcStatus_Success;
}

#include "hal_data.h"
// Callback function for External IRQ, DREADY pin from slave
void external_irq_callback(external_irq_callback_args_t *p_args)
{

}
