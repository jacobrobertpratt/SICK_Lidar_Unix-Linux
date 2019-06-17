#ifndef __ULLID_CONNECTION_TCP__
#define __ULLID_CONNECTION_TCP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*  */
typedef struct {
    int sockid, port;
    struct sockaddr_in addr;
    char * ip;
} TcpSocket;

/*  */
int CreateTCPConnection(TcpSocket * sock);

/*  */
int DestroyTCPConnection(TcpSocket * sock);

/*  */
int TCPMessage(TcpSocket * sock, char * sendMsg, char * recvMsg);

#endif
