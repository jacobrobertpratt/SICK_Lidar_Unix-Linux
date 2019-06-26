
#include "ulid_common.h"

int main(int argc, char * argv[]) {
    
    // Assume config file is generated and ready to go ...
    
    Lidar lidar;
    InitializeLidarDevice(&lidar,TIM551);
    
    char * outMsg = SOPAS_EncodeMessage(&lidar,METHOD,LOGIN);
    
    printf("outMsg: %s\n",outMsg);
    free(outMsg);
    
    
    // 1) Initialize list to set shared memory loation, config file, lidar name ... etc.
    
    // 2) Split into different processes which utilize a shared memory location
        // a. Process (1)   ... to (n) will be for connecting and reading from a Lidar and writing to shared memory
        // b. Process (n+1) ... to generate logic, building PCL, and other things
        // c. Process (n+2) ... to generate front end application that can be seen by the user.
    
    
    
    return 0;
}

