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

/* ErrorLog */
typedef struct ErrorLog {
    FILE * file;
    char path[1024];
    char name[100];
    int count;
} ErrorLog;

/* TCP Socket structure */
typedef struct TcpSocket {
    int sockid, port;
    struct sockaddr_in addr;
    char ip[16];
} TcpSocket;

/*  */
typedef enum Device {
    TIM551,
    LMS511
} Device;

/*  */
typedef struct Lidar {
    // Primatives
    uint32_t scan_freq, ang_res;
    int32_t start_ang, stop_ang;
    uint16_t active_sectors;
    // structs
    Device model;
    ErrorLog errorLog;
    TcpSocket tcpSocket;
} Lidar;




/****************** MACROS ******************/







/****************** LOCAL HEADERS ******************/
#include "ulid_utility.h"
#include "ulid_error.h"
#include "ulid_tcp_conn.h"
#include "ulid_sopas_comm.h"
#include "ulid_lidar.h"

#endif
