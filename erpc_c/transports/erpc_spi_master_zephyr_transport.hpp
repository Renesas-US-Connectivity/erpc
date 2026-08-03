/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _EMBEDDED_RPC_ZEPHYR_SPI_MASTER_TRANSPORT_H_
#define _EMBEDDED_RPC_ZEPHYR_SPI_MASTER_TRANSPORT_H_

#include "erpc_config_internal.h"
#if !ERPC_THREADS_IS(NONE)
#include "erpc_threading.h"
#endif
#include "erpc_framed_transport.hpp"

#include <cstdlib>

extern "C" {
#include <stdlib.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
}

/*!
 * @addtogroup abs_master_transport
 * @{
 * @file
 */

////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////

namespace erpc {
/*!
 * @brief Transport to send/receive messages via the transport.
 *
 * @ingroup abs_master_transport
 */
class AbsMasterTransport : public FramedTransport
{
public:
    /*!
     * @brief Constructor.
     *
     * @param[in] p_abs_instance Pointer to transport instance.
     * @param[in] p_ioport_instance Pointer to IOPORT instance.
     * @param[in] int_pin GPIO pin number used for nINT signal from slave.
     */
    AbsMasterTransport(void * p_abs_instance, void * p_ioport_instance, uint16_t int_pin);

    /*!
     * @brief Destructor.
     */
    virtual ~AbsMasterTransport(void);

    /*!
     * @brief Initialize the transport peripheral configuration structure with values specified in AbsTransport constructor.
     *
     * @retval kErpcStatus_Success Always returns success status.
     */
    virtual erpc_status_t init(void);

    /*!
     * @brief Function called when nINT GPIO input is asserted signaling the slave is ready
     *
     * Unblocks the send and receive functions.
     */
    void ready_cb(void);

protected:
#if (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_UART)
    uart_instance_t *m_abs_inst;
#elif (CFG_ERPC_TRANSPORT == ERPC_TRANSPORT_SPI)
    spi_instance_t *m_abs_inst;
#endif
    ioport_instance_t *m_ioport_inst;
    bsp_io_port_pin_t m_int_pin;
    bool m_isInited;         /*!< the transport peripheral init status flag */
#if ERPC_THREADS
    Semaphore m_slaveReadySemaphore;
#endif

private:
    using FramedTransport::underlyingReceive;
    using FramedTransport::underlyingSend;

    /*!
     * @brief Receive data from the transport peripheral.
     *
     * @param[inout] data Preallocated buffer for receiving data.
     * @param[in] size Size of data to read.
     *
     * @retval kErpcStatus_ReceiveFailed Transport failed to receive data.
     * @retval kErpcStatus_Success Successfully received all data.
     */
    virtual erpc_status_t underlyingReceive(uint8_t *data, uint32_t size) override;

    /*!
     * @brief Write data to the transport peripheral.
     *
     * @param[in] data Buffer to send.
     * @param[in] size Size of data to send.
     *
     * @retval kErpcStatus_SendFailed Transport failed to send data.
     * @retval kErpcStatus_Success Successfully sent all data.
     */
    virtual erpc_status_t underlyingSend(const uint8_t *data, uint32_t size) override;

    // Block until the slave asserts ready
    void wait_for_slave_ready();
};

} // namespace erpc

/*! @} */

#endif // _EMBEDDED_FSP_ABS_MASTER_TRANSPORT_H_
