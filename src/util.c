
#include "../include/util.h"

int createDir(const char * directory, const char * dirname) {
    
    char * dir = NULL; 
    char * name = NULL;
    
    int ret = 0;
    
    // if directory is null
    if(!directory) {
        getcwd(dir,1024);
    } else {
        dir = strdup(directory);
        ret = chdir(dir);
        if (ret == ENOENT) {
            perror("no path exists");
            return 1;
        }
    }
    
    // Check if filename is null or not
    if(!dirname){
        name = strdup("file");
    } else {
        name = strdup(dirname);
        if(!name)
            return 1;
    }
    
    /* We actually generate the file below */
    
    /* The behavior of mkdir is undefined for anything other than the "permission" bits */
    if (mkdir(name, 0777)){
        perror(name);
        return 1;
    }

    /* So we need to set the sticky/executable bits explicitly with chmod after calling mkdir */
    if (chmod(name, 07777)){
        perror(name);
        return 1;
    }
    
    // make sure to free everything
    free(dir);
    free(name);
    
    return ret;
}
/*
int getYYYYMMDDString(char * string) {
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    if(!string)
        return 1;
    
    // allocate string
    char * str = (char*) malloc(sizeof(char) * 8 + 1);
    
    // build string after this
    free(str);
    
    return 0;
}
*/
