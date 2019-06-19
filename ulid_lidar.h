#ifndef __ULID_LIDAR__
#define __ULID_LIDAR__

#include "ulid_common.h"

/* Destroy */
int DestroyLidarDevice(Lidar * lidar);

/* Create */
int InitializeLidarDevice(Lidar * lidar, Device device);

#endif
