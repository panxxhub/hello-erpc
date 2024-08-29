/*
 * Generated by erpcgen 1.13.0 on Thu Aug 29 13:52:21 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "c_erpc_servo_configure_client.h"
#include "erpc_servo_configure_client.hpp"
#include "erpc_manually_constructed.hpp"

using namespace erpc;
using namespace std;
using namespace erpcShim;


#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
ServoConfigureService_client *s_ServoConfigureService_client = nullptr;
#else
ERPC_MANUALLY_CONSTRUCTED_STATIC(ServoConfigureService_client, s_ServoConfigureService_client);
#endif

int32_t setSdoSubEntry(uint16_t index, const SdoSubEntry * subEntry)
{
    int32_t result;
    result = s_ServoConfigureService_client->setSdoSubEntry(index, subEntry);

    return result;
}

int32_t sdoLoadFactorySettings(void)
{
    int32_t result;
    result = s_ServoConfigureService_client->sdoLoadFactorySettings();

    return result;
}

int32_t sdoEntryLoadFactorySettings(uint16_t index)
{
    int32_t result;
    result = s_ServoConfigureService_client->sdoEntryLoadFactorySettings(index);

    return result;
}

int32_t sdoSubEntryLoadFactorySettings(uint16_t index, uint8_t subIndex)
{
    int32_t result;
    result = s_ServoConfigureService_client->sdoSubEntryLoadFactorySettings(index, subIndex);

    return result;
}

int32_t getSdoSubEntry(uint16_t index, uint8_t subIndex, SdoSubEntry * subEntry)
{
    int32_t result;
    result = s_ServoConfigureService_client->getSdoSubEntry(index, subIndex, subEntry);

    return result;
}

int32_t saveAllToNonVolatileMemory(void)
{
    int32_t result;
    result = s_ServoConfigureService_client->saveAllToNonVolatileMemory();

    return result;
}

void initServoConfigureService_client(erpc_client_t client)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    erpc_assert(s_ServoConfigureService_client == nullptr);
    s_ServoConfigureService_client = new ServoConfigureService_client(reinterpret_cast<ClientManager *>(client));
#else
    erpc_assert(!s_ServoConfigureService_client.isUsed());
    s_ServoConfigureService_client.construct(reinterpret_cast<ClientManager *>(client));
#endif
}

void deinitServoConfigureService_client(void)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    if (s_ServoConfigureService_client != nullptr)
    {
        delete s_ServoConfigureService_client;
        s_ServoConfigureService_client = nullptr;
    }
#else
    s_ServoConfigureService_client.destroy();
#endif
}
