#ifndef _ULLID_ERROR_HEADER
#define _ULLID_ERROR_HEADER

#include <stdio.h>
#include <stdlib.h>

char * errorLogName;

FILE * errorLogFile;

int ConstructErrorLog(const char * fileName);

int DestructErrorLog();

int LogError(const char * errorMessage);

#endif
