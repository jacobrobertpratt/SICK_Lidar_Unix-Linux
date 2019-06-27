#include "ulid_common.h"
#include "ulid_tcp_conn.h"

/*********************** TO IMPROVE ******************************
 *
 *  1)  Work on timeout checks --> approx 30 seconds try again 10x
 *  2)  ...
 *
 ****************************************************************/


/*  Create TCP Connection
    Creates a TCP connection and returns
    returns 1 if socket fails, 2 if connection fails and 0 upon success. */
int CreateTCPConnection(TcpSocket * sock) {
    
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
        // error log
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
int ExchangeTCPMessage(TcpSocket * sock, Message * packet) {
    
    if(send(sock->sockid, packet->outMsg, sizeof(packet->outMsg), 0) == -1){
        // error message
        printf("ERROR: send message failed --> %s   at    %d\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    if(recv(sock->sockid, packet->retMsg, sizeof(packet->retMsg), 0) < 0){
        // Error message
        printf("ERROR: recv message failed --> %s   at    %d\n", __FUNCTION__, __LINE__);
        return 2; // Would like to, at some point, check the global errno that is set
    }
    
    return 0;
}
