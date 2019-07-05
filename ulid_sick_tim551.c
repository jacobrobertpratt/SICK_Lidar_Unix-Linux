#include "ulid_sick_tim551.h"

int SICK_UpdateParametersTim551(Lidar * lidar) {
    
    // updates the parameters on the lidar
    
    return 0;
}

int SICK_ScanDataTim551(Lidar * lidar) {
    // method to run and take in data then send it to the shared memory location
    
    return 0;
}


/*  Sets default values for SICK's TIM551 per SOPAS Documentation */
int SICK_InitializeTim551(Lidar * lidar) {
    
    // device
    lidar->device = TIM551;
    lidar->userLevel = CLIENT;
    
    // basic settings
    lidar->scan_freq = 15;
    lidar->active_sectors = 1;
    lidar->ang_res = 1;
    lidar->start_ang = -45;
    lidar->stop_ang = 225;
    
    // Error Reporting
    strcpy(lidar->errorLog.path,"./");
    strcpy(lidar->errorLog.path,"tim551_errorLog");
    lidar->errorLog.count = 0;
    
    // TCP Connection
    lidar->tcpSocket.port = 2112;
    strcpy(lidar->tcpSocket.ip,"192.168.0.2");
    
    // Set callbacks
    lidar->callbacks.ScanData = SICK_ScanDataTim551;
    
    return 0;
}
