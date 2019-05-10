
#include <string.h>

#include "ullid_error.h"

int ConstructErrorLog(const char * fileName){
    if(fileName == NULL)
        return 1;
    errorLogName = (char*) malloc(strlen(fileName)*sizeof(char));
    strcpy(errorLogName,fileName);
    return 0;
}

int DestructErrorLog(){
    free(errorLogName);
    return 0;
}

int LogError(const char * errorMessage) {
    errorLogFile = fopen(errorLogName,"w");
    fprintf(errorLogFile,"ERROR: %s in\t%s @ line %d\n",errorMessage,__FILE__,__LINE__);
    fclose(errorLogFile);
    return 0;
}
