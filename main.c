#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>  // Error reporting
#include <unistd.h> // To close the socket

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argv, char * argc[]) {
    
    int clientSocket;                                                                       /*---- ClientScoket is this personal clients socket.  ----*/
    
    int port_number;                                                                        /*---- Port_number is the port number that is changed for this specific client  ----*/
    
    char buffer[1024];                                                                      /*---- Buffer is an input buffer  ----*/
    
    struct sockaddr_in serverAddr;                                                          /*---- removes the '\n' since it will  ----*/
    
    port_number = 2111;
    
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);                                         /*---- generates the socket ----*/
    serverAddr.sin_family = AF_INET;                                                        /*---- Specifies that we want to use TCP connection thingy ----*/
    serverAddr.sin_port = htons(port_number);                                               /*---- sets the port number ----*/
    serverAddr.sin_addr.s_addr = inet_addr("192.168.0.3");                                  /*---- sets the host to be local --> this is not set by the argument list above  ----*/
    
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    
    if(connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0) {    /*---- Connect the socket to the server using the address struct  ----*/
        perror("ERROR");
        exit(1);
    } else {
        printf("connected to the socket");
    }
    
    while(1) {                                                                              /*---- loop repeats the receive / send of the client ----*/
        
        send(clientSocket, buffer, sizeof(buffer), 0);
        bzero(buffer, sizeof(buffer));
        
        char rec_buffer[1048576];                                                           /*---- a buffer that is set empty to recieve the message from the client ----*/
        
        if(recv(clientSocket, rec_buffer, sizeof(rec_buffer), 0) < 0){                      /*---- recieves the socket connection message and sets it to buffer ----*/
            perror("recv");                                                                 /*---- prints a standar output ----*/
            break;
        } else {
            printf("Server: %s\n", rec_buffer);
            bzero(rec_buffer, sizeof(rec_buffer));                                          /*---- zeros the buffer if successful ----*/
        }
    }
    close(clientSocket);                                                                    /*---- closes the socket when client exits main loop ----*/
    
    return 0;
}
