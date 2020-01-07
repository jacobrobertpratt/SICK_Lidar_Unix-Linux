#include <time.h>

#include "include/sopas.h"
#include "include/socket.h"
#include "include/error.h"
#include "include/util.h"

int main(int argc, char * argv[]) {
    
    Sopas * sopas = sopas_alloc();
    
    socket_setIP(sopas->sock,"192.168.0.2");
    socket_setPort(sopas->sock,2112);
    socket_connect(sopas->sock);
    
    sopas_scanOne(sopas);
    
    sopas_free(sopas);
    
    /*
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
    
    printf("%s\n", retmsg);

    int cnt = countTokens(retmsg,' ');
    printf("cnt: %d\n", cnt);
    
    char * arr[cnt];
    
    printf("size arr: %d\n", sizeof(arr));
    
    if(retmsg)
        free(retmsg);
    
    socket_free(sock);
     */
    
    return 0;
}

