#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  // Error reporting
#include <unistd.h> // To close the socket

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argv, char * argc[]) {
    
    int clientSocket;
    struct sockaddr_in addr;
    
    // Send buffer
    char buffer[1024];
    bzero(buffer, sizeof(buffer));
    
    // Recv buffer
    char rec_buffer[1024];
    bzero(rec_buffer, sizeof(rec_buffer));
    
    
    // Create a socket
    clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(clientSocket < 0){
        perror("ERROR");
        close(clientSocket);
        return 0;
    }
    
    // Clear the sockaddr_in struct
    memset(&addr, 0, sizeof(addr));             // Zero out structure
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(2112);                // Host-2-Network byte order
    addr.sin_addr.s_addr = inet_addr("192.168.0.2");
    
    if(connect(clientSocket, (struct sockaddr *)(&addr), sizeof(addr)) < 0) {
        perror("ERROR connect: ");
        return 0;
    } else {
        printf("socket connected\n");
    }
    
    strcpy(buffer, "\2sRN LMPscancfg\3");
    printf("send: %s\n", buffer);
    
    send(clientSocket, buffer, sizeof(buffer), 0);
    
    if(recv(clientSocket, rec_buffer, sizeof(rec_buffer), 0) < 0){
        perror("ERROR recv: ");
    } else {
        printf("recv: %s\n", rec_buffer);
        bzero(rec_buffer, sizeof(rec_buffer));
    }
    
    close(clientSocket);
    
    return 0;
}
