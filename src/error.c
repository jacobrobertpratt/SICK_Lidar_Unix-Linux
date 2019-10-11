
#include "../include/error.h"

ErrorLog * errorlog_alloc(){
    
    // Allocate main structure memory
    ErrorLog * log = (ErrorLog *) malloc(sizeof(ErrorLog));
    if(!log){
        printf("ERROR: failed to allocate error log struct @ %d\n", __LINE__);
    }
    
    // Set all variables to initial values
    log->filename = NULL;
    
    return log;
    
}

int errorlog_free(ErrorLog * log) {
    
    if(!log)
        return 1; // improvment -> Set global error
    
    // free filename if set
    if(log->filename) {
        free(log->filename);
        log->filename = NULL;
    }
    
    free(log);
    
    return 0;
    
}

int errorlog_create(ErrorLog * log, const char * directory) {
    
    int ret;
    
    if(!log)
        return 1; // improvment -> Set global error
    
    if(log->filename){
        free(log->filename);
        log->filename = NULL;
    }
    
    if(!directory)
        ret = createDir("..","errlog");
    else
        ret = createDir(directory,"errlog");
    
    if(ret){
        printf("error in creating log file");
        return 1;
    }
    
    // Collect date and time data into a string
    
    
    // Build full-file-path string to create file
    
    // Create file, make write able
    
    // Close file
    
    return 0;
    
}
