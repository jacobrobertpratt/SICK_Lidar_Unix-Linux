
#include "../include/uframe.h"

uFrame * frame_alloc() {
    uFrame * frame = NULL;
    frame = (uFrame*)malloc(sizeof(uFrame));
    if(!frame) {
        uliderror(errno);
        return NULL;
    }
    
    frame->width = 0;
    frame->height = 0;
    frame->data = NULL;
    
    return frame;
}

void frame_free(uFrame * frame) {
    
    if(!frame)
        return;
    
    if(frame->data)
        free(frame->data);
    
    free(frame);
}

int frame_initialize(uFrame * frame, int width, int height) {
    
    if(!frame) {
        return ERROR_TYPENULL;
    }
    
    if(width < 0 || height < 0)
        return ERROR_SIZE;
    
    frame->width = width;
    frame->height = height;
    
    // Set to a 32-bit pixel format size although should be changed later
    frame->data = (uint32_t*)malloc(sizeof(uint32_t) * width * height);
    if(!frame->data)
        return errno;
    
    return 0;
}

int frame_buildFrame(uFrame * frame, void * type) {
    if(!frame || !type)
        return ERROR_TYPENULL;
    
    if((frame->width == 0) || (frame->height == 0))
        return ERROR_DATA;
    
    return 0;
}
