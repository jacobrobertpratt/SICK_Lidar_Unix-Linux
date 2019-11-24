/**
 * Main testing entry point. This class will systymatically run all testing classes that are associated with ULID.
 */
#include <unistd.h>

#include "test.h"

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
        test_unit_socket_file();
    }
    
    int i;
    for(i = 0; i < argc; i++){
        // tests message.c file
        if(!strcmp("-msg",argv[i]) || !strcmp("--msg",argv[i]) || !strcmp("-message",argv[i]) || !strcmp("--message",argv[i]))
            test_unit_message_file();
        
        // tests error.c file
        if(!strcmp("-err",argv[i]) || !strcmp("--err",argv[i]) || !strcmp("-error",argv[i]) || !strcmp("--error",argv[i]))
            test_unit_error_file();
        
        // tests socket.c file
        if(!strcmp("-sock",argv[i]) || !strcmp("--sock",argv[i]) || !strcmp("-socket",argv[i]) || !strcmp("--socket",argv[i]))
            test_unit_socket_file();
    }
    
    return UNITY_END();
}
