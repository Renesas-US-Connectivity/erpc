/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _EMBEDDED_RPC__SPI_SLAVE_TRANSPORT_H_
#define _EMBEDDED_RPC__SPI_SLAVE_TRANSPORT_H_

#include "erpc_config_internal.h"
#include <cstdlib>
#if ERPC_THREADS
#include "erpc_threading.h"
#endif
#include "erpc_framed_transport.hpp"

extern "C" {
#include "r_gpio_w.h"
#include "r_spi_w.h"
}

/*!
 * @addtogroup spi_slave_transport
 * @{
 * @file
 */

////////////////////////////////////////////////////////////////////////////////
// Classes
////////////////////////////////////////////////////////////////////////////////

namespace erpc {
/*!
 * @brief Very basic transport to send/receive messages via SPI.
 *
 * @ingroup spi_slave_transport
 */
class SpiSlaveTransport : public FramedTransport
{
public:
    /*!
     * @brief Constructor.
     *
     * @param[in] spiBaseAddr DSPI peripheral base address.
     * @param[in] baudRate Baudrate.
     * @param[in] srcClock_Hz Source clock.
     */
    //SpiSlaveTransport(SPI_Type *spiBaseAddr, uint32_t baudRate, uint32_t srcClock_Hz);
    SpiSlaveTransport(void * p_spi_instance, void * p_ioport_instance, uint16_t dready_pin) ;

    /*!
     * @brief Destructor.
     */
    virtual ~SpiSlaveTransport(void);

    /*!
     * @brief Initialize SPI peripheral configuration structure with values specified in SpiTransport constructor.
     *
     * @retval kErpcStatus_Success Always returns success status.
     */
    virtual erpc_status_t init(void);

    /*!
     * @brief Function called from SPI_SlaveUserCallback when SPI transfer is completed
     *
     * Unblocks the send/receive function.
     */
    void transfer_cb(void);

protected:
    spi_instance_t *m_spi_inst;
    ioport_instance_t *m_ioport_inst;
    //ioport_ctrl_t *m_io_ctrl;
    bsp_io_port_pin_t m_dready_pin;

    bool m_isInited;         /*!< the SPI peripheral init status flag */
#if ERPC_THREADS
    Semaphore m_txrxSemaphore; /*!< Semaphore used by RTOS to block task until the sending/receiving is not complete */
#endif

private:
    using FramedTransport::underlyingReceive;
    using FramedTransport::underlyingSend;

    /*!
     * @brief Receive data from SPI peripheral.
     *
     * @param[inout] data Preallocated buffer for receiving data.
     * @param[in] size Size of data to read.
     *
     * @retval kErpcStatus_ReceiveFailed SPI failed to receive data.
     * @retval kErpcStatus_Success Successfully received all data.
     */
    virtual erpc_status_t underlyingReceive(uint8_t *data, uint32_t size) override;

    /*!
     * @brief Write data to SPI peripheral.
     *
     * @param[in] data Buffer to send.
     * @param[in] size Size of data to send.
     *
     * @retval kErpcStatus_SendFailed SPI failed to send data.
     * @retval kErpcStatus_Success Successfully sent all data.
     */
    virtual erpc_status_t underlyingSend(const uint8_t *data, uint32_t size) override;

    void SpiSlaveTransport_NotifyTransferGpioReady(void);
    void SpiSlaveTransport_NotifyTransferGpioCompleted(void);
};

} // namespace erpc

/*! @} */

#endif // _EMBEDDED_RPC__SPI_SLAVE_TRANSPORT_H_
