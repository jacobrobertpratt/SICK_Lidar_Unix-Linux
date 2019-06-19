#ifndef __ULID_LIDAR__
#define __ULID_LIDAR__

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "ulid_tcp_conn.h"
#include "ulid_error.h"
#include "ulid_sopas_comm.h"

/*  */
typedef enum {
    TIM551,
    LMS511
} Device;

/*  */
typedef struct {
    uint32_t scan_freq, ang_res;
    int32_t start_ang, stop_ang;
    uint16_t active_sectors;
    tcp_socket_t sock;
    Device model;
    error_log_t e_log;
} lidar_t;

/* Create */
int InitializeLidarDevice(lidar_t * lidar, Device device);

/* Destroy */
int DestroyLidarDevice(lidar_t * lidar);

#endif
