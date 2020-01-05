
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
/**
 * Creates a directory at the given directory location specifiec locations with the given
 * name specified. If the directory is set to NULL, a directory will be made at the current
 * wording directory. If the file name is NULL then the function will return an error. This
 * functions checks to see if the file directory and name already exists. If they already
 * exists it returns 0. The directory name can either take a root directory or a shorter string
 * from the current working directory.
 *
 *  This also works like a terrminal in that you can specify going forward or backward
 *  in the current working directory. As in if you type ".." into the directory name, it will make
 *  the file in the previous directory.
 * @param directory is a (const char *)
 * @param dirname name of new directory
 * @return 0 on success, 1 on failure
 */
int createDir(const char * directory, const char * dirname);

/**
 * Get date and time as a string
 */
int getYYYYMMDDString(char * string);

#endif
