#include "ulid_sick_tim551.h"


int SICK_InitializeTim551(Lidar * lidar) {
    
    // device specific values
    lidar->device = TIM551;
    
    // Allocate memory for TCP socket
    lidar->tcpSocket = TCPCreateSocketStruct();
    
    lidar->tcpSocket->port = 2112;
    strcpy(lidar->tcpSocket->ip,"192.168.0.2"); // Temp value and will need to be set earlier in the code during start or an .ini file.
    
    // Establish socket connection
    if(TCPCreateConnection(lidar->tcpSocket)){
        printf("ERROR: failed to create tcp connection --> %s @ line %d\n",__FILE__,__LINE__);
        return 1;
    }
    
    // Set callbacks
    lidar->callbacks.startMeasurments = SICK_StartMeasurmentTim551;
    
    return 0;
}


int SICK_DestroyTim551(Lidar * lidar) {
    
    // Stop any measurment
    
    
    // Destroy the socket
    if(TCPDestroySocket(lidar->tcpSocket)){
        printf("Warning: couldn't close socket struct --> %s @ line %d\n",__FILE__,__LINE__);
    }
    
    
    
    return 0;
}


int SICK_StartMeasurmentTim551(Lidar * lidar) {
    
    /*  Will need to make this a loop if we want to get continuous measurments */
    
    // Make sure Lidar isn't NULL
    if(lidar == NULL){
        printf("ERROR: lidar device doesn't exist --> %s   @   %d\n",__FILE__,__LINE__);
        return 1;
    }
    
    // Create a message packet
    Message * message = CreateMessagePacket();
    if(message == NULL){
        printf("ERROR: message failed to allocate --> %s   @   %d\n",__FILE__,__LINE__);
        return 1;
    }
    
    // Gets the message from SOPAS functions and structures.
    message = SOPAS_EncodeMessage(lidar,READ,LMDscandata);
    if(message == NULL){
        printf("ERROR: failed to encode sopas message --> %s   @   %d\n",__FILE__,__LINE__);
        return 1;
    }
    
    // Send message to lidar
    /*if(TCPExchangeMessage(lidar->tcpSocket,message->data)){
        printf("ERROR: message to lidar failed to send --> %s   @   %d\n",__FILE__,__LINE__);
        return 1;
    }*/
    
    // Destroy message packet
    if(DestroyMessagePacket(message)){
        printf("ERROR: message to deallocate --> %s   @   %d\n",__FILE__,__LINE__);
        return 1;
    }
    
    return 0;
}
