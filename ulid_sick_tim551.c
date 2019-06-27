#include "ulid_sick_tim551.h"

/*  */
int SICK_SetIPAddress(Lidar * lidar, const char * address) {
    if(strlen(address) > 15)
        printf("ERROR: ip address is too long try again --> %s   at   %d\n",__FUNCTION__, __LINE__);
    // TODO --> Actually set the IP address
    return 0;
}

/*  */
int SICK_SetStopAngleTIM551(Lidar * lidar, int angle) {
    // TODO -->
    return 0;
}

/*  */
int SICK_SetStartAngleTIM551(Lidar * lidar, int angle) {
    // TODO -->
    return 0;
}

/*  */
int SICK_SetAngularResolutionTIM551(Lidar * lidar, int resolution) {
    // TODO --> Check on values.
    return 0;
}

/*  Sets the basic settings and
    */
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
    lidar->callbacks.setScanFrequency = NULL;
    lidar->callbacks.setAngularResolution = SICK_SetAngularResolutionTIM551;
    lidar->callbacks.setStartAngle = SICK_SetStartAngleTIM551;
    lidar->callbacks.setStopAngle = SICK_SetStopAngleTIM551;
    return 0;
}
