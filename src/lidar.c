
#include "../include/lidar.h"

Lidar * lidar_alloc() {
    
    // Allocate memory for this structure
    Lidar * lidar = (Lidar *) malloc(sizeof(Lidar));
    if(!lidar) {
        uliderror(errno);
        return NULL;
    }
    
    // Assign the call-sign of this structure
    lidar->struct_code = LIDAR_STRUCT_CODE;
    
    // Could stay NULL depending on the lidar used.
    lidar->sopas = sopas_alloc();
    lidar->name = NULL;
    
    // Set device to none
    lidar->device = NONE;
    
    // Set the callbacks to none
    lidar->callback.run = NULL;
    
    return lidar;
}

int lidar_free(Lidar * lidar) {
    
    if(!lidar) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    if(lidar->struct_code != LIDAR_STRUCT_CODE) {
        uliderror(ERROR_STRUCTCODE);
        return ERROR_STRUCTCODE;
    }
    
    if(lidar->sopas)
        sopas_free(&(lidar->sopas));
    
    free(lidar);
    
    return 0;
}

int lidar_initialize(Lidar * lidar, const char * name, Device device) {
    
    // Check input parameters
    if(!lidar || !name){
        uliderror(ERROR_TYPENULL);
        return 1;
    }
    
    // Check for correct device type parameter
    if(device == NONE) {
        uliderror(ERROR_TYPE);
        return ERROR_TYPE;
    }
    
    // Set name and device type
    if(!lidar->name){
        lidar->name = strdup(name);
        if(!lidar->name){
            uliderror(errno);
            return errno;
        }
    }
    else {
        uliderror(ERROR_REPLACE);
    }
    
    // Set the type of device
    if(lidar->device == NONE) {
        lidar->device = device;
    }
    else {
        uliderror(ERROR_REPLACE);
        return ERROR_REPLACE;
    }
    
    // Set the callback functions specific to the device
    if(device == TIM551) {
        
        // TODO: assign callback functions here for general purpose
        
    }
    else {
        uliderror(ERROR_TYPE);
        return ERROR_TYPE;
    }
    
    return 0;
}
