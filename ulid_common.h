#ifndef __ULID_COMMON_HEADERS__
#define __ULID_COMMON_HEADERS__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>

#include <time.h>
#include <string.h>

/****************** COMMON STRUCTS ******************/

struct lidar_t;

/*  ErrorLog */
typedef struct errorLog_t {
    FILE * file;
    char path[1024];
    char name[100];
    int count;
} ErrorLog;




/*  TCP Socket structure */
typedef struct tcpSocket_t {
    int sockid, port;
    struct sockaddr_in addr;
    char ip[16];
} TcpSocket;




/*  Device is an enum of all available devices */
typedef enum device_t {
    TIM551,
    LMS511,
    MRS1000
} Device;




/*  Callbacks */
typedef struct callbacks_t {
    // int (*errorMessage)(struct lidar_t * lidar, const char * msg, const char * file, int line);  // --> setting error message callback
    int (*ScanData)(struct lidar_t * lidar);
    int (*destroyLidar)(struct lidar_t * lidar);
} Callbacks;




/*  User Level Enumorator
 This is used to log in and specify the userlevel of the SOPAS device.
 Not a direct association with a device it will need to be specified. */
typedef enum userlevel_t {
    MAINTENENCE,
    CLIENT,
    SERVICE
} UserLevel;




/*  Lidar general */
typedef struct lidar_t {
    // Primatives
    uint32_t scan_freq, ang_res;
    int32_t start_ang, stop_ang;
    uint16_t active_sectors;
    // structs
    Device device;
    UserLevel userLevel;
    ErrorLog errorLog;
    TcpSocket tcpSocket;
    // Callbacks
    Callbacks callbacks;
} Lidar;




/*  Message packet that can be passed around */
typedef struct message_t {
    // would like to make this a pointer not array but need a function to initialize it same with outMsg;
    char outMsg[100];
    char retMsg[100000];
    //int outMsgSize, retMsgSize;
} Message;







/****************** MACROS ******************/



/****************** LOCAL HEADERS ******************/
#include "ulid_utility.h"
#include "ulid_error.h"
#include "ulid_tcp_conn.h"
#include "ulid_sopas_comm.h"
#include "ulid_lidar.h"



/****************** LIDAR HEADERS ******************/
#include "ulid_sick_tim551.h"




#endif
