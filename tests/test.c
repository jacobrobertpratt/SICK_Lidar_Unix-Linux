/**
 * Main testing entry point. This class will systymatically run all testing classes that are associated with ULID.
 */

/* STANDARD HEADERS */
#include <stdio.h>
#include <stdlib.h>

/* LOCAL HEADERS */
#include "unity.h"
#include "message_test.h"
#include "error_test.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

// not needed when using generate_test_runner.rb
int main(int argc, char * argv[]) {
    UNITY_BEGIN();
    
    if(argc < 2){
        test_unit_message_file();
        test_unit_error_file();
    }
    
    int i;
    for(i = 0; i < argc; i++){
        // tests message.c file
        if(!strcmp("-msg",argv[i]) || !strcmp("--msg",argv[i]) || !strcmp("-message",argv[i]) || !strcmp("--message",argv[i]))
            test_unit_message_file();
        
        // tests error.c file
        if(!strcmp("-err",argv[i]) || !strcmp("--err",argv[i]) || !strcmp("-error",argv[i]) || !strcmp("--error",argv[i]))
            test_unit_error_file();
        
        
    }
    
    return UNITY_END();
}
