
#include "../include/error.h"

static char * errorArray[] = {
    "message was null pointer",
    "negative values are not accepted as inputs",
    "Incorrect string value entered",
    "unable to open the given address",
    "size value is not correct",
    "data value is not correct",
    "data type is not correct",
    "function not yet implemented"
};

char * error_getString(int errnum) {
    
    char * retStr = NULL;
    
    //printf("sizeof errorArray: %lu\n",sizeof(errorArray));
    
    // Gets the maximum value of the possible errornum
    int max_errnum = MAX_ERR_NUM;
    
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

int error_print(int errnum, const char * file, int line) {
    char * err_str = NULL;
    int ret = 0;
    err_str = error_getString(errnum);
    if(!err_str)
        printf("[%s @ %d] Error: invalide error code: - \n", file, line);
    else
        printf("[%s @ %d] Error: %s: %d\n",file,line,err_str,errnum);
    return ret;
}
