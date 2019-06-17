#ifndef _ULLID_ERROR_HEADER
#define _ULLID_ERROR_HEADER

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
} ErrorLog;

/*  CreateErrorLog
    Creates the directory and error log file.
    Saves important information to ErrorLog struct.
 Returns: <not yet documented >*/
int CreateErrorLog(ErrorLog * log, const char * directory, const char * name);

/*  DestroyErrorLog
    */
int DestroyErrorLog(ErrorLog * log);

/* LogError */
int LogError(ErrorLog * log, const char * msg, const char * file, int line);

/* PrintErrorLog */
void PrintErrorLog(ErrorLog * log);

#endif
