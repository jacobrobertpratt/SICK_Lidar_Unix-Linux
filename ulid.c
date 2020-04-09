
//#include "include/sopas.h"

#include "include/common.h"
#include "include/sopas.h"
#include "include/uframe.h"

int main(int argc, char * argv[]) {
    
    uFrame frame;
    
    // GENERAL STRUCTURE OF PROGRAM
    Sopas * sopas = sopas_alloc();
    
    // sign-in
    
    socket_setIP(sopas->sock, "192.168.0.2");
    socket_setPort(sopas->sock, 2112);
    socket_connect(sopas->sock);
    
    uframe_init(&frame, 2160, 1080, 32);
    
    // get telegram
    Telegram * tele = telegram_alloc();
    
    if(sopas_scanOnce(sopas, tele))
        printf("scanOnce failed\n");
    
    uframe_buildFrame(&frame,tele,TELEGRAM_STRUCT_CODE);
    if(frame.data)
        printf("frame data allocted\n");
    
    uframe_reset(&frame);
    if(!frame.data)
        printf("frame data freed\n");
    
    // Scan
    sopas_scanOnce(sopas, tele);
    
    // free allocated structs
    telegram_free(&tele);
    sopas_free(&sopas);
     
    
    /* Work in progress
        Lidar * lidar = lidar_alloc();
        lidar_free(lidar);
    */
    
    /*
    // GENERAL STRUCTURE OF PROGRAM
    Sopas * sopas = sopas_alloc();
    
    // sign-in
    
    socket_setIP(sopas->sock, "192.168.0.2");
    socket_setPort(sopas->sock, 2112);
    socket_connect(sopas->sock);
    
    // get telegram
    Telegram * tele = telegram_alloc();
    
    // Scan
    sopas_scanOnce(sopas, tele);
    
    // free allocated structs
    telegram_free(&tele);
    sopas_free(&sopas);
    */
    return 0;
}

