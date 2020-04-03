#ifndef _ULID_COMMON_H_
#define _ULID_COMMON_H_

/* GLOBAL INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

/* LOCAL INCLUDES */
#include "error.h"
#include "util.h"

/** CLASS DEFINITION:
 * This class is a place holder for compiling common headers and useful function or structurres relevent to the whole project.
 *
 * @Author Jacob Robert Pratt
 * @Date January 7th, 2020
 */

/* Common messages that cen be used to print to the terminal. They are mostly used in testing
    and building the software, but can be used if you desire to output messages to the terminal.*/
#define ERRMSG(a) printf("[%s@%d] ERROR: %s\n",&(strrchr(__FILE__,'/')[1]),__LINE__,a);
#define WRNMSG(a) printf("[%s@%d] WARNING: %s\n",&(strrchr(__FILE__,'/')[1]),__LINE__,a);
#define TSTMSG(a) printf("[%s@%d] %s\n",&(strrchr(__FILE__,'/')[1]),__LINE__,a);

/**
 * The  XXXX_fraction_t structures represent a more accurate version of a floating point number. Since floating point numbers can lose values as they are passed around and manipulated, we use a fraction representation to maintain dependency. This idea is taken from the open sourrce FFMpeg library, I suggest you look through it as it's very cool.
 */

typedef struct uint8_fraction_t {
    uint8_t num;
    uint8_t den;
} uint8_frac;

typedef struct uint16_fraction_t {
    uint16_t num;
    uint16_t den;
} uint16_frac;

typedef struct uint32_fraction_t {
    uint32_t num;
    uint32_t den;
} uint32_frac;

typedef struct uint64_fraction_t {
    uint64_t num;
    uint64_t den;
} uint64_frac;

typedef struct int8_fraction_t {
    int8_t num;
    int8_t den;
} int8_frac;

typedef struct int16_fraction_t {
    int16_t num;
    int16_t den;
} int16_frac;

typedef struct int32_fraction_t {
    int32_t num;
    int32_t den;
} int32_frac;

typedef struct int64_fraction_t {
    int64_t num;
    int64_t den;
} int64_frac;


/* Generating a generic objects macros */

#endif
