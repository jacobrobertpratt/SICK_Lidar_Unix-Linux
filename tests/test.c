/**
 * Main testing entry point. This class will systymatically run all testing classes that are associated with ULID.
 */

/* STANDARD HEADERS */
#include <stdio.h>
#include <stdlib.h>

/* LOCAL HEADERS */
#include "unity.h"
#include "message_test.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    
    // tests for the message.c file
    test_unit_message_file();
    
    return UNITY_END();
}
