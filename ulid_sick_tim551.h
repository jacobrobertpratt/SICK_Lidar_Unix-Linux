#ifndef __ULID_SICK_TIM551__
#define __ULID_SICK_TIM551__

#include "ulid_common.h"

/*  */
int SICK_SetStopAngleTIM551(Lidar * lidar, int angle);

/*  */
int SICK_SetStartAngleTIM551(Lidar * lidar, int angle);

/*  */
int SICK_SetAngularResolutionTIM551(Lidar * lidar, int resolution);

/*  Sets default values for SICK's TIM551 per SOPAS Documentation */
int SICK_InitializeTim551(Lidar * lidar);

#endif
