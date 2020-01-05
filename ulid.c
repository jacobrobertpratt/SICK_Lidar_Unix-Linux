#include <time.h>

#include "include/common.h"
#include "include/qnode.h"
#include "include/fifo.h"
#include "include/message.h"
#include "include/error.h"

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


int main(int argc, char * argv[]) {
    
    printf("%s\n",error_getString(115));
    
    
    return 0;
}

