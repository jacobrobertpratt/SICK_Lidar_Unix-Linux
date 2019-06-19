#ifndef __ULID_SOPAS_COM__
#define __ULID_SOPAS_COM__

#include "ulid_common.h"

/*  User Level Enumorator
    This is used to log in and specify the userlevel of the SOPAS device.
    Not a direct association with a device it will need to be specified. */
typedef enum UserLevel {
    MAINTENENCE,
    CLIENT,
    SERVICE
} UserLevel;

/************************ SHARED SOPAS FUNCTIONS ************************/

/*  */
int SOPAS_LogIn(int sock_id, enum UserLevel level);

/*  */
int SOPAS_ReadScanConfig(int sock_id);



#endif
