#include <string.h>

#include "ullid_error.h"

// Create Log
int CreateErrorLog(ErrorLog * log, const char * directory, const char * name) {
    
    // current time yyyy_mm_dd format
    time_t rawtime = time(NULL);
    struct tm *ptm = localtime(&rawtime);
    
    // make the directory if it doesn't exist
    mkdir(directory,S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
    
    // make path string
    log->path = (char *) malloc(sizeof(char) * (strlen(directory) + strlen(name)) + 1);
    
    sprintf(log->path,"%s/%s_%04d_%02d_%02d.txt",directory,name,(1900 + ptm->tm_year),ptm->tm_mon,ptm->tm_mday);
    
    printf("path: %s \n", log->path);
    
    log->file = fopen(log->path,"a");
    
    // Set count to zero
    log->count = 0;
    
    return 0;
}

// destroy error log
int DestroyErrorLog(ErrorLog * log) {
    
    if(log->file)
        fclose(log->file);
    
    if(log->path)
        free(log->path);
    
    return 0;
}

// print to error log
int LogError(ErrorLog * log, const char * msg, const char * file, int line) {
    log->count++;
    // Add in time functionality here
    fprintf(log->file,"%d) ERROR: %s \t file: %s -->\t line: %d \n",log->count,msg,file,line);
    return 0;
}

void PrintErrorLog(ErrorLog * log) {
    
}
