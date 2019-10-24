
#include "message_test.h"

#define PREV_MSG_SIZE_BYTES     32

void test_message_alloc() {
    Message * msg = message_alloc();
    
    // Check if it's not NULL
    TEST_ASSERT_NOT_NULL(msg);
    
    // Check if allocated message size has increased.
    TEST_ASSERT_TRUE(sizeof(*msg) == PREV_MSG_SIZE_BYTES);
    
    // Check if the variables are initialized correctly.
    TEST_ASSERT_NULL(msg->data);
    TEST_ASSERT_NULL(msg->data_type);
    TEST_ASSERT_TRUE(msg->size == 0);
    TEST_ASSERT_TRUE(msg->time_stamp == -1);
    
    message_free(msg);
}

void test_message_reset() {
    TEST_MESSAGE("Function and test function not yet implemented.");
}

void test_message_free() {
    Message * msg = NULL;
    // Test if error message output
    TEST_ASSERT_TRUE(ERROR_TYPENULL == message_free(msg));
    
    msg = message_alloc();
    // Test if function completes
    TEST_ASSERT_TRUE(0 == message_free(msg));
}

void test_message_set_data() {
    
    Message * msg = NULL;
    int ret = 0;
    char * tstStr = strdup("This is a test message");
    int size = strlen(tstStr) + 1;
    
    // Test Message struct NULL
    ret = message_set_data(msg,tstStr, size, "char*");
    TEST_ASSERT_TRUE(ERROR_TYPENULL == ret);
    
    // Test data NULL
    msg = message_alloc();
    ret = message_set_data(msg, NULL, size,  "char*");
    TEST_ASSERT_TRUE(ERROR_TYPENULL == ret);

    
    
    free(tstStr);
}


void test_unit_message_file() {
    RUN_TEST(test_message_alloc);
    RUN_TEST(test_message_reset);
    RUN_TEST(test_message_free);
    RUN_TEST(test_message_set_data);
}
