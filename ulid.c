
#include "ulid_common.h"

// 1) Initialize list to set shared memory loation, config file, lidar name ... etc.

// 2) Split into different processes which utilize a shared memory location
// a. Process (1)   ... to (n) will be for connecting and reading from a Lidar and writing to shared memory
// b. Process (n+1) ... to generate logic, building PCL, and other things
// c. Process (n+2) ... to generate front end application that can be seen by the user.


int main(int argc, char * argv[]) {
    
    // Creat lidar device --> might want to change it into a lidar pointer.
    Lidar lidar;
    InitializeLidarDevice(&lidar,TIM551);
    
    // Create message packet
    Message msg;
    
    // Get message from SOPAS
    char * sopasMsg = SOPAS_EncodeMessage(&lidar,READ,SCAN_DATA);
    printf("sopasMsg: %s\n",sopasMsg);
    
    // Copy message to packet
    strcpy(msg.outMsg,sopasMsg);
    free(sopasMsg); // free Encoded Message
    printf("outMsg: %s\n",msg.outMsg);
    
    ExchangeTCPMessage(&lidar.tcpSocket, &msg);
    printf("retMsg: %s\n",msg.retMsg);
    
    DestroyLidarDevice(&lidar);
    
    return 0;
}

