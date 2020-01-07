#ifndef __ULID_LIDAR__
#define __ULID_LIDAR__

#include "ulid_common.h"

/*  CeateLidarDevice
 *  Allocates memory for a generic lidar device and sets all callback functions
 *  to NULL. All structures are initialized to NULL.
 *  @return returns NULL if device fails to allocate, else lidar struct on success. */
Lidar * CreateLidarDevice();

/*  DestroyLidarDevice(Lidar * lidar)
 *  If device is not NULL and lidar is initialized then the lidar specific
 *  Destructor will deallocate memory and set all structs to NULL pointer.
 *  @return returns 1 on failure, 0 on success. */
int DestroyLidarDevice(Lidar * lidar);

/*  InitializeLidarDevice(Lidar * lidar, Device device)
*    */
int InitializeLidarDevice(Lidar * lidar, Device device);

/* Start */
int StartLidarMeasurments(Lidar * lidar);

// At some point we want to save the lidar information to pull it up again.

#endif
