
#ifndef ULID_ERROR_H
#define ULID_ERROR_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/util.h"


/**
 * Error message definitions specific to the ULID library.
 */
#define ERROR_MSGNULL  103     // If a message is NULL but it shouldn't be.


/**
 * Represents an error log that can be passed to different error log functions
 * either to open or log something.
 */
typedef struct errorLog_t {
    
    // the full path file name
    char * filename;
    
} ErrorLog;

/**
 * Allocates an ErrorLog struct. The resultant struct must be freed using
 * errorlog_free(ErrorLog * log) function.
 * @param none
 * @return ErrorLog structure or NULL on failure.
 */
ErrorLog * errorlog_alloc();

/**
 * Free's an error log struct that has alrready been allocated. 
 * @param log an ErrorLog struct
 * @return 0 on success, 1 on failure.
 */
int errorlog_free(ErrorLog * log);

/**
 * Creates an error log that can be saved the the desitnation specified in
 * in the parameters. The log will be marked with the date and time the operation happened.
 * If directory is set to NULL, the log file will locate to the current file directory.
 * @param log is the  ErrorLog structue
 * @param directory log file destination. This can be set to NULL.
 * @return 0 on success, 1 on failure.
 */
int errorlog_create(ErrorLog * log, const char * directory);

/**
 * Writes to an already created error-log. If the error log struct does not have a valid log already
 * created, then it will make a call to create an error log with the date as the file name and the directory (not yet implemented)
 * will be the current directory the executable is running in.
 * @param log is the ErrorLog structure
 * @param msg is a constant
 * @return 0 on success or 1 on failure.
 */
int errorlog_log(ErrorLog * log, const char * msg);

/**
 * Gives the pointer to a already defined string value representing the error.
 * All error numbers are defined at the top of error.h (above)
 * @param errnum is a global error number (int) that is defined in error.h
 * @return (char *) of the string, or NULL on failure.
 */
char * errorstr(int errnum);

/**
 * Function will print the provided global integer message to the terminal. If a message
 * is added to the input paramters, then the messaged is tacked on to the end of the input
 * message. Else, if the message paramters is NULL, the message ignores it.
 * @param errnum global error number
 * @param message to add to the standard error message
 * @return 0 on success, 1 on failure.
 */
int printError(int errnum, const char * file, int line);





/**
 * Macro that prints the error message to the terminal. 
 *
 * The general format will be:
 * [<function name> @ <line number> ] Error: <error message here>
 */
#define uliderror(a) printError(a, __FILE__, __LINE__)





#endif
