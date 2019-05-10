
/*  STANDARD INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

/*  LOCAL INCLUDEDS */
#include "ullid_test.h"


// Initialize the Test Log --> Creats the name --> possibly create and open the file
int ConstructTestLog(const char * fileName) {
    // Set the test log name
    if(fileName == NULL)
        return 1;
    testLogName = (char*) malloc(strlen(fileName)*sizeof(char));
    strcpy(testLogName,fileName);
    testLogFile = fopen(testLogName,"w");
    return 0;
}


// Releases all things that have been allocated
int DestructTestLog(){
    fclose(testLogFile);
    free(testLogName);
    return 0;
}


// Logs the results of the test
int LogTestResult(const char * testSet, const char * testName, const char * result, ... ) {
    va_list lst;
    va_start(lst,result);
    
    fprintf(testLogFile, "Test %d) %s - %s --> %s\n",testNumber,testSet,testName,result);
    
    if(printToTerminal)
        printf("Test %d) %s - %s --> %s\n",testNumber,testSet,testName,result);
    
    // This will add a note after the test.
    char * note = NULL;
    note = va_arg(lst,char*);
    if(note != NULL)
        fprintf(testLogFile,"\tNote: %s\n",note);
    
    va_end(lst);
    return 0;
}


#ifdef _ULLID_COMM_FORMAT_HEADER

int sMN_SetAccessModeTest_CorrectStringProduced() {   // Test SetAccessMode --> Has correct output.

    const char * message = "checks if telegramBuilder function produced desired output.";
    const char * correctStr = "\2sMN SetAccessMode 03 F4724744\3";
    char * testString = telegramBuilder(sMN,SetAccessMode,"client", "F4724744");
    
    int result = strncmp(correctStr,testString,strlen(testString));
    if(result == 0){
        LogTestResult(COMM_FORMAT_TEST_SET,__FUNCTION__,"PASSED", message);
    } else {
        LogTestResult(COMM_FORMAT_TEST_SET,__FUNCTION__,"FAILED", message);
    }
    
    free(testString);
    return 0;
}

int sMN_mLMPsetscancfgTest_CorrectStringProduct() {
    
    const char * message = "checks if telegramBuilder function produced desired output.";
    const char * correctStr = "\2sMN SetAccessMode +5000 \3";
    char * testString = telegramBuilder(sMN,mLMPsetscancfg,25);
    
    int result = strncmp(correctStr,testString,strlen(testString));
    if(result == 0){
        LogTestResult(COMM_FORMAT_TEST_SET,__FUNCTION__,"PASSED", message);
    } else {
        LogTestResult(COMM_FORMAT_TEST_SET,__FUNCTION__,"FAILED", message);
    }
    
    free(testString);
    return 0;
}


int CommunicationFormatTestSet(){
    
    sMN_SetAccessModeTest_CorrectStringProduced();
    sMN_mLMPsetscancfgTest_CorrectStringProduct();
    
    return 0;
}

#endif

int main(int argc, char * argv[]) {
    
    
    
    ConstructErrorLog("ErrorLog.txt");
    ConstructTestLog("TestLog.txt");
    
    CommunicationFormatTestSet();
    
    DestructErrorLog();
    DestructTestLog();
    
    return 0;
}
