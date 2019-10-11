#include "ulid_lidar.h"

Lidar * CreateLidarDevice() {
    
    Lidar * lidar = (Lidar*) malloc(sizeof(Lidar));
    if(lidar == NULL){
        printf("ERROR: lidar device failed to allocate memory in %s at line %d\n",__FUNCTION__,__LINE__);
        return NULL;
    }
    
    // tcpSocket is a structure in ulid_common.h
    lidar->tcpSocket = NULL;
    
    /*  callbacks is a callback struct in ulid_common.h
     *  These will be set later in the specific lidar's source file.
     *  example TIM551 --> SICK_InitializeTim551(lidar) sets these. */
    lidar->callbacks.destroyLidar = NULL;
    lidar->callbacks.startMeasurments = NULL;
    
    return lidar;
}


int DestroyLidarDevice(Lidar * lidar) {
    
    // Check if lidar has allocated memory
    if(lidar == NULL){
        // Log error
        printf("ERROR: lidar can't be free --> %s @ line %d\n",__FUNCTION__,__LINE__);
        return 1;
    }
    
    // Destroy lidar specific memory allocations
    switch(lidar->device){
        case TIM551:
            SICK_DestroyTim551(lidar);
            break;
        case LMS511:
            // TODO
            break;
        default:
            printf("printf - ERROR: lidar device doesn't exist --> %s   @   %d\n",__FILE__,__LINE__);
            return 1;
    }
    
    // Free Lidar
    free(lidar);
    
    exit(0);
    return 0;
}


int InitializeLidarDevice(Lidar * lidar, Device device) {
    
    switch(device){
        case TIM551:
            SICK_InitializeTim551(lidar);
            break;
        case LMS511:
            // TODO
            break;
        default:
            printf("ERROR: lidar device doesn't exist --> %s   @   %d\n",__FILE__,__LINE__);
            return 1;
    }
    
    // Sets callback to kill lidar device
    lidar->callbacks.destroyLidar = DestroyLidarDevice;
    
    return 0;
}


int StartLidarMeasurments(Lidar * lidar) {
    
    // Check if Lidar is not created
    if(lidar == NULL){
        printf("ERROR: lidar device doesn't exist --> %s   @   %d\n",__FILE__,__LINE__);
        return 1;
    }
    
    if(lidar->callbacks.startMeasurments == NULL) {
        printf("ERROR: start measurment callback not set --> %s   @   %d\n",__FILE__,__LINE__);
        return 1;
    }
    
    lidar->callbacks.startMeasurments(lidar); // Starts the lidar measurment.
    
    return 0;
}
