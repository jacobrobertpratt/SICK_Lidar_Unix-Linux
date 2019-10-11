#include "ulid_common.h"
#include "ulid_tcp_conn.h"

/* ******************* TO IMPROVE ******************************
 *
 *  1)  Work on timeout checks --> approx 30 seconds try again 10x
 *  2)  ...
 *
 * ***************************************************************/


TcpSocket * TCPCreateSocketStruct(){
    TcpSocket * sock = (TcpSocket *) malloc(sizeof(TcpSocket));
    if(sock == NULL){
        printf("ERROR: TcpSocket struct failed to allocate memory in %s at line %d\n", \
               __FILE__, __LINE__);
        return NULL;
    }
    sock->sockid = 0;
    sock->port = 0;
    return sock;
}


int TCPDestroySocket(TcpSocket * sock){
    
    // Check if socket is not empty
    if(sock == NULL){
        printf("ERROR: socket can't be freed --> %s   at   %d\n",__FILE__, __LINE__);
        return 1;
    }
    
    // make sure socket is closed
    if(sock->sockid)
        close(sock->sockid);
    
    // free socket
    free(sock);
    return 0;
}


int TCPSetIPAddress(Lidar * lidar, const char * address) {
    if(strlen(address) > 15)
        printf("ERROR: ip address is too long try again --> %s   at   %d\n",__FUNCTION__, __LINE__);
    strcpy(lidar->tcpSocket->ip,address);
    return 0;
}


int TCPSetPortNumber(Lidar * lidar, const char * number){
    // Add checks to ensure correct port number
    int port_num = atoi(number);
    lidar->tcpSocket->port = port_num;
    return 0;
}


int TCPCreateConnection(TcpSocket * sock) {
    
    // Create a socket
    sock->sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock->sockid < 0){
        // log error
        printf("ERROR: Socket failed to initialize --> %s   @   %d\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    printf("TCP socket created\n");
    
    // Clear the sockaddr_in struct
    memset(&sock->addr, 0, sizeof(sock->addr));
    
    // Set up the structure to connect
    sock->addr.sin_family = AF_INET;
    sock->addr.sin_port = htons(sock->port);
    sock->addr.sin_addr.s_addr = inet_addr(sock->ip);
    
    // Connect socket to the Lidar
    if(connect(sock->sockid, (struct sockaddr *)(&sock->addr), sizeof(sock->addr)) < 0) {
        // error log
        printf("ERROR: Socket failed to connect --> %s   @   %d\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    printf("TCP connection established ... \n");
    
    return 0;
}


int TCPCloseConnection(TcpSocket * sock) {
    if(!sock->sockid)
        close(sock->sockid);
    return 0;
}


int TCPExchangeMessage(TcpSocket * sock, char * sendMsg, char * retMsg) {
    
    // Need to check the strlen of the message not sizeof
    
    // Send the message to the Lidar device
    if(send(sock->sockid, sendMsg, strlen(sendMsg), 0) < 0){
        printf("ERROR: send message failed --> %s   at    %d\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    // need to free the message char * here and then resize depending on ... this is the problem.
    
    if(recv(sock->sockid, retMsg, strlen(retMsg), 0) < 0) {
        printf("ERROR: recv message failed --> %s   at    %d\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    
    return 0;
}
