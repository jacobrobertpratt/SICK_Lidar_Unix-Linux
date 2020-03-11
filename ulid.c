#include <time.h>

#include "include/sopas.h"
#include "include/socket.h"
#include "include/error.h"
#include "include/util.h"
#include "include/telegram.h"

int main(int argc, char * argv[]) {
    
    // GENERAL STRUCTURE OF PROGRAM
    Sopas * sopas = sopas_alloc();
    
    socket_setIP(sopas->sock, "192.168.0.2");
    socket_setPort(sopas->sock, 2112);
    socket_connect(sopas->sock);
    
    Telegram * tele = telegram_alloc();
    
    sopas_scanOnce(sopas, tele);
    
    telegram_free(&tele);
    
    sopas_free(&sopas);
     
    
    return 0;
}

