
#ifndef ULID_ERROR_H
#define ULID_ERROR_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/util.h"

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
 * created, then it will make a call to create an error log with the date as the file name and the directory
 * will be the current directory the executable is running in.
 * @param log is the ErrorLog structure
 * @param msg is a constant
 * @return 0 on success or 1 on failure.
 */
int errorlog_log(ErrorLog * log, const char * msg);



#endif
