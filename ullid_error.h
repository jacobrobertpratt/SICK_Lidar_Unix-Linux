/*  Controls all error messages & updates error log file
 */

#ifndef _ULLID_ERROR_HEADER
#define _ULLID_ERROR_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE * error_log_file;
bool print_error;

/*  */
void logError(const char * error_msg, const char * file, int line);

#endif
