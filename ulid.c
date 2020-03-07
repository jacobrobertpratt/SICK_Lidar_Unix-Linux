#include <time.h>

#include "include/sopas.h"
#include "include/socket.h"
#include "include/error.h"
#include "include/util.h"
#include "include/telegram.h"

int main(int argc, char * argv[]) {
    /*
    Sopas * sopas = sopas_alloc();
    
    socket_setIP(sopas->sock, "192.168.0.2");
    socket_setPort(sopas->sock, 2112);
    socket_connect(sopas->sock);
    
    Telegram * tele = telegram_alloc();
    
    sopas_scanOnce(sopas, tele);
    int i;
    for(i = 0; i < tele->data_count; i++) {
        printf("%d) %u\n", i, tele->data[i]);
    }
    
    telegram_free(&tele);
    
    sopas_free(sopas);
     */
    
    Telegram * tele = telegram_alloc();
    
    printf("tele size: %lu\n", sizeof(*tele));
    
    telegram_free(&tele);
     
    
    return 0;
}

