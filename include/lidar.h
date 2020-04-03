#ifndef ULID_LIDAR_H
#define ULID_LIDAR_H

#include "common.h"
#include "sopas.h"

#define LIDAR_STRUCT_CODE 0x0005

/* */
typedef enum device_type_t{
    NONE,
    TIM551
} Device;

/* */
typedef struct callback_t {
    int (*run)();
} Callback;

/* */
typedef struct lidar_t {
    
    // Call sign of this structure for deallocations purposes.
    int struct_code;
    
    // If lidar is sopas we use sopas struct for information
    Sopas * sopas;
    
    // Initialize a callback_t structure for standard callbacks
    Callback callback;
    
    // Set the device type
    Device device;
    
    // Device name -> user defined for user use
    char * name;
    
    // Possibly have a buffer here for Telegram structures
    
} Lidar;

/* */
Lidar * lidar_alloc();

/* */
int lidar_free(Lidar * lidar);

/* */
int lidar_initialize(Lidar * lidar, const char * name, Device type);

#endif /* ULID_LIDAR_H */
