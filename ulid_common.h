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


/*  TcpSocket:
 *  Structure that holds a socket ID number, socket port number, sockaddr_in structure,
 *  and and IP address which is held in a 16-byte char array. Generally, a generic
 *  Lidar structure will have a TcpSocket structure. */
typedef struct tcpSocket_t {
    int sockid, port;
    struct sockaddr_in addr;
    char ip[16];
} TcpSocket;




/*  Device:
 *  Structure the represents all types of the devices that are compatable
 *  with the ULID program. */
typedef enum device_t {
    TIM551,
    LMS511
} Device;




/*  Callbacks
 *  The callback struct is a set of generic functions that can be called
 *  from any lidar struct. Each lidar device should be allocated, destroyed,
 *  start a measurment, return information, ... etc. Depending on the Lidar being
 *  used there will be different module that can assign these callbacks. This allows
 *  The ULID program to become more modular. (Need to make a flowchart of the
 *  modularity of the ULID structure)*/
typedef struct callbacks_t {
    //int (*destroyLidar)(struct lidar_t * lidar);
    //int (*startMeasurments)(struct lidar_t * lidar);
} Callbacks;




/*  User Level Enumorator
 *  This is used to log in and specify the userlevel of the SOPAS device.
 *  Not a direct association with a device it will need to be specified. */
typedef enum userlevel_t {
    MAINTENENCE,
    CLIENT,
    SERVICE
} UserLevel;



/*  Lidar general
 *  This is a general implementation of a lidar device with generic callback
 *  function that can be assigned given the specific.
 */
typedef struct lidar_t {
    
    // The label of this specific device.
    Device device;
    
    // The level that the user has access
    UserLevel UserLevel;
    
    // TcpSocket Structure contains all the socket information
    TcpSocket * tcpSocket;
    
    // Callback functions that are spcific to this individual lidar.
    //Callbacks callbacks;
    
} Lidar;


/* ***************** MACROS ***************** */

#define PRINT_ERROR(a)  printf("ERROR: %s --> %s at line %d\n",a,__FILE__, __LINE__)
#define GOT_HERE    printf("got to line %d\n", __LINE__)
#define ENTERED printf("Entered %s in %s at line %d\n", __FUNCTION__, __FILE__, __LINE__)

/* ***************** LOCAL HEADERS ***************** */
//#include "ulid_utility.h"
//#include "ulid_error.h"
//#include "ulid_tcp_conn.h"
//#include "ulid_sopas_comm.h"
//#include "ulid_lidar.h"

/* ***************** LIDAR HEADERS ***************** */
//#include "ulid_sick_tim551.h"

/* ***************** COMMON FUNCTIONS ***************** */

/*  CreateMessagePacket()
 *  Initializes a message structure with the size at 0 and the data set to NULL.
 *  @param none
 *  @return returns a Message packet with all internal values set to NULL on success else NULL on failure.
 */
Message * CreateMessagePacket();

/*  DestroyMessagePacket(Message * message)
 *  @param Message struct, if message structure is not initialized then function returns 1
 *  @return return 0 on success, 1 on failure.
 */
int DestroyMessagePacket(Message * message);

#endif
