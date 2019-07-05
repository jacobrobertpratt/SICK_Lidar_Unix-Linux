#ifndef __ULID_SICK_TIM551__
#define __ULID_SICK_TIM551__

#include "ulid_common.h"


int SICK_UpdateParametersTim551(Lidar * lidar);

int SICK_ScanDataTim551(Lidar * lidar);

/*  Sets default values for SICK's TIM551 per SOPAS Documentation */
int SICK_InitializeTim551(Lidar * lidar);

#endif
