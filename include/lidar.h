#ifndef ULID_LIDAR_H
#define ULID_LIDAR_H

#include "common.h"
#include "error.h"
#include "socket.h"

#define LIDAR_STRUCT_CODE 0x0005

typedef struct lidar_t {
    
    // Call sign of this structure for deallocations purposes.
    int struct_code;
    
    // User level
    uint8_t level;
    
    // password
    char password[20];
    
    Socket * sock;
    
} Lidar;

Lidar * lidar_alloc();

int lidar_free(Lidar * lidar);

#endif /* ULID_LIDAR_H */
