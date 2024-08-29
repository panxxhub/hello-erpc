/*
 * Generated by erpcgen 1.13.0 on Thu Aug 29 11:19:01 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include <new>
#include "c_erpc_servo_configure_server.h"
#include "erpc_servo_configure_server.hpp"
#include "erpc_manually_constructed.hpp"

using namespace erpc;
using namespace std;
using namespace erpcShim;


class ServoConfigureService_server: public ServoConfigureService_interface
{
    public:
        virtual ~ServoConfigureService_server() {};


        int32_t getSdoSubEntry(int16_t index, int16_t subIndex, SdoSubEntry * subEntry)
        {
            int32_t result;
            result = ::getSdoSubEntry(index, subIndex, subEntry);

            return result;
        }
};

ERPC_MANUALLY_CONSTRUCTED_STATIC(ServoConfigureService_service, s_ServoConfigureService_service);
ERPC_MANUALLY_CONSTRUCTED_STATIC(ServoConfigureService_server, s_ServoConfigureService_server);

erpc_service_t create_ServoConfigureService_service(void)
{
    erpc_service_t service;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    service = new (nothrow) ServoConfigureService_service(new (nothrow)ServoConfigureService_server());
#else
    if (s_ServoConfigureService_service.isUsed())
    {
        service = NULL;
    }
    else
    {
        s_ServoConfigureService_server.construct();
        s_ServoConfigureService_service.construct(s_ServoConfigureService_server.get());
        service = s_ServoConfigureService_service.get();
    }
#endif

    return service;
}

void destroy_ServoConfigureService_service(erpc_service_t service)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    if (service)
    {
        delete (ServoConfigureService_server *)(((ServoConfigureService_service *)service)->getHandler());
        delete (ServoConfigureService_service *)service;
    }
#else
    (void)service;
    erpc_assert(service == s_ServoConfigureService_service.get());
    s_ServoConfigureService_service.destroy();
    s_ServoConfigureService_server.destroy();
#endif
}

