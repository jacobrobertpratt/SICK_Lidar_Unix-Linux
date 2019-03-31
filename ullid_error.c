/*
 */

#include "ullid_error.h"

void logError(const char * error_msg, const char * file, int line) {
    
    if(!error_log_file)
        error_log_file = fopen("./ErrorLog.txt","w");
    
    if(!error_log_file)
        exit(1);
    
    // print_error is false unless set in the arguments
    if(print_error == true)
        printf("ERROR: %s in %s @ %d\n", error_msg, file, line);
    
    fprintf(error_log_file, "ERROR: %s in %s @ %d\n", error_msg, file, line);
    
    exit(1);
}
