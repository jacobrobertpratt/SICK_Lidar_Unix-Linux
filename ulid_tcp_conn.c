#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "ulid_tcp_conn.h"

/*  */
int CreateTCPConnection(tcp_socket_t * sock) {
    
    // Create a socket
    sock->sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock->sockid < 0){
        // log error
        printf("ERROR: Socket failed to initialize --> %s   @   %d\n", __FUNCTION__, __LINE__);
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
int DestroyTCPConnection(tcp_socket_t * sock) {
    if(!sock->sockid)
        close(sock->sockid);
    return 0;
}
