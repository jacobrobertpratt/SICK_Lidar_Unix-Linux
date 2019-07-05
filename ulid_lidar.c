#include "ulid_lidar.h"

/*  */
int DestroyLidarDevice(Lidar * lidar) {
    // use callback to destroy tcp connection
    DestroyTCPConnection(&lidar->tcpSocket);
    // Destroy error log
    DestroyErrorLog(lidar);
    exit(0);
    return 0;
}

/*  Initialize a Lidar Device
    returns: 1 if lidar device doesn't exists, 0 otherwise. */
int InitializeLidarDevice(Lidar * lidar, Device device) {
    switch(device){
        case TIM551:
            // Sets callbacks for TIM551 specific functions & basic settings
            SICK_InitializeTim551(lidar);
            
            // If config file exists --> read and update from config file
                // ConfigureLidarDevice(lidar);
            
            // Initialize error messaging --> set error callbacks
            CreateErrorLog(lidar);
            SetKillProcessCallback(DestroyLidarDevice);
            
            // Initialize TCP Connections --> set tcp callbacks
            CreateTCPConnection(&lidar->tcpSocket);
            
            // Sets callback to kill lidar device
            lidar->callbacks.destroyLidar = DestroyLidarDevice;
            
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
