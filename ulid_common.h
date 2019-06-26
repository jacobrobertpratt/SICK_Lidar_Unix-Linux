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
    LMS511
} Device;

/*  Callbacks */
typedef struct callbacks_t {
    int (*setScanFrequency)(struct lidar_t * lidar, int freq);
    int (*setAngularResolution)(struct lidar_t * lidar, int resolution);
    int (*setStartAngle)(struct lidar_t * lidar, int angle);
    int (*setStopAngle)(struct lidar_t * lidar, int angle);
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
    Device model;
    UserLevel userLevel;
    ErrorLog errorLog;
    TcpSocket tcpSocket;
    // Callbacks
    Callbacks callbacks;
} Lidar;

/*  Message packet that can be passed around */
typedef struct message_t {
    char * outMsg;
    char * retMsg;
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
