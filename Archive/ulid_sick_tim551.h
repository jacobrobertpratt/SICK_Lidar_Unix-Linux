#ifndef __ULID_SICK_TIM551__
#define __ULID_SICK_TIM551__

#include "ulid_common.h"

/*  SICK_InitializeTim551(Lidar * lidar)
 *  */
int SICK_InitializeTim551(Lidar * lidar);

/*  SICK_DestroyTim551(Lidar * lidar)
 *  */
int SICK_DestroyTim551(Lidar * lidar);

/*  SICK_StartMeasurmentTim551(Lidar * lidar)
 *  */
int SICK_StartMeasurmentTim551(Lidar * lidar);



#endif
