
#include "../include/lidar.h"

Lidar * lidar_alloc() {
    
    // Allocate memory for this structure
    Lidar * lidar = (Lidar *) malloc(sizeof(Lidar));
    if(!lidar) {
        uliderror(errno);
        return NULL;
    }
    
    // Assign the call-sign of this structure
    lidar->struct_code = LIDAR_STRUCT_CODE;
    
    // User level --> init to zero
    lidar->level = 0;
    
    // Zero out password buffer
    memset(lidar->password,0,sizeof(lidar->password));
    
    // Allocate Socket structure
    lidar->sock = socket_alloc();
    
    return lidar;
}

int lidar_free(Lidar * lidar) {
    
    if(!lidar) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    if(lidar->struct_code != LIDAR_STRUCT_CODE) {
        uliderror(ERROR_STRUCTCODE);
        return ERROR_STRUCTCODE;
    }
    
    if(lidar->sock)
        socket_free(lidar->sock);
    
    free(lidar);
    
    return 0;
}
