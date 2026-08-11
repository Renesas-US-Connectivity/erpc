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

ERPC_MANUALLY_CONSTRUCTED_STATIC(AbsMasterTransport, s_absTransport);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

erpc_transport_t erpc_transport_zephyr_spi_master_init(void * p_abs_instance, void * p_ioport_instance)
{
    AbsMasterTransport *absTransport;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
    if (s_absTransport.isUsed())
    {
        absTransport = NULL;
    }
    else
    {
        s_absTransport.construct(p_abs_instance, p_ioport_instance, 0);
        absTransport = s_absTransport.get();
    }
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    absTransport = new AbsMasterTransport(p_abs_instance, p_ioport_instance, 0);
#else
#error "Unknown eRPC allocation policy!"
#endif

    if (absTransport != NULL)
    {
        (void)absTransport->init();
    }

    return reinterpret_cast<erpc_transport_t>(absTransport);
}

void erpc_transport_zephyr_spi_master_deinit(erpc_transport_t transport)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
    (void)transport;
    s_absTransport.destroy();
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    erpc_assert(transport != NULL);

    AbsMasterTransport *absTransport = reinterpret_cast<AbsMasterTransport *>(transport);

    delete absTransport;
#endif
}