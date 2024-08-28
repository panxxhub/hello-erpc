/*
 * Generated by erpcgen 1.13.0 on Wed Aug 28 14:22:23 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_erpc_servo_configure_common_h_)
#define _erpc_servo_configure_common_h_


#if defined(__cplusplus)
extern "C"
{
#endif
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "erpc_version.h"

#if 11300 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif


#if !defined(ERPC_TYPE_DEFINITIONS_ERPC_SERVO_CONFIGURE)
#define ERPC_TYPE_DEFINITIONS_ERPC_SERVO_CONFIGURE

// Enumerators data types declarations
typedef enum AxisType
{
    D_AXIS = 0,
    Q_AXIS = 1
} AxisType;

typedef enum AdcType
{
    ADC_VBUS = 0,
    ADC_IBUS = 1,
    ADC_TEMP = 2,
    ADC_CURRENT0 = 3,
    ADC_CURRENT1 = 4,
    ADC_CURRENT2 = 5,
    ADC_VOLTAGE0 = 6,
    ADC_VOLTAGE1 = 7,
    ADC_VOLTAGE2 = 8,
    ADC_MAIN_ENCODER_SIN = 9,
    ADC_MAIN_ENCODER_COS = 10
} AdcType;

// Aliases data types declarations
typedef struct DQ DQ;
typedef struct OscDataElement OscDataElement;
typedef struct PV PV;
typedef struct SdoSubEntry SdoSubEntry;
typedef struct Sdo Sdo;
typedef struct OscDataFragment OscDataFragment;
typedef struct MainEncoderInfo MainEncoderInfo;

// Structures/unions data types declarations
struct DQ
{
    float d;
    float q;
};

struct OscDataElement
{
    int16_t v_bus;
    int16_t v_3d[3];
    int16_t c_3d[3];
    uint32_t timestamp;
};

struct PV
{
    float p;
    float v;
};

struct SdoSubEntry
{
    int16_t sub_index;
    uint8_t data[256];
};

struct Sdo
{
    int16_t index;
    SdoSubEntry sub_entries[64];
};

struct OscDataFragment
{
    int16_t id;
    OscDataElement data[64];
};

struct MainEncoderInfo
{
    uint64_t timestamp;
    int32_t velocity;
    int32_t single_turn;
    int16_t single_turn_width;
    int32_t multi_turn;
};


// Constant variable declarations
extern const int32_t servo_param_max_size;

extern const int32_t sdo_max_sub_entry_size;

extern const int32_t osc_fragment_max_size;

extern const double velocity_to_rmp_ratio;

#endif // ERPC_TYPE_DEFINITIONS_ERPC_SERVO_CONFIGURE

#if defined(__cplusplus)
}
#endif

#endif // _erpc_servo_configure_common_h_
