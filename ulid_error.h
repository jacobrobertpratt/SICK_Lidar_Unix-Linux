#ifndef _ULLID_ERROR__
#define _ULLID_ERROR__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <unistd.h>

/* ErrorLog */
typedef struct ErrorLog {
    FILE * file;
    char * path;
    int count;
} error_log_t;

/*  CreateErrorLog
    Creates the directory and error log file.
    Saves important information to ErrorLog struct.
 Returns: <not yet documented >*/
int CreateErrorLog(error_log_t * log, const char * directory, const char * name);

/*  DestroyErrorLog */
int DestroyErrorLog(error_log_t * log);

/* LogError */
int LogError(error_log_t * log, const char * msg, const char * file, int line);

/* PrintErrorLog */
void PrintErrorLog(error_log_t * log);

#endif
