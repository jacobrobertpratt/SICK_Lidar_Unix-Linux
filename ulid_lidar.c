#include "ulid_lidar.h"

/*  */
int DestroyLidarDevice(Lidar * lidar) {
    printf("Entered: %s\n",__FUNCTION__); // callback test
    // use callback to destroy error log
    // use callback to destroy tcp connection
    return 0;
}

/*
 returns: 1 if lidar device doesn't exists, 0 otherwise. */
int InitializeLidarDevice(Lidar * lidar, Device device) {
    switch(device){
        case TIM551:
            SICK_InitializeTim551(lidar); // Sets callbacks for TIM551 specific functions
            // Initialize error messaging --> set error callbacks
            // Initialize TCP Connections --> set tcp callbacks
            // Initialize SOPAS Commands --> set sopas callbacks
            break;
        case LMS511:
            // TODO -->
            break;
        default:
            printf("printf - ERROR: lidar device doesn't exist --> %s   @   %d\n",__FILE__,__LINE__);
            return 1;
    }
    return 0;
}


// Put a Lidar_main(int argv, char * argc[]) ... here to fork to at some point.
