#ifndef _ULLID_ERROR__
#define _ULLID_ERROR__

#include "ulid_common.h"

int (*killProcess_callback)(Lidar*);

/*  CreateErrorLog
    Creates the directory and error log file.
    Saves important information to ErrorLog struct.
 Returns: <not yet documented >*/
int CreateErrorLog(Lidar * lidar);

/*  Sets the destructor path to kill the processes */
void SetKillProcessCallback(int (*callback)(Lidar*));

/*  DestroyErrorLog */
int DestroyErrorLog(Lidar * lidar);

/* LogError */
int LogError(Lidar * lidar, const char * msg, const char * file, int line);

/* PrintErrorLog */
void PrintErrorLog(Lidar * lidar);

#endif
