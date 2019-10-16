
#include "../include/error.h"

static char * errorArray[] = {
    "message was null pointer"
};

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

char * errorstr(int errnum) {
    
    char * retStr = NULL;
    
    //printf("sizeof errorArray: %lu\n",sizeof(errorArray));
    
    // Gets the maximum value of the possible errornum
    int max_errnum = (sizeof(errorArray) / 8) + 102;
    if(errnum > max_errnum)
        return NULL;
    
    // checks if standard errno number or local error number
    if(errnum < 103)
        retStr = strerror(errnum);
    else {
        errnum = errnum - 103;
        retStr = errorArray[errnum];
    }
    
    return retStr;
}

int printError(int errnum, const char * file, int line) {
    
    char * err_str = NULL;
    int ret = 0;
    
    // Get the error string
    err_str = errorstr(errnum);
    if(err_str == NULL)
        printf("[%s @ %d] Error: invalide error code\n",file,line);
    else
        printf("[%s @ %d] Error: %s\n",file,line,err_str);
    
    return ret;
}
