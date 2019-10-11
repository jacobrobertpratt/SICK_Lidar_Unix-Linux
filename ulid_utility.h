#ifndef _ULLID_UTILITY_HEADER
#define _ULLID_UTILITY_HEADER

#include "ulid_common.h"

/*  printHex(const char * str)
 *  This will print the Hex values of the string and end with a new line.
 *  If the string is NULL then nothing will print.
 *  @return 1 on failure, 0 upon success. */ 
int printHex(const char * str);

/*  freeString(char * string)
 *  This checks if the string is NULL before freeing
 *  */
void freeString(char * string);

#endif
