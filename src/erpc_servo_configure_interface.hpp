/*
 * Generated by erpcgen 1.13.0 on Thu Aug 29 09:19:44 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_erpc_servo_configure_interface_hpp_)
#define _erpc_servo_configure_interface_hpp_

#include "erpc_servo_configure_common.hpp"

namespace erpcShim
{


// Abstract base class for ServoConfigureService
class ServoConfigureService_interface
{
    public:
        static const uint8_t m_serviceId = 1;
        static const uint8_t m_getSdoSubEntryId = 1;

        virtual ~ServoConfigureService_interface(void);

        virtual int32_t getSdoSubEntry(int16_t index, int16_t subIndex, SdoSubEntry * subEntry) = 0;
private:
};
} // erpcShim


#endif // _erpc_servo_configure_interface_hpp_
