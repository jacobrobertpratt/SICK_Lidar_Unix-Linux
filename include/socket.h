#ifndef _ULID_SOCKET_H_
#define _ULID_SOCKET_H_

#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../include/error.h"

enum SocketType{
    STREAM_SOCKET,
    DATAGRAM_SOCKET,
    RAW_SOCKET
};

/**
 *
 */
typedef struct socket_t {
    
    /* Socket identification number as an integer */
    int sockid;
    
    /* Socket port number as an integer */
    int port;
    
    /* Socket address struct native to POSIX systems */
    struct sockaddr_in addr;
    
    /* Socket IP address */
    char ip[16];
    
    /* type of socket */
    enum SocketType type;
    
} Socket;

/**
 * Allocates a socket and sets all internal fields of the socket to NULL or 0. If the
 * memory fails to allocate, the global error variable errno is set, then it will make
 * a call to uliderror(). Must call socket_free(Socket * sock) to free the allocated
 * memory.
 * @return Socket struct pointer on success, or NULL on failure.
 */
Socket * socket_alloc();

/**
 * Frees a Socket structure which was allocated by socket_alloc().
 */
int socket_free(Socket * sock);

/**
 */
int socket_setIP(Socket * sock, const char * address);

/**
 */
int socket_setPort(Socket * sock, const char * port);

/**
 */
int socket_setType(Socket * sock, const enum SocketType type);

/**
 */
int socket_connect(Socket * sock);

/**
 */
int socket_disconnect(Socket * sock);

//int TCPExchangeMessage(TcpSocket * sock, char * sendMsg, char * retMsg);

#endif
