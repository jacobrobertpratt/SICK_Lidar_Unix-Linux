#ifndef __ULID_LIDAR__
#define __ULID_LIDAR__

#include "ulid_common.h"

/* Destroy */
int DestroyLidarDevice(Lidar * lidar);

/* Create */
int InitializeLidarDevice(Lidar * lidar, Device device);

// At some point we want to save the lidar information to pull it up again.

#endif
