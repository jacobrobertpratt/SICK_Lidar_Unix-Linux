
#include "../include/util.h"
#include "../include/error.h"

int countTokens(char * str, char chr) {
    
    if(!str)
        return -1;
    
    
    
    int i, cnt = 0;
    if(str) {
        for(i = 0; i < strlen(str); i++)
            if(str[i] == chr)
                cnt++;
    }
    
    cnt++;
    
    return cnt;
}

int stringToTokenArray(char * str, char * arr[], const char * tokens, int count) {
    
    // str not NULL
    if(!str || !tokens) {
        uliderror(ERROR_TYPENULL);
        return ERROR_TYPENULL;
    }
    
    // tokens and count must be of some values
    if(strlen(tokens) == 0 || count < 1) {
        uliderror(ERROR_SIZE);
        return ERROR_SIZE;
    }
    
    char **ap;
    
    for (ap = arr; (*ap = strsep(&str, tokens)) != NULL;)
            if (**ap != '\0')
                    if (++ap >= &arr[count])
                            break;
    
    return 0;
}
