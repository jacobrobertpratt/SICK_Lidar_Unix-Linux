#ifndef __ULID_TCP_CONNECTION__
#define __ULID_TCP_CONNECTION__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


typedef struct {
    int sockid, port;
    struct sockaddr_in addr;
    char ip[16];
} tcp_socket_t;

/*  */
int CreateTCPConnection(tcp_socket_t * sock);

/*  */
int DestroyTCPConnection(tcp_socket_t * sock);


#endif
