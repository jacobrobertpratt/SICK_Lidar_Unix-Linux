#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "ullid_connection_tcp.h"



/*  */
int CreateTCPConnection(TcpSocket * sock) {
    
    // Create a socket
    sock->sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock->sockid < 0){
        // log error
        return 1;
    }
    
    // Clear the sockaddr_in struct
    memset(&sock->addr, 0, sizeof(sock->addr));
    
    // Set up the structure to connect
    sock->addr.sin_family = AF_INET;
    sock->addr.sin_port = htons(sock->port);
    sock->addr.sin_addr.s_addr = inet_addr(sock->ip);
    
    // Connect socket to the Lidar
    if(connect(sock->sockid, (struct sockaddr *)(&sock->addr), sizeof(sock->addr)) < 0) {
        // log error
        return 2;
    }
    
    return 0;
}



/*  */
int DestroyTCPConnection(TcpSocket * sock) {
    if(!sock->sockid)
        close(sock->sockid);
    return 0;
}



/*  */
int TCPMessage(TcpSocket * sock, char * sendMsg, char * recvMsg) {
   
    // Check if parameters have value
    if(sock == NULL || sendMsg == NULL) {
        // log error
        return 1;
    }
    
    // Send message to connection
    if(send(sock->sockid,sendMsg,sizeof(sendMsg),0)<0){
        // log error
        return 2;
    }
    
    // Recieve message from connection
    if(recv(sock->sockid,recvMsg,sizeof(recvMsg),0)<0){
        // log error
        return 3;
    }
    
    return 0;
}
