
/*  STANDARD INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <string.h>

/*  LOCAL INCLUDEDS */
#include "ullid.h"
#include "ullid_error.h"
#include "ullid_comm_format.h"
#include "LMS1XX.h"

int main(int argc, char * argv[]) {
    
    Lidar lidar;
    
    int i;  // Used strictly for loops --> must always be initialized to zero
    print_error = false; // initialize this to false.
    
    // Started at 1 since starting the prog. auto makes argc == 1
    for(i = 1; i < argc; i++) {
        
        // Sets the device to LMS511
        if(strcmp(argv[i],"LMS511") == 0) {
            lidar.name = argv[i];
            // TODO --> trigger the LMS511 Methods, variables, ... etc.
        }
        
        // Sets the values so that we print on the terminal the errors
        if(strcmp(argv[i],"-print_errors") == 0 || strcmp(argv[i],"--perr") == 0) {
            print_error = true;
        }
        
    }
    
    
    char * str = telegramBuilder(sMN,SetAccessMode,"hello");
    printf("output: %s\n", str);
    free(str);
    
    return 0;
}
