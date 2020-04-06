
#include "../include/telegram.h"

Telegram * telegram_alloc() {
    
    Telegram * tele = (Telegram*) malloc(sizeof(Telegram));
    if(!tele) {
        uliderror(errno);
        return NULL;
    }
    
    tele->code = TELEGRAM_STRUCT_CODE; // 7
    tele->device_number = 0;
    tele->device_timestamp = 0;
    tele->sys_timestamp = 0;
    tele->layer_angle = 0;
    tele->scan_freq.num = 0;
    tele->scan_freq.den = 0;
    tele->channel = 0;
    tele->dist_unit = MILLIMETER;
    tele->scale_factor = 1;
    tele->start_angle.num = 0;
    tele->start_angle.den = 0;
    tele->angular_step.num = 1; // 1-deg
    tele->angular_step.den = 1; // 1-deg
    tele->data_count = 0;
    tele->data_format = 0;
    tele->max_dist = 0;
    tele->data = NULL;
    
    return tele;
}

int telegram_free(Telegram ** tele) {
    
    if(!(*tele)) {
        return ERROR_TYPENULL;
    }
    
    if((*tele)->data)
        free((*tele)->data);
    
    free(*tele);
    *tele = NULL;
    
    return 0;
}
