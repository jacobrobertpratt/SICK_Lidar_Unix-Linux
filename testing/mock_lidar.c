
// Standard
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Socket
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>

// Local
#include "../include/common.h"

// Create an exact response image from the TIM551 lidar
const char * mock_lidar_message = "sRA LMDscandata 1 1 F510AB 0 0 5932 5933 5B87697D 5B88808C 0 0 1 0 0 5DC 36 0 1 DIST1 3F800000 00000000 FFF92230 2710 10F 292 290 28D 291 290 28F 27B 269 28B 28D 28C 28E 28E 28F 28E 290 290 293 298 299 297 294 29B 298 2A2 29B 1F3 191 191 19E 195 19F 234 2C0 2D0 2CD 2D5 2D5 2E6 2F0 2F6 2F6 300 310 2BA 2B6 2C4 2D6 2E7 2F2 2F7 2FA 303 30D 319 333 347 356 361 371 388 39E 3A5 3C1 388 1C6 19C 19F 1A9 1A4 1A8 1A0 4C7 510 537 56A 5A4 5DB 62C 66F 6C2 72D 785 7FD 895 973 92E 938 928 91F 917 911 916 956 A90 0 B79 B55 BAA BC5 AE2 B3B B84 BC3 BCE BD2 868 77F 6B9 6C1 6C6 6D5 6DB 6E5 6F3 6ED 6FB 706 70F 719 72E 738 746 751 75B 770 77B 792 7A3 7B1 7D3 7E2 7F6 811 822 83E 847 876 F16 84A E73 644 CCC 569 B90 B91 BD0 CCD D26 CF8 CCA CA1 C71 C49 C25 BFF BCC BA3 BD3 D23 E4B 1724 17E7 18C1 19A9 1265 1250 1232 1212 11F1 11D4 11B8 1195 125F 1391 14E2 1669 1868 199D 1995 197C 196D 1961 1955 1898 95E 956 957 95F 95E 953 95C 956 95B 963 91F 865 6A4 5F8 513 50C 4F 8E B0 B5 BE CA CC D1 D3 D4 DB CE D2 D5 D2 D4 D4 CD D9 DE D1 CF D7 D3 CD D2 D4 D4 D3 C6 B1 9D 94 0 0 370 367 346 223 221 225 224 26D 317 30E 30A 303 2F5 2ED 2D1 2CC 2D7 2D1 233 298 2BF 2B6 2AF 2AC 2A9 2A5 29E 2A0 299 296 292 294 28E 289 289 1 RSSI1 3F800000 00000000 FFF92230 2710 10F E6 E6 E6 E6 E6 E6 C3 B0 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E1 E6 DB E6 D8 BD C3 C3 CB C8 C0 95 D8 E6 DB DE DB E6 E6 E6 DB E1 E6 D3 D0 CB C8 C8 D8 D6 D3 D0 D3 C8 C6 C0 CE C8 C6 C8 C8 BB C0 A5 9A B0 CB CE CB CB";

char * getReturnMessage(const char * msg) {
    
    if(!msg)
        return NULL;
    
    
    
    return NULL;
}


int main( int argc, char *argv[] ) {
    
    int stat;
    int serverSock;
    int clientSock;
    char buffer[1024];
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    int flags, ret;
    
    struct timeval sock_delay;
    sock_delay.tv_sec = 1; // 1 seconds
    
    socklen_t addr_size;
    
    serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSock < 0) {
        printf("Error in server socket\n");
        exit(1);
    }
    
    
    // Get the flags for the server socket
    flags = fcntl(serverSock, F_GETFL);
    if(flags < 0){
        ERRMSG("failed to get the flags for server socket\n");
        exit(1);
    }
    
    // Set the socket to non-blocking
    if(fcntl(serverSock, F_SETFL, flags | O_NONBLOCK) < 0) {
        ERRMSG("count no set serverSock to non-blocking\n");
        exit(1);
    }
    
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9999);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    
    bind(serverSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    if(listen(serverSock, 5) == 0)
        printf("listening ... \n\n");
    else
        printf("Error in binding server side. \n");
    
    signal(SIGCHLD, SIG_IGN);
    
    while(1) {
            
        addr_size = sizeof serverStorage;
        clientSock = accept(serverSock, (struct sockaddr *) &serverStorage, &addr_size);
        if(clientSock < 0) {
            if (errno == EWOULDBLOCK) {
              printf("No pending connections sleeping 2 second ...\n");
              sleep(3);
            } else {
              perror("error when accepting connection");
              exit(1);
            }
        }
        
        pid_t child_pid, parent_pid;
        
        if((child_pid = fork()) == 0) {
            
            fpurge(stdout);
            fpurge(stdin);
            
            char * out_msg = NULL;
            
            // wait for a message from client
            ret = recv(clientSock, buffer, sizeof(buffer), 0);
            if(ret < 0){
                printf("child: nothing recieved\n");
            } else {
                
                int send_msg = 0, send_len = 0;
                
                // Add mock messages here ... helper functions
                if(!strcmp(buffer, "\2sRN LMDscandata\3")) {
                    send_len = strlen(mock_lidar_message);
                    out_msg = (char*)malloc(send_len + 1);
                    if(!out_msg){
                        ERRMSG("failed to allocate space for mock lidar message");
                    }
                    strcpy(out_msg,mock_lidar_message);
                    send_msg = 1;
                }
                
                printf("send_len: %d\n", send_len);
                
                // Sends a message to the client
                if(send_msg) {
                    ret = send(clientSock, out_msg, send_len, 0);
                    printf("message sent: %d\n", ret);
                }
                
            }
            
            // Zero buffers after all is sent and recieved
            bzero(buffer, sizeof(buffer));
            
            if(out_msg)
                free(out_msg);
        }
        
        while ((parent_pid = waitpid(-1, &stat, WNOHANG)) < 0)
            ;
        // back in parent process
        if(stat < 0){
            ERRMSG("failed to successfully wait for child process");
            exit(1);
        }
        
    }
        
    close(clientSock);
    close(serverSock);
    
    return 0;
}

