#include "ulid_lidar.h"

/*  */
int DestroyLidarDevice(Lidar * lidar) {
    // use callback to destroy tcp connection
    DestroyTCPConnection(&lidar->tcpSocket);
    // Destroy error log
    DestroyErrorLog(lidar);
    return 0;
}

/*  Initialize a Lidar Device
    returns: 1 if lidar device doesn't exists, 0 otherwise. */
int InitializeLidarDevice(Lidar * lidar, Device device) {
    switch(device){
        case TIM551:
            SICK_InitializeTim551(lidar); // Sets callbacks for TIM551 specific functions
            // Initialize error messaging --> set error callbacks
            CreateErrorLog(lidar);
            SetKillProcessCallback(DestroyLidarDevice);
            
            // Initialize TCP Connections --> set tcp callbacks
            CreateTCPConnection(&lidar->tcpSocket);
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
