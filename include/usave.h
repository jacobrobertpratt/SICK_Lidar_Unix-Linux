#ifndef _ULID_SAVE_H_
#define _ULID_SAVE_H_

#include "common.h"

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>

int save_frameAsJPEG(uint32_t * data, int pic_width, int pic_height, int bitperpix, char * name, int idx);

#endif
