
#ifndef _ULID_SOCKET_H_
#define _ULID_SOCKET_H_

#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "common.h"

/** CLASS DEFINITION:
 The socket class represents a socket connection. A socket structure must be allocated to start a socket connection. The given device's IP address, socket type, and port number must be known prior to starting a connection. Similarly, information can be passed back and forth between the device through the sendData and recvData functions. The communication protocols for the give device must be known in advance.
 */

#define SOCKET_STRUCT_CODE  4
#define RET_BUFF_SIZE       1024


enum SOCK_TYPE {
    TCP  = 1,
    UDP  = 2,
    ICMP = 3
};

/**
 * socket_t represents a socket connection and aims to simplify the complexity behind setting up a socket connection. This structure represents a socket connection.
 */
typedef struct socket_t {
    
    /* Socket identification number as an integer */
    int sockid;
    
    /* Socket port number as an integer */
    int port;
    
    /* Socket address struct native to POSIX systems */
    struct sockaddr_in addr;
    
    /* Socket IP address */
    char * ip;
    
    /* type of socket */
    enum SOCK_TYPE type;
    
    /* Call sign of this structure for deallocations purposes. */
    int struct_code;
    
    // boolean is socket is connected or not
    bool connected;
    
} Socket;

/**
 * Allocates a socket and sets all internal fields of the socket to NULL or 0. If the memory fails to allocate, the global error variable errno is set, then it will make a call to uliderror(). Must call socket_free(Socket * sock) to free the allocated memory.
 * @param void
 * @return Socket  pointer on success, or NULL on failure.
 */
Socket * socket_alloc();

/**
 * Frees the memory allocated by socket_alloc(). If the socket is not previously closed, this function will first close the socket and free the IP address.
 * @param sock Socket pointer
 * @return 0 on success or ulid error number of failure
 *      ERROR_TYPENULL if the Socket pointer is NULL
 *      ERROR_STRUCTCODE if the pointer passed is not a Socket structure
 */
int socket_free(Socket * sock);

/**
 * Sets the IP address for the socket. Takes a constant character pointer as an argument. Must follow the standard IP address structure.
 * @param sock Socket pointer
 * @param address const char * representing the IP address
 * @return 0 on success or ulid error number of failure
 *      ERROR_TYPENULL if the Socket pointer is NULL
 *      ERROR_STRUCTCODE if the pointer passed is not a Socket structure
 */
int socket_setIP(Socket * sock, const char * address);

/**
 * Sets the port number. This must be an integer between 0 and 9999.
 * @param sock Socket pointer
 * @param port integer between 0 and 9999
 * @return 0 on success or ulid error number of failure
 *      ERROR_TYPENULL if the Socket pointer is NULL
 *      ERROR_SIZE if the port number is incorrect
 */
int socket_setPort(Socket * sock, int port);

/**
 * Sets the type of socket to be used. This can be TCP, UDP, or TCMP as available in the SOCK_TYPE enum located at the start of this class. The standard type is TCP and is set when the Socket pointer is allocated.
 * @param sock Socket pointer
 * @param type enum SOCK_TYPE  { TCP,  UDP,  TCMP }
 * @return 0 on success or ulid error number of failure
 *      ERROR_TYPENULL if the Socket pointer is NULL
 */
int socket_setType(Socket * sock, enum SOCK_TYPE type);

/**
 * Disconnects the socket by closing the connection. This function is still being improved.
 * @param sock Socket  pointer
 * @return 0 on success or ulid error number of failure
 *      ERROR_TYPENULL if the Socket pointer is NULL
 */
int socket_disconnect(Socket * sock);

/**
 * Establishes a connection with the socket. If the incorrect settings are established, then the socket connection function will fail. Port, IP, and appropriate allocations must be done first. This function is still being improved.
 * @param sock Socket pointer
 * @return 0 on success or ulid error number of failure
 *      ERROR_TYPENULL if the Socket pointer is NULL
 */
int socket_connect(Socket * sock);


// returns 0 on success or error number on failure. --> need to build tests
int socket_exchange(Socket * sock, char * msg, char ** size);



#endif
