/*
 * Copyright 2018,2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * Generated by erpcgen 1.14.0 on Wed May 28 10:34:55 2025.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include <new>
#include "c_erpc_two_way_rpc_Core0Interface_server.h"
#include "erpc_two_way_rpc_Core0Interface_server.hpp"
#include "erpc_manually_constructed.hpp"
#include "erpc_utils.hpp"

using namespace erpc;
using namespace std;
using namespace erpcShim;


static const getNumberCallback_t _getNumberCallback_t[1] = { getNumberFromCore1 };

class Core0Interface_server: public Core0Interface_interface
{
    public:
        virtual ~Core0Interface_server() {};


        void setGetNumberFunction(const getNumberCallback_t getNumberCallbackParam)
        {
            uint16_t _fnIndex;
            ::getNumberCallback_t _getNumberCallbackParam = NULL;

            if (Core0Interface_interface::get_callbackIdx_getNumberCallback_t(&getNumberCallbackParam, _fnIndex))
            {
                _getNumberCallbackParam=::_getNumberCallback_t[_fnIndex];
            }

            ::setGetNumberFunction(_getNumberCallbackParam);
        }

        void getGetNumberFunction(getNumberCallback_t * getNumberCallbackParam)
        {
            uint16_t _fnIndex;
            ::getNumberCallback_t _getNumberCallbackParam = NULL;

            ::getGetNumberFunction(&_getNumberCallbackParam);

            if (findIndexOfFunction((arrayOfFunctionPtr_t)::_getNumberCallback_t, sizeof(::_getNumberCallback_t)/sizeof(::getNumberCallback_t), (functionPtr_t)_getNumberCallbackParam, _fnIndex))
            {
                Core0Interface_interface::get_callbackAddress_getNumberCallback_t(_fnIndex, getNumberCallbackParam);
            }
        }

        void nestedCallGetNumber(const getNumberCallback_t getNumberCallbackParam)
        {
            uint16_t _fnIndex;
            ::getNumberCallback_t _getNumberCallbackParam = NULL;

            if (Core0Interface_interface::get_callbackIdx_getNumberCallback_t(&getNumberCallbackParam, _fnIndex))
            {
                _getNumberCallbackParam=::_getNumberCallback_t[_fnIndex];
            }

            ::nestedCallGetNumber(_getNumberCallbackParam);
        }

        void getNumberFromCore1(uint32_t * number)
        {
            ::getNumberFromCore1(number);
        }
};

ERPC_MANUALLY_CONSTRUCTED_STATIC(Core0Interface_service, s_Core0Interface_service);
ERPC_MANUALLY_CONSTRUCTED_STATIC(Core0Interface_server, s_Core0Interface_server);

erpc_service_t create_Core0Interface_service(void)
{
    erpc_service_t service;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    service = new (nothrow) Core0Interface_service(new (nothrow)Core0Interface_server());
#else
    if (s_Core0Interface_service.isUsed())
    {
        service = NULL;
    }
    else
    {
        s_Core0Interface_server.construct();
        s_Core0Interface_service.construct(s_Core0Interface_server.get());
        service = s_Core0Interface_service.get();
    }
#endif

    return service;
}

void destroy_Core0Interface_service(erpc_service_t service)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    if (service)
    {
        delete (Core0Interface_server *)(((Core0Interface_service *)service)->getHandler());
        delete (Core0Interface_service *)service;
    }
#else
    (void)service;
    erpc_assert(service == s_Core0Interface_service.get());
    s_Core0Interface_service.destroy();
    s_Core0Interface_server.destroy();
#endif
}

