#ifndef _ULID_COMMON_H_
#define _ULID_COMMON_H_

/* GLOBAL INCLUDES */
#include <stdio.h>
#include <stdlib.h>

#define ULID_ERROR_COUNT    113     // The number of local error numbers that we have


/* MACROS */
#define _INCREMENT_ (__COUNTER__ + ULID_ERROR_COUNT + 1)     // Increments a count starting at last number past our final error message number (currrently at 110)

#endif
