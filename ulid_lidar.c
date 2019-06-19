#include "ulid_lidar.h"

/*
 returns: 1 if lidar device doesn't exists, 0 otherwise. */
int InitializeLidarDevice(lidar_t * lidar, Device device) {
    switch(device){
        case TIM551:
            lidar->model = device;
            // Below needs to be put in an init file //
            lidar->scan_freq = 15;
            lidar->active_sectors = 1;
            lidar->ang_res = 1;
            lidar->start_ang = -45;
            lidar->stop_ang = 225;
            strcpy(lidar->sock.ip,"192.168.0.2");
            lidar->sock.port = 2112;
            CreateTCPConnection(&lidar->sock);
            
            break;
        case LMS511:
            // TODO //
            break;
        default:
            printf("ERROR: lidar device doesn't exist --> %s   @   %d\n",__FILE__,__LINE__);
            return 1;
    }
    return 0;
}

/*  */
int DestroyLidarDevice(lidar_t * lidar) {
    DestroyTCPConnection(&lidar->sock);
    DestroyErrorLog(&lidar->e_log);
    return 0;
}



// Put a Lidar_main(int argv, char * argc[]) ... here to fork to at some point.
