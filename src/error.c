
#include "../include/error.h"

static char * errorArray[] = {
    "input data type was null pointer",
    "negative values are not accepted as inputs",
    "incorrect string value entered",
    "unable to open the given address",
    "size value is not correct",
    "data value is not correct",
    "data type is not correct",
    "function not yet implemented",
    "cannot free could lose data memory reference",
    "attempting to replace already allocated data without freeing the origional data",
    "limit for data input has been reached",
    "incorrect structure being passed to function",
    "socket is not connected",
    "socket IP address is not set or is incorrect",
    "socket Port number is not set or is incorrect",
    "socket failed to exchange message",
    "lidar device returned incorrect message",
    "attempting to replace an already set variable or structure",
    "type assignment is unknown or not accepted"
};

char * error_getString(int errnum) {
    
    char * retStr = NULL;
    
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
        printf("[%s@%d] Error: invalide error code: - \n", file, line);
    else
        printf("[%s@%d] Error: %s: %d\n",file,line,err_str,errnum);
    return ret;
}
