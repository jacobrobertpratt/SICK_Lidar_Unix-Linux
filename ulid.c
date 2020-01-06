#include <time.h>

#include "include/sopas.h"
#include "include/socket.h"
#include "include/error.h"

int main(int argc, char * argv[]) {
    
    Socket * sock = socket_alloc();
    
    socket_setIP(sock,"192.168.0.2");
    socket_setPort(sock,2112);
    socket_connect(sock);
    
    char str[32];
    sprintf(str,"\2sRN LMDscandata\3");
    printf("str: %s\n", str);
    
    char * retmsg = NULL;
    int ret = socket_exchange(sock, str, &retmsg);
    if(ret)
        uliderror(ret);
    
    if(retmsg)
        free(retmsg);
    
    socket_free(sock);
    
    return 0;
}

