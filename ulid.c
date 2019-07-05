
#include "ulid_common.h"

// 1) Initialize list to set shared memory loation, config file, lidar name ... etc.

// 2) Split into different processes which utilize a shared memory location
// a. Process (1)   ... to (n) will be for connecting and reading from a Lidar and writing to shared memory
// b. Process (n+1) ... to generate logic, building PCL, and other things
// c. Process (n+2) ... to generate front end application that can be seen by the user.

/*  Input arguments ulid tim551 -sm
 *  -sm <shared memory name>]
 *  -config <file_name>
 *
 */


/*  example: args = ./ulid tim551 <dir/config.txt> */
int main(int argc, char * argv[]) {
    
    Lidar lidar;
    
    // Check for config file --> open and read from config file
    InitializeLidarDevice(&lidar,TIM551);
    
    // Get output message
    char * msg = SOPAS_EncodeMessage(&lidar, READ, LMDscandata);
    
    // Create a message packet
    Message msgPacket;
    strcpy(msgPacket.outMsg,msg);
    
    // Sends the and returns the message
    ExchangeTCPMessage(&lidar.tcpSocket,&msgPacket);
    
    printf("retMsg: %s\n",msgPacket.retMsg);
    
    // Confirm message
    SOPAS_DecodeMessage(&lidar,&msgPacket);
    
    free(msg);
    
    DestroyLidarDevice(&lidar);
    
    return 0;
}

