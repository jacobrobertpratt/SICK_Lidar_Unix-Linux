
#include "../include/socket.h"

Socket * socket_alloc() {
    
    Socket * sock = (Socket *) malloc(sizeof(Socket));
    if(!sock) {
        uliderror(errno);
        return NULL;
    }
    
    sock->sockid = 0;
    
    sock->port = 0;
    
    sock->ip = NULL;
        
    sock->type = TCP;
    
    sock->struct_code = SOCKET_STRUCT_CODE;
    
    sock->connected = false;
    
    return sock;
}

int socket_free(Socket * sock) {
    
    if(!sock) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    if(sock->struct_code != SOCKET_STRUCT_CODE) {
        uliderror(ERROR_STRUCTCODE);
        return ERROR_STRUCTCODE;
    }
    
    // close and disconnect the socket
    if(sock->connected)
        socket_disconnect(sock);
    
    // Clear the buffer of ip if it's allocated
    if(sock->ip)
        free(sock->ip);
    
    // This also free's the sockaddr_in struct
    free(sock);
    
    return 0;
}

int socket_setIP(Socket * sock, const char * address)
{
    if(!sock)
        return ERROR_TYPENULL;
    
    if(strlen(address) > 15 || strlen(address) < 7) {
        uliderror(ERROR_SOCKIP);
        return ERROR_SOCKIP;
    }
    
    sock->ip = strdup(address);
    
    return 0;
}

int socket_setPort(Socket * sock, int port) {
    
    /* Checks if the socket is not allocated */
    if(!sock) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    /* Checks if valid port number */
    if(port > 9999 || port <= 0) {
        uliderror(ERROR_SOCKPORT);
        return ERROR_SOCKPORT;
    }
    
    sock->port = port;
    
    return 0;
}

int socket_setType(Socket * sock, enum SOCK_TYPE type) {
    
    if(!sock) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    sock->type = type;
    
    return 0;
}

/* Static method that connects to a tcp connection. Does not check if ip, port, or addr structs
    are allocated, this must be done in the host function socket_connect. */
static int socket_connect_TCP(Socket * sock) {
    
    // Create a socket
    sock->sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock->sockid < 0){
        uliderror(errno);
        return errno;
    }
    
    // Clear the sockaddr_in struct
    memset(&sock->addr, 0, sizeof(sock->addr));
    
    // Set up the structure to connect
    sock->addr.sin_family = AF_INET;
    sock->addr.sin_port = htons(sock->port);
    sock->addr.sin_addr.s_addr = inet_addr(sock->ip);
    
    // Connect socket to the Lidar
    if(connect(sock->sockid, (struct sockaddr *)(&sock->addr), sizeof(sock->addr)) < 0) {
        uliderror(errno);
        return errno;
    }
    
    return 0;
}

// NOT YET IMPLEMENTED
static int socket_connect_UDP(Socket * sock) {
    // remove once this function is implemented
    uliderror(ERROR_IMPLEMENTED);
    return ERROR_IMPLEMENTED;
}


// NOT YET IMPLEMENTED
static int socket_connect_ICMP(Socket * sock) {
    // remove once this function is implemented
    uliderror(ERROR_IMPLEMENTED);
    return ERROR_IMPLEMENTED;
}

int socket_disconnect(Socket * sock) {
    
    if(!sock->sockid)
        close(sock->sockid);
    
    sock->connected = false;
    
    return 0;
}

int socket_connect(Socket * sock) {
    
    int ret = 0;
    
    /* Checks if the socket is not allocated */
    if (!sock) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    /* Check if ip address is set. */
    if(!strlen(sock->ip)) {
        uliderror(ERROR_SOCKIP);
        return ERROR_SOCKIP;
    }
    
    /* Check if the port number is set. */
    if(sock->port <= 0) {
        uliderror(ERROR_SOCKPORT);
        return ERROR_SOCKPORT;
    }
    
    // If socket is already connected closes previous connection.
    if(sock->sockid) {
        socket_disconnect(sock);
    }
    
    // Call to connect with TCP
    if(sock->type == TCP) {
        ret = socket_connect_TCP(sock);
        if(ret) {
            uliderror(ret);
            return ret;
        }
    }
    
    // Connect UDP --> not yet implemented
    if(sock->type == UDP) {
        ret = socket_connect_UDP(sock);
        if(ret) {
            uliderror(ret);
            return ret;
        }
    }
    
    // Connect with whatever this is --> not yet implemented
    if(sock->type == ICMP) {
        ret = socket_connect_ICMP(sock);
        if(ret) {
            uliderror(ret);
            return ret;
        }
    }
    
    sock->connected = true;
    
    return 0;
}

int socket_exchange(Socket * sock, char * msg, char ** ret) {
    
    char buff[RET_BUFF_SIZE];
    
    if(!sock || !msg) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    // check if there is a connection
    if(!sock->connected) {
        uliderror(ERROR_SOCKCONNECT);
        return ERROR_SOCKCONNECT;
    }
    
    // Delete the previous message
    if(*ret)
        free(*ret);
    *ret = NULL;
    
    // Send message
    if(send(sock->sockid, msg, strlen(msg), 0) < 0){
        uliderror(errno);
        return errno;
    }
    
    // Get back message and build
    int len = 0, total = 0;
    while(1) {
        len = recv(sock->sockid, buff, RET_BUFF_SIZE, 0);
        if(len < 0) {
            if(*ret)
                free(*ret);
            uliderror(errno);
            return errno;
        }
        total += len;
        *ret = (char*) realloc(*ret, total + 1);
        if(!*ret) {
            if(*ret)
                free(*ret);
            uliderror(errno);
            return errno;
        }
        
        strncat(*ret,buff,len);
        if(len < RET_BUFF_SIZE)
            break;
    }
    
    return 0;
}

/*
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
}*/
