
#include <string.h>

#include "ulid_utility.h"

/*
 printHex:
 This method takes a string and prints out the hexadecimal value with two digits.
 Input: const char *
 Returns: 0 upon completion
 */
int printHex(const char * str){
    int i, j;
    j = strlen(str);
    for(i = 0; i < j; i++){
        printf("%x ",str[i]);
    }
    printf("\n");
    return 0;
}

void freeString(char * string) {
    if(string != NULL)
        free(string);
}
