
#ifndef ULID_UTIL_H
#define ULID_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include "common.h"

/** CLASS DEFINITION:
 * This class is a combination of random functions that have been useful in the building of this API. All these functions geneal implementations and are not subject to any specific class purposes, although they are found more common in some classes than in others.
 */

/**
 * Given a non-null string. This function will return the value of the number of character values plus one. This provides the total number of tokens used. The resulting number will be a positive integer. If the string value entered is NULL -1 will be returned. This is used to in multiple instances to decode the return messages from a lidar device.
 * @param str char * string value (null terminated)
 * @param chr character value wanting to count
 * @return integer number of tokens
 */
int countTokens(char * str, char chr);

/**
 * Passing a string value and null set array of character pointers will fill the array with the tokenized character values. This function does not copy values, but just reassigns their pointers. The tokens that are passed are in string format, and should be listed all values that should not be included in the array (ex. " \2\3" is a valid entry). The count, is the number of tokens for the array, and ultimitly the size of the array. The string entered and tokens entered must not be of zero length or NULL values. The count must be greater than 0. The arr must be initialized to NULL.
 * @param str string pointer
 * @param arr[] NULL set character pointer
 * @param tokens constant string of delimiters
 * @param count integer size of array
 * @return 0 on success or ulid error number
 *      ERROR_TYPENULL if the string entered is not allocated
 *      ERROR_SIZE size of tokens and count must be greater than trivial
 */
int stringToTokenArray(char * str, char * arr[], const char * tokens, int count);


#endif
