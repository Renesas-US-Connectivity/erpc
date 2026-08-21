/*
 * Copyright (c) 2025 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "erpc_manually_constructed.hpp"
#include "erpc_spi_slave_fsp_transport.hpp"
#include "erpc_transport_setup.h"

using namespace erpc;

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

ERPC_MANUALLY_CONSTRUCTED_STATIC(SpiSlaveTransport, s_spiTransport);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

erpc_transport_t erpc_transport_fsp_spi_slave_init(void * p_spi_instance, void * p_ioport_instance, uint16_t int_pin)
{
    SpiSlaveTransport *spiTransport;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
    if (s_spiTransport.isUsed())
    {
        spiTransport = NULL;
    }
    else
    {
        s_spiTransport.construct(p_spi_instance, p_ioport_instance, int_pin);
        spiTransport = s_spiTransport.get();
    }
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    spiTransport = new SpiSlaveTransport(p_spi_instance, p_ioport_instance, int_pin);
#else
#error "Unknown eRPC allocation policy!"
#endif

    if (spiTransport != NULL)
    {
        erpc_status_t initStatus = spiTransport->init();
        if (initStatus != kErpcStatus_Success)
        {
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
            s_spiTransport.destroy();
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
            delete spiTransport;
#endif
            spiTransport = NULL;
        }
    }

    return reinterpret_cast<erpc_transport_t>(spiTransport);
}

void erpc_transport_spi_slave_deinit(erpc_transport_t transport)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
    (void)transport;
    s_spiTransport.destroy();
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    erpc_assert(transport != NULL);

    SpiSlaveTransport *spiTransport = reinterpret_cast<SpiSlaveTransport *>(transport);

    delete spiTransport;
#endif
}
