#ifndef _ULLID_TEST_HEADER
#define _ULLID_TEST_HEADER

#include <stdarg.h>

#include "ullid_utility.h"
#include "ullid_error.h"
#include "ullid_comm_format.h"

// Create Test Log File Thingy
FILE * testLogFile;

char * testLogName;

// General global variables
int printToTerminal = 1; // change to zero if not wanting to print
int testNumber = 1; // Inreases automatically for each test

int Test_String_Equal(const char * str1, const char * str2);

int ConstructTestLog(const char * fileName);

int DestructTestLog();

int LogTestResult(const char * testSet, const char * testName, const char * result, ... );

int AssertStringsEqual(const char * testingStr, const char * correctStr);



#ifdef _ULLID_COMM_FORMAT_HEADER

#define COMM_FORMAT_TEST_SET "CommunicationFormatTestSet"

int CommunicationFormatTestSet();

#endif





#endif
