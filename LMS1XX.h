/*
 */

#ifndef _ULLID_SICK_LMS1XX
#define _ULLID_SICK_LMS1XX

struct LMS1xx {
    uint32_t scanFrequency;
    uint32_t angularResolution;
    int_32 startAngle;
    int_32 stopAngle;
    // TODO --> each lidar gets it's own structure that contains data
};

// methods specific to the lidar goes here. 

#endif
