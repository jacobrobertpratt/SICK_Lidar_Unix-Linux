
//#include "ulid_common.h" // Currently working on error.h

#include "./include/error.h"
#include "./include/util.h"

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
    
    ErrorLog * log;
    log = errorlog_alloc();
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    
    char str[100];
    getYYYYMMDDString(str);
    
    
    
    errorlog_free(log);
    
    return 0;
}

