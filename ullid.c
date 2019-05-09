
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
    
    // 02 73 4D 4E 20 53 65 74 41 63 63 65 73 73 4D 6F 64 65 20 30 33 20 46 34 37 32 34 37 34 34 03
    // 02 73 4D 4E 20 53 65 74 41 63 63 65 73 73 4D 6F 64 65 20 30 33 20 46 34 37 32 34 37 34 34 03
    
    char * str = telegramBuilder(sMN,SetAccessMode,"client", "F4724744");
    printf("Output1: %s\n", str);
    printf("Output: ");
    for(i = 0; i < 31; i++){
        printf(" %2X",str[i]);
    }
    printf("\n");
    free(str);
    
    return 0;
}
