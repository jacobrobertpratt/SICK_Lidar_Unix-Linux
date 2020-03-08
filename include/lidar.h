#ifndef ULID_LIDAR_H
#define ULID_LIDAR_H

#include "common.h"
#include "error.h"
#include "sopas.h"

#define LIDAR_STRUCT_CODE 0x0005

/* */
typedef struct lidar_t {
    
    // Call sign of this structure for deallocations purposes.
    int struct_code;
    
    // If lidar is sopas we use sopas struct for information
    Sopas * sopas;
    
} Lidar;

/* */
Lidar * lidar_alloc();

/* */
int lidar_free(Lidar * lidar);

#endif /* ULID_LIDAR_H */
