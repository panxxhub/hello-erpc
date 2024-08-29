/*
 * Generated by erpcgen 1.13.0 on Thu Aug 29 13:52:21 2024.
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
        static const uint8_t m_setSdoSubEntryId = 1;
        static const uint8_t m_sdoLoadFactorySettingsId = 2;
        static const uint8_t m_sdoEntryLoadFactorySettingsId = 3;
        static const uint8_t m_sdoSubEntryLoadFactorySettingsId = 4;
        static const uint8_t m_getSdoSubEntryId = 5;
        static const uint8_t m_saveAllToNonVolatileMemoryId = 6;

        virtual ~ServoConfigureService_interface(void);

        virtual int32_t setSdoSubEntry(uint16_t index, const SdoSubEntry * subEntry) = 0;

        virtual int32_t sdoLoadFactorySettings(void) = 0;

        virtual int32_t sdoEntryLoadFactorySettings(uint16_t index) = 0;

        virtual int32_t sdoSubEntryLoadFactorySettings(uint16_t index, uint8_t subIndex) = 0;

        virtual int32_t getSdoSubEntry(uint16_t index, uint8_t subIndex, SdoSubEntry * subEntry) = 0;

        virtual int32_t saveAllToNonVolatileMemory(void) = 0;
private:
};
} // erpcShim


#endif // _erpc_servo_configure_interface_hpp_
