#ifndef _ULID_FRAME_H_
#define _ULID_FRAME_H_

#include <stdlib.h>
#include "common.h"
#include "telegram.h"
#include "udraw.h"

#define ULID_FRAME_STRUCT_CODE  8

/* Pixel format for the frame information. */
#define ULID_PIXFMT_ARGB        1;

/* CLASS DESCRIPTION */



typedef struct ulid_frame_t {
    uint8_t code;
    uint8_t * data;
    uint32_t width:13, height:13, bitperpix:6;
    uint32_t stride:15;
    // % away from edge of shortest side of frame
    uint8_t edgebuffer;
} uFrame;

/* */
uFrame * uframe_alloc();

/* */
void uframe_free(uFrame * frame);

/* */
int uframe_init(uFrame * frame, int width, int height, int bitperpix);

/* */
int uframe_buildFrame(uFrame * frame, void * data, int type);

/* */
int uframe_reset(uFrame * frame);

#endif
