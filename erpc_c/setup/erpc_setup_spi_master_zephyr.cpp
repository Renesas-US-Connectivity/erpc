/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "erpc_manually_constructed.hpp"
#include "erpc_spi_master_zephyr_transport.hpp"
#include "erpc_transport_setup.h"

using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

ERPC_MANUALLY_CONSTRUCTED_STATIC(SpiMasterTransport, s_spiTransport);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

erpc_transport_t erpc_transport_zephyr_spi_master_init(void *spi, void *rdy, void *intr)
{
    SpiMasterTransport *spiTransport;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
    if (s_spiTransport.isUsed())
    {
        spiTransport = NULL;
    }
    else
    {
        s_spiTransport.construct(reinterpret_cast<struct spi_dt_spec *>(spi), reinterpret_cast<struct gpio_dt_spec *>(gpio));
        spiTransport = s_spiTransport.get();
    }
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    spiTransport = new SpiMasterTransport(reinterpret_cast<struct spi_dt_spec *>(spi), reinterpret_cast<struct gpio_dt_spec *>(rdy), reinterpret_cast<struct gpio_dt_spec *>(intr));
#else
#error "Unknown eRPC allocation policy!"
#endif

    if (spiTransport != NULL)
    {
        (void)spiTransport->init();
    }

    return reinterpret_cast<erpc_transport_t>(spiTransport);
}

void erpc_transport_zephyr_spi_master_deinit(erpc_transport_t transport)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
    (void)transport;
    s_spiTransport.destroy();
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    erpc_assert(transport != NULL);

    SpiMasterTransport *spiTransport = reinterpret_cast<SpiMasterTransport *>(transport);

    delete spiTransport;
#endif
}
