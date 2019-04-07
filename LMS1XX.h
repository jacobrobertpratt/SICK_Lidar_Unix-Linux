/*
 */

#ifndef _ULLID_SICK_LMS1XX
#define _ULLID_SICK_LMS1XX

#include <stdint.h>

struct LMS1xx {
    
    // Scan Configuration
    uint32_t    scan_frequency;
    uint32_t    angular_resolution;
    int32_t      start_angle;
    int32_t      stop_angle;
    
    // LMDscandatacfg --> pg 16
    uint8_t     *   data_channel;
    
    // TODO --> each lidar gets it's own structure that contains data
};

char lms1xx_password_arr[3][9];

char lms1xx_user_level_arr[3][2];

#endif
