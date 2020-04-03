
#ifndef _ULID_ERROR_H_
#define _ULID_ERROR_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/**
 * Error message definitions specific to the ULID library.
 */
#define ERROR_TYPENULL      103     //
#define ERROR_NEGVAL        104     //
#define ERROR_STRING        105     //
#define ERROR_OPEN          106     //
#define ERROR_SIZE          107     //
#define ERROR_DATA          108     //
#define ERROR_TYPEDATA      109     //
#define ERROR_IMPLEMENTED   110     //
#define ERROR_MEMREF        111     //
#define ERROR_REPDATA       112     //
#define ERROR_LIMIT         113     //
#define ERROR_STRUCTCODE    114     //
#define ERROR_SOCKCONNECT   115     //
#define ERROR_SOCKIP        116     //
#define ERROR_SOCKPORT      117     //
#define ERROR_SOCKMSG       118     //
#define ERROR_RETMSG        119     //
#define ERROR_REPLACE       120     //
#define ERROR_TYPE          121     //


#define MAX_ERR_NUM     (sizeof(errorArray) / 8) + 102
#define ERROR_STRUCT_CODE   0x0000

/**
 * Represents an error log that can be passed to different error log functions
 * either to open or log something.
 */
typedef struct ulid_error_t {
    /* Call sign of this structure for identification purposes */
    int struct_code;
} Error;

/**
 * Gives the pointer to a already defined string value representing the error.
 * All error numbers are defined at the top of error.h (above)
 * @param errnum is a global error number (int) that is defined in error.h
 * @return (char *) of the string, or NULL on failure.
 */
char * error_getString(int errnum);

/**
 * Function will print the provided global integer message to the terminal. If a message
 * is added to the input paramters, then the messaged is tacked on to the end of the input
 * message. Else, if the message paramters is NULL, the message ignores it.
 * @param errnum global error number
 * @param message to add to the standard error message
 * @return 0 on success, 1 on failure.
 */
int error_print(int errnum, const char * file, int line);

/**
 * Macro that prints the error message to the terminal. 
 *
 * The general format will be:
 * [<function name> @ <line number> ] Error: <error message here>
 */
#define uliderror(a) error_print(a, &(strrchr(__FILE__,'/')[1]), __LINE__)





#endif
