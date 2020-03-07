#ifndef ULID_TELEGRAM_H
#define ULID_TELEGRAM_H

#include <time.h>
#include <math.h>

#include "common.h"
#include "error.h"

/** CLASS DEFINITION:
 *A telegrram structure represent the information passed back to our system from a LIDAR device. It holds all the pertinent information relevant to a measurment. This can then be stored in a buffer or passed to a display class to output the information. This can also be used as information to a logic class. This is a generic structure and has a high possibility to change (to a more general or unique format) as more LIDAR devices are added. A reference to this structure is generally passed to those functions that return LIDAR measurments.
 * @Author Jacob R Pratt
 * @Date January 7th 2020
 */

#define TELEGRAM_STRUCT_CODE 0x0007
#define DEBUG(a,b) //printf("[telegram @ %d]: DEBUG: %s -> %d\n", __LINE__, a, b)

/** DISTUNIT:
 * Represents the unit value of length given to each data point. This is used in the telegram structurer below to bring world dimensions from the telegram. If one device gives readings in (mm) and the other in (feet), we then have a bases to compare the two measurments.
 */
typedef enum dist_unit_t {
    MILLIMETER,
    CENTMETER,
    METER,
    KILOMETER,
    INCH,
    FEET,
    YARD
} DistUnit;

/** TELEGRAM:
 *  A telegrram structure represent the information passed back to our system from a LIDAR device. 
 */
typedef struct telegram_t {
    
    // Call sign of this structure for deallocations purposes.
    int struct_code;
    
    // Device number associated with this this telegram
    uint8_t device_number;
    
    /* Time in μ-secs when the complete scan is transmitted to the buffer for data output; starting with 0 at scanner bootup. */
    uint32_t device_timestamp;
    
    /* Time in μ-secs when the telegram was recieved from the device. This
        is calculated from the system time. */
    uint32_t sys_timestamp;
    
    // Layer angle of scan. Could be positive or negative.
    int16_t layer_angle;
    
    // fraction value where the completed division is in Hz.
    uint32_frac scan_freq;
    
    // the specific channel this telegram came from
    uint16_t channel;
    
    // Distance unit (mm, cm, meter, feet, yards)
    DistUnit dist_unit;
    
    // Scale factor of measurment x1 or x2
    int scale_factor;
    
    // Fractional value of start angle
    int32_frac start_angle;
    
    // Angular step --> distance between measurments
    uint16_frac angular_step;
    
    // The total number of measured values
    uint16_t data_count;
    
    // Repesents the format of the data (1 = radial, 0 = cartesian)
    int data_format;
    
    /* Data comes in a a 2-dimensional array. The values can either be in radial or cartesian format. The format is specified in the format field. */
    uint32_t * data;
    
} Telegram;

/* Allocates a tellegram struct setting all the initial parameters to 0, and the pointers to NULL. */
Telegram * telegram_alloc();

//
int telegram_free(Telegram * tele);



#endif /* ULID_TELEGRAM_H */
