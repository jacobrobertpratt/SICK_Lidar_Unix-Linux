#include <time.h>

#include "./include/error.h"
#include "./include/util.h"
#include "./include/message.h"
#include "./include/socket.h"
#include "ulid_common.h"

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

struct tmp_t {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
} ;


int main(int argc, char * argv[]) {
    
    
    return 0;
}

