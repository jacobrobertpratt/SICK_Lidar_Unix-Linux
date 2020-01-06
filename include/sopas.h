#ifndef ULID_SOPAS_COM
#define ULID_SOPAS_COM

#include "common.h"
#include "lidar.h"

typedef enum command_t {
    READ,
    WRITE,
    METHOD,
    EVENT,
    RETREAD,
    RETWRITE,
    RETMETHOD,
    RETEVENT,
    RETCHANGE,
    ERROR
} Command;

typedef enum subject_t {
    LOGIN
} Subject;

/* Login
 - used by all devices the same.
 */
int sopas_login(Lidar * lidar);

// Logout

#endif
