#ifndef __ULID_SOPAS_COM__
#define __ULID_SOPAS_COM__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/errno.h>

// make a message structure that can be passed around

/* Enums */
/*  */
enum UserLevel {
    MAINTENENCE,
    CLIENT,
    SERVICE
};

// Read ... Write ... etcs

/*  */
int SOPAS_LogIn(int sock_id, enum UserLevel level);

/*  */
int SOPAS_ReadScanConfig(int sock_id);

/*  */







#endif
