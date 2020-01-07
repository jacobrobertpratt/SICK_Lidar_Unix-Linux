#ifndef ULID_TELEGRAM_H
#define ULID_TELEGRAM_H

#include "common.h"
#include "error.h"

/** CLASS DEFINITION:
 * @Author Jacob R Pratt
 * @Date January 7th 2020
 */

/**
 * DistUnit represents the unit value of length given to each data point. This is used in the telegram structurer below to bring world dimensions from the telegram. If one device gives readings in (mm) and the other in (feet), we then have a bases to compare the two measurments.
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
 * A telegrram structure represent the information passed back to our system from a LIDAR device. It holds all the pertinent information relevant to a measurment. This can then be stored in a buffer or passed to a display class to output the information. This can also be used as information to a logic class. This is a generic structure and has a high possibility to change (to a more general or unique format) as more LIDAR devices are added. A reference to this structure is generally passed to those functions that return LIDAR measurments.
 */
typedef struct telegram_t {
    
    // Device number associated with this this telegram
    uint8_t devicenumber;
    
    /* Time in μ-secs when the complete scan is transmitted to the buffer for data output; starting with 0 at scanner bootup. */
    uint32_t device_timestamp;
    
    /* Time in μ-secs when the telegram was recieved from the device. This
        is calculated from the system time. */
    uint32_t sys_timestamp;
    
    // Layer angle of scan. Could be positive or negative.
    int16_t layerangle;
    
    // fraction value where the completed division is in Hz.
    uint32_frac scanfreq;
    
    // the specific channel this telegram came from
    uint16_t channel;
    
    // Distance unit (mm, cm, meter, feet, yards)
    DistUnit distunit;
    
    // Scale factor of measurment x1 or x2
    int scalefactor;
    
    // Fractional value of start angle
    int32_frac startangle;
    
    // Angular step --> distance between measurments
    uint16_t angularstep;
    
    // The total number of measured values
    uint16_t measurmentcount;
    
    // Repesents the format of the data (1 = radial, 0 = cartesian)
    int dataformat;
    
    /* Data comes in a a 2-dimensional array. The values can either be in radial or cartesian format. The format is specified in the format field. */
    uint32_frac ** data;
    
} Telegram;

//
Telegram * telegram_alloc();

//
int telegram_free(Telegram * tele);



#endif /* ULID_TELEGRAM_H */
