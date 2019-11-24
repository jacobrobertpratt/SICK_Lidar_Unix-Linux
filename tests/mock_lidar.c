

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>


int main( int argc, char *argv[] ) {
    
    int stat;
    int serverSock;
    int clientSock;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    
    socklen_t addr_size;
    
    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSock < 0) {
        printf("Error in server socket\n");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9999);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    
    bind(serverSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    
    if(listen(serverSock, 5) == 0)
        printf("Listening ... \n\n");
    else
        printf("Error in binding server side. \n");
    
    pid_t pid;
    
    signal(SIGCHLD, SIG_IGN);
    
    while(1) {
            
            addr_size = sizeof serverStorage;
            clientSock = accept(serverSock, (struct sockaddr *) &serverStorage, &addr_size);
            
            if(clientSock < 0) {
                perror("accept call failed");
                exit(1);
            }
            
            pid_t client_pid;
            
            if((client_pid = fork()) == 0) {
                
                close(serverSock);
                
                printf("client socket recieved ...\n");
                
                fpurge(stdout);
                fpurge(stdin);
                
                while(1) {
                    
                    // wait for a message from client
                    recv(clientSock, buffer, sizeof(buffer), 0);
                    printf("recv: %s\n", buffer); // print message
                    
                    // Add mock messages here ... helper functions
                    
                    // Temp out message
                    char out_msg[1024];
                    bzero(out_msg,sizeof(out_msg));
                    strcpy(out_msg,"this is a return message.");
                    
                    // Sends a message to the client
                    send(clientSock, out_msg, sizeof(out_msg), 0);
                    
                    // Zero buffers after all is sent and recieved
                    bzero(buffer, sizeof(buffer));
                    bzero(out_msg, sizeof(out_msg));
                    
                }
                
            } else {
                while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0) {
                    printf("child %d terminated\n", pid);
                }
            }
            
        }
        
        close(clientSock);
    
    return 0;
}
