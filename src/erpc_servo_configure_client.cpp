/*
 * Generated by erpcgen 1.13.0 on Thu Aug 29 09:19:44 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include "erpc_port.h"
#endif
#include "erpc_codec.hpp"
#include "erpc_servo_configure_client.hpp"
#include "erpc_manually_constructed.hpp"

#if 11300 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;
using namespace erpcShim;


// Constant variable definitions
#if defined(__MINGW32__)
__declspec( selectany )
#else
#pragma weak servo_param_max_size
#endif
extern const int32_t servo_param_max_size = 8;
#if defined(__MINGW32__)
__declspec( selectany )
#else
#pragma weak sdo_max_sub_entry_size
#endif
extern const int32_t sdo_max_sub_entry_size = 64;
#if defined(__MINGW32__)
__declspec( selectany )
#else
#pragma weak osc_fragment_max_size
#endif
extern const int32_t osc_fragment_max_size = 64;
#if defined(__MINGW32__)
__declspec( selectany )
#else
#pragma weak velocity_to_rmp_ratio
#endif
extern const double velocity_to_rmp_ratio = 0.227317;

//! @brief Function to read struct SdoSubEntry
static void read_SdoSubEntry_struct(erpc::Codec * codec, SdoSubEntry * data);


// Read struct SdoSubEntry function implementation
static void read_SdoSubEntry_struct(erpc::Codec * codec, SdoSubEntry * data)
{
    if(NULL == data)
    {
        return;
    }

    codec->read(data->sub_index);

    for (uint32_t arrayCount0 = 0U; arrayCount0 < 8U; ++arrayCount0)
    {
        codec->read(data->data[arrayCount0]);
    }
}




ServoConfigureService_client::ServoConfigureService_client(ClientManager *manager)
:m_clientManager(manager)
{
}

ServoConfigureService_client::~ServoConfigureService_client()
{
}

// ServoConfigureService interface getSdoSubEntry function client shim.
int32_t ServoConfigureService_client::getSdoSubEntry(int16_t index, int16_t subIndex, SdoSubEntry * subEntry)
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = m_clientManager->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = m_clientManager->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(message_type_t::kInvocationMessage, m_serviceId, m_getSdoSubEntryId, request.getSequence());

        codec->write(index);

        codec->write(subIndex);

        // Send message to server
        // Codec status is checked inside this function.
        m_clientManager->performRequest(request);

        read_SdoSubEntry_struct(codec, subEntry);

        codec->read(result);

        err = codec->getStatus();
    }

    // Dispose of the request.
    m_clientManager->releaseRequest(request);

    // Invoke error handler callback function
    m_clientManager->callErrorHandler(err, m_getSdoSubEntryId);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = m_clientManager->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = -1;
    }

    return result;
}
