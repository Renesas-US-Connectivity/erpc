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
 * @addtogroup spi_master_transport
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
 * @ingroup spi_master_transport
 */
class SpiMasterTransport : public FramedTransport
{
public:
    /*!
     * @brief Constructor.
     *
     * TODO update parameter list
     * @param[in] dev Zephyr SPI device.
     */
    SpiMasterTransport(struct spi_dt_spec *spi, struct gpio_dt_spec *gpio);

    /*!
     * @brief Destructor.
     */
    virtual ~SpiMasterTransport(void);

    /*!
     * @brief Initialize SPI peripheral configuration structure with values specified in SpiTransport constructor.
     *
     * @retval kErpcStatus_Success Always returns success status.
     */
    virtual erpc_status_t init(void);

protected:
    struct spi_dt_spec *m_spi; /*!< Access structure of the SPI device */
    struct gpio_dt_spec *m_gpio; /*!< Access structure of the GPIO device */

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
};

} // namespace erpc

/*! @} */

#endif // _EMBEDDED_RPC_ZEPHYR_SPI_MASTER_TRANSPORT_H_
