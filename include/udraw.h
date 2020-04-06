#ifndef _ULID_DRAW_H_
#define _ULID_DRAW_H_

#include "common.h"
#include "uframe.h"

/* size is leveling up of point values 1 -> one pixel, 2 -> 9 pixels,
    3 -> 16 pixels ... etc. */
int udraw_drawPoint(uFrame * frame, Point point, uint8_t size);

/* */
//int udraw_drawLine(uFrame * frame, Point from, Point to, uint8_t size);

/* */
//int udraw_drawRect(uFrame * frame, Point topleft, Point botright, uint8_t size);


#endif
