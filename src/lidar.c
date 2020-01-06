
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
    
    // Could stay NULL depending on the lidar used.
    lidar->sopas = sopas_alloc();
    
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
    
    if(lidar->sopas)
        sopas_free(lidar->sopas);
    
    free(lidar);
    
    return 0;
}
