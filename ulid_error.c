
#include "ulid_error.h"





/*  Sets the function that will deallocate memory before the system is forced to shut down. */
void SetKillProcessCallback(int (*callback)(Lidar*)) {
    killProcess_callback = callback;
}

// Create Log
int CreateErrorLog(Lidar * lidar) {
    
    // current time yyyy_mm_dd format
    time_t rawtime = time(NULL);
    struct tm *ptm = localtime(&rawtime);
    
    // make the directory if it doesn't exist
    mkdir(lidar->errorLog.path, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
    
    // Generate log file name
    sprintf(lidar->errorLog.path,"%s/%s_%04d_%02d_%02d.txt",lidar->errorLog.path,lidar->errorLog.name,(1900 + ptm->tm_year),ptm->tm_mon,ptm->tm_mday);
    
    // Creates file, unless it already exists.
    lidar->errorLog.file = fopen(lidar->errorLog.path,"a");
    
    // Set count to zero
    lidar->errorLog.count = 0;
    
    return 0;
}

// destroy error log
int DestroyErrorLog(Lidar * lidar) {
    //printf("Entered: %s\n",__FUNCTION__);   // callback test
    fclose(lidar->errorLog.file);
    return 0;
}

// print to error log
int LogError(Lidar * lidar, const char * msg, const char * file, int line) {
    lidar->errorLog.count++;
    // Add in time functionality here
    fprintf(lidar->errorLog.file,"%d. ERROR: %s  -->  file: %s \t line: %d \n",lidar->errorLog.count,msg,file,line);
    killProcess_callback(lidar);
    return 0;
}

void PrintErrorLog(Lidar * lidar) {
    // TODO
}
