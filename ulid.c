
//#include "include/sopas.h"

#include "include/common.h"
#include "include/sopas.h"
#include "include/uframe.h"
#include "include/usave.h"

int main(int argc, char * argv[]) {
    
    
    uint32_t * data = malloc(1080 * 720 * 4 * sizeof(uint8_t));
    uint32_t * strt = data;
    memset(data, 0, 1080 * 720 * sizeof(uint32_t));
    
    data+=100 + 1080 * 100;
    
    uint32_t * row = data;
    int i, j;
    for(j = 100; j < 150; j++){
        for(i = 100; i < 150; i++){
            *data = 0xff00ff00;
            data++;
        }
        row += 1080;
        data = row;
    }
    
    save_frameAsJPEG(strt,1080,720,32,"test",0);
    
    GOTHERE
    
    free(strt);
    /*
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
     */
    
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

