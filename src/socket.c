
#include "../include/socket.h"

Socket * socket_alloc() {
    Socket * sock = (Socket *) malloc(sizeof(Socket));
    if(!sock) {
        uliderror(errno);
        return NULL;
    }
    
    sock->sockid = 0;
    sock->port = 0;
    sock->type = TCP;
    
    return sock;
}

int socket_free(Socket * sock) {
    
    if(!sock) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    // must check to ensure socket is closed
    if(sock->sockid)
        close(sock->sockid);
    
    // This also free's the sockaddr_in struct
    free(sock);
    return 0;
}

int socket_setIP(Socket * sock, const char * address)
{
    if(strlen(address) > 15 || strlen(address) < 7) {
        uliderror(ERROR_STRING);
        return ERROR_STRING;
    }
    
    // Copy string to
    strcpy(sock->ip,address);
    return 0;
}

int socket_setPort(Socket * sock, const char * port) {
    
    /* Checks if the socket is not allocated */
    if(!sock) {
        uliderror(ERROR_TYPENULL);
    }
    
    /* Checks if valid port number */
    if(strlen(port) > 4 || strlen(port) == 0) {
        uliderror(ERROR_STRING);
        return ERROR_STRING;
    }
    
    int port_num = atoi(port);
    sock->port = port_num;
    
    return 0;
}

int socket_setType(Socket * sock, int type) {
    
    if(!sock) {
        uliderror(ERROR_STRING);
        return ERROR_TYPENULL;
    }
    
    sock->type = type;
    
    return 0;
}

static int socket_connect_tcp(Socket * sock) {
    
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

int socket_connect(Socket * sock) {
    
    /* Checks if the socket is not allocated */
    if (!sock) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    /* If socket is already connected throws error
       and closes previous connection. */
    if(sock->sockid) {
        // TODO ...
    }
    
    if(sock->type == TCP)
        socket_connect_tcp(sock);
    
    // Add other connection types of sockets here ... right now we only use TCP
    
    return 0;
}

int socket_disconnect(Socket * sock) {
    if(!sock->sockid)
        close(sock->sockid);
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
