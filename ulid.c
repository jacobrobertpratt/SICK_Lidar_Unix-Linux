#include <stdio.h>

#include "ulid_lidar.h"
#include "ulid_sopas_comm.h"

int main(int argc, char * argv[]) {
    
    lidar_t one;
    InitializeLidarDevice(&one,TIM551);
    
    SOPAS_ReadScanConfig(one.sock.sockid);
    
    DestroyLidarDevice(&one);
    
    return 0;
}

