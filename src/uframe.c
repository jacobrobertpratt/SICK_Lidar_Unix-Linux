
#include "../include/uframe.h"

static int uframe_buildFrameTele(uFrame * frame, Telegram * tele) {
    
    uint32_t width = frame->width;
    uint32_t height = frame->height;
    
    double minfrmdim = min(width,height);
    
    // position of lidar device
    uint16_t xpos_lidar = frame->width / 2;
    uint32_t ypos_lidar = (frame->height * 2) / 3;
    
    // TODO: construct a frame from an allocated and filled telegram structure
    
    // tele->scale_factor = strtol(arr[21], NULL, 16);
    
    // arr[23] --> start angle (SAVE)
    
    // tele->start_angle.num = strtol(arr[23], NULL, 16);
    // tele->start_angle.den = 10000; // sopas secific
    
    // arr[24] --> Size of single angular step (Output format in degree: 1/10000°) (SAVE)
    // tele->angular_step.num = strtol(arr[24], NULL, 16);
    // tele->angular_step.den = 10000; // sopas specific
    
    // arr[25] --> amount of data (Defines the number of items on measured output) (SAVE)
    // tele->data_count = strtol(arr[25], NULL, 16);
    
    // Set the Triangle robot position
    
    double angle = (double)tele->start_angle.num / tele->start_angle.den;
    double angstep = (double)tele->angular_step.num / tele->angular_step.den;
    
    double maxdist = tele->max_dist;
    
    printf("minfrmdim: %lf\n",minfrmdim);
    printf("max mills: %lf\n",maxdist);
    
    double distperpix = maxdist / minfrmdim;
    printf("distperpix: %lf\n",distperpix);
    
    double x_pos, y_pos;
    
    uint32_t * data = malloc(frame->width * frame->height * sizeof(uint32_t));
    uint32_t * strt = data;
    memset(data, 0, frame->width * frame->height * sizeof(uint32_t));
    
    int i;
    for(i = 0; i < tele->data_count; i++) {
        x_pos = xpos_lidar + ((cos(angle * 3.1415926 / 180) * tele->data[i]) / distperpix);
        y_pos = ypos_lidar - ((sin(angle * 3.1415926 / 180) * tele->data[i]) / distperpix);
        angle += angstep;
        printf("xpos: %lf    ypos: %lf\n",x_pos, y_pos);
        if(x_pos < 1 || y_pos < 1 || y_pos > frame->height || x_pos > frame->width)
            continue;
        udraw_drawPoint(strt,frame->width,(int)x_pos,(int)y_pos,3);
    }
    
    save_frameAsJPEG(strt,frame->width,frame->height,32,"test",0);
    
    free(strt);
    
    return 0;
}

uFrame * uframe_alloc() {
    uFrame * frame = NULL;
    frame = (uFrame*)malloc(sizeof(uFrame));
    if(!frame) {
        uliderror(errno);
        return NULL;
    }
    frame->data = NULL;
    return frame;
}

void uframe_free(uFrame * frame) {
    if(!frame)
        return;
    if(frame->data)
        free(frame->data);
    free(frame);
}

int uframe_init(uFrame * frame, int width, int height, int bitperpix) {
    
    int ret = 0;
    
    if(!frame)
        return ERROR_TYPENULL;
    
    // Set struct code
    frame->code = ULID_FRAME_STRUCT_CODE;
    
    // Set bits per pixel
    if(bitperpix > 0)
        frame->bitperpix = bitperpix;
    else
        frame->bitperpix = 32;
    
    frame->stride = frame->bitperpix / 8;
    
    // Set frame width and height
    if(width < 64)
        frame->width = 64;
    else if (width > 2160)
        frame->width = 2160;
    else
        frame->width = width;
    
    if(height < 64)
        frame->height = 64;
    else if (height > 1080)
        frame->height = 1080;
    else
        frame->height = height;
    
    return ret;
}

int uframe_buildFrame(uFrame * frame, void * data, int type) {
    
    int ret = 0;
    
    // Check input data
    if(!frame || !data)
        return ERROR_TYPENULL;
    
    uint8_t width = frame->width;
    uint8_t height = frame->height;
    uint8_t bpp = frame->bitperpix;
    
    // Width and Height must be set
    if(width == 0 || height == 0)
        return ERROR_DATA;
    
    // If previous data is allocated free it
    if(frame->data)
        free(frame->data);
    
    // Allocate frame data
    frame->data = (uint8_t*)malloc(sizeof(uint8_t)*height*width*bpp);
    if(!frame->data)
        return errno;
        
    // Select type of input data for building frame
    if(type == TELEGRAM_STRUCT_CODE) {
        Telegram * tele = (Telegram*)data;
        if(tele->code != TELEGRAM_STRUCT_CODE)
            return ERROR_TYPE;
        ret = uframe_buildFrameTele(frame, tele);
        if(ret) return ret;
    }
    else {
        free(frame->data);
        frame->data = NULL;
        return ERROR_TYPEDATA;
    }
    
    return 0;
}

int uframe_reset(uFrame * frame) {
    int ret = 0;
    if(!frame)
        return ERROR_TYPENULL;
    if(frame->data)
        free(frame->data);
    frame->data = NULL;
    return ret;
}
