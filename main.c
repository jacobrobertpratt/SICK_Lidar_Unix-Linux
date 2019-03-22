/*  STANDARD INCLUDES */
#include <stdio.h>
#include <string.h>
#include <stdint.h>


/*  LOCAL INCLUDEDS */
#include "common.h"

enum ARG {
    DEFAULT,
    REPORT,
    TEST
};

// NEED TO ADD STANDARD ERROR FILE

static void setLogFile(char* error) {
    //  TODO must implement a file --> standard error message --> macros __DATE__ & __TIME__
}

// get an initialize function to set stuff that is in common.h --> look into how to do this universally

// Also add functionality to check Macros and #define values.

static int setArguments(enum ARG arg) {
    switch(arg) {
        case DEFAULT:
            printf("sick_exe <arg1> <arg1> ... \n");
            break;
        case REPORT:
            args[REPORT] = true;
            break;
        case TEST:
            args[TEST] = true;
            break;
        default:
            printf("ERROR: invalid argument");
            return 1;
    }
    return 0;
}


int main(int argc, char * argv[]) {
    
    //printf("arg: %d\n", argc);
    
    int i;  // Used strictly for loops --> must always be initialized to zero
    
    if(argc == 1) {
        setArguments(DEFAULT);
        return 1; // return 1 for invalid input
    }
    
    // Started at 1 since starting the prog. auto makes argc == 1
    for(i = 1; i < argc; i++) {
        
        if(strcmp(argv[i],"--report") == 0) {
            setArguments(REPORT);
        }
        if(strcmp(argv[i],"--test") == 0) {
            setArguments(TEST);
        }
        
        
        
        
    }
    
    return 0;
}
