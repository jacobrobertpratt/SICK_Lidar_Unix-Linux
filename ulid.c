
//#include "ulid_common.h" // Currently working on error.h

#include "./include/error.h"
#include "./include/util.h"
#include "./include/message.h"

#include <time.h>

// 1) Initialize list to set shared memory loation, config file, lidar name ... etc.

// 2) Split into different processes which utilize a shared memory location
// a. Process (1)   ... to (n) will be for connecting and reading from a Lidar and writing to shared memory
// b. Process (n+1) ... to generate logic, building PCL, and other things
// c. Process (n+2) ... to generate front end application that can be seen by the user.

/*  Input arguments ulid tim551 -sm
 *  -sm <shared memory name>]
 *  -config <file_name>
 *
 */


/*  example: args = ./ulid tim551 <dir/config.txt> */
int main(int argc, char * argv[]) {
    
    Message * msg = message_alloc();
    Message * test = message_alloc();
    
    printf("sizeof test: %lu\n",sizeof(test));
    
    int ret = 0;
    
    ret = message_set(msg, 4, test);
    
    uliderror(ret);
    
    
    
    message_free(test);
    message_free(msg);
    
    
    return 0;
}

