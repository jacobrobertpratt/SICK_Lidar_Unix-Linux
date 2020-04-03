#ifndef _ULID_FRAME_H_
#define _ULID_FRAME_H_

#include <stdlib.h>
#include "common.h"
#include "telegram.h"

#define ULID_FRAME_STRUCT_CODE  0x0008

typedef struct ulid_frame_t {
    uint32_t width:12, height:12; // 4K (4096 x 4096)
    uint32_t * data; // pixel format = 32-bit for now -> update later
} uFrame;

/* */
uFrame * frame_alloc();

/* */
void frame_free(uFrame * frame);

/* */
int frame_initialize(uFrame * frame, int width, int height);

/* */
int frame_buildFrame(uFrame * frame, void * type);

#endif
