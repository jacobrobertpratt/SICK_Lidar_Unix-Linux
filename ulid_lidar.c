#include "ulid_lidar.h"

/*  */
int DestroyLidarDevice(Lidar * lidar) {
    printf("Entered: %s\n",__FUNCTION__);
    DestroyErrorLog(lidar);
    return 0;
}

/*
 returns: 1 if lidar device doesn't exists, 0 otherwise. */
int InitializeLidarDevice(Lidar * lidar, Device device) {
    switch(device){
        case TIM551:
            lidar->model = device;
            // Below needs to be put in an init file //
            lidar->scan_freq = 15;
            lidar->active_sectors = 1;
            lidar->ang_res = 1;
            lidar->start_ang = -45;
            lidar->stop_ang = 225;
            strcpy(lidar->errorLog.path,"./");
            strcpy(lidar->errorLog.name,"error_log");
            CreateErrorLog(lidar);
            SetKillProcessCallback(DestroyLidarDevice); // If an error occurs then the callback calls the destroyLidarDevice function
            LogError(lidar,"test message",__FILE__,__LINE__);
            break;
        case LMS511:
            // TODO -->
            break;
        default:
            printf("ERROR: lidar device doesn't exist --> %s   @   %d\n",__FILE__,__LINE__);
            return 1;
    }
    return 0;
}


// Put a Lidar_main(int argv, char * argc[]) ... here to fork to at some point.
