
#include "test.h"

// Represents the size of the Message struct (10/28/2019)
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
    
    Message * msg = message_alloc();
    
    // TODO:
    
    message_free(msg);
}

void test_message_free() {
    
    Message * msg = NULL;
    
    // Test if error message output
    message_free(msg);
    TEST_ASSERT_NULL(msg);
    
    // Allocate the message
    msg = message_alloc();
    TEST_ASSERT_NOT_NULL(msg);
    
    // Check if function returns correct result
    message_free(msg);
    
}

void test_message_set_data_works() {
    
    int ret;
    Message * msg = message_alloc();
    
    char * test_str = strdup("test data string");
    
    ret = message_setData(msg,test_str,strlen(test_str));
    
    TEST_ASSERT_TRUE(ret == 0);
    TEST_ASSERT_NOT_NULL(msg->data);
    TEST_ASSERT_EQUAL_STRING (test_str, msg->data);
    
    free(test_str);
    
    message_free(msg);
    
}

void test_message_set_data_null_msg() {
    
    int ret = 0;
    Message * msg = NULL;
    char * test_str = strdup("test data string");
    
    ret = message_setData(msg,test_str,strlen(test_str));
    TEST_ASSERT_TRUE(ret == ERROR_TYPENULL);
    
    free(test_str);
    
    message_free(msg);
}

void test_message_set_data_null_data() {
    int ret;
    Message * msg = message_alloc();
    char * test_str = NULL;
    
    ret = message_setData(msg,test_str,0);
    TEST_ASSERT_TRUE(ret == ERROR_TYPEDATA);
    
    message_free(msg);
}

void test_message_set_data_size_zero() {
    int ret;
    Message * msg = message_alloc();
    char * test_str = strdup("test data string");
    
    ret = message_setData(msg,test_str,0);
    TEST_ASSERT_TRUE(ret == ERROR_SIZE);
    
    free(test_str);
    
    message_free(msg);
}

void test_message_set_data_diff_data() {
    int ret;
    Message * msg = message_alloc();
    
    char * test_str = strdup("test data string");
    // Sets the initial data
    ret = message_setData(msg,test_str,strlen(test_str));
    // Checks the inital data is correct
    TEST_ASSERT_TRUE(ret == 0);
    TEST_ASSERT_NOT_NULL(msg->data);
    TEST_ASSERT_EQUAL_STRING (test_str, msg->data);
    
    char * test_str_2 = strdup("different test data string");
    
    ret = message_setData(msg,test_str_2,strlen(test_str_2));
    
    TEST_ASSERT_TRUE(ret == 0);
    TEST_ASSERT_NOT_NULL(msg->data);
    TEST_ASSERT_EQUAL_STRING (test_str_2, msg->data);
    
    free(test_str);
    free(test_str_2);
    message_free(msg);
}

void test_message_set_timestamp() {
    int ret;
    //TEST_FAIL_MESSAGE("Function and test function not yet implemented.");
    Message * msg = message_alloc();
    ret = message_setTimestamp(msg,100122);
    TEST_ASSERT_TRUE(100122 == msg->time_stamp);
    TEST_ASSERT_TRUE(ret == 0);
    message_free(msg);
}

void test_unit_message_file() {
    RUN_TEST(test_message_alloc);
    RUN_TEST(test_message_reset);
    RUN_TEST(test_message_free);
    RUN_TEST(test_message_set_data_works);
    RUN_TEST(test_message_set_data_null_msg);
    RUN_TEST(test_message_set_data_null_data);
    RUN_TEST(test_message_set_data_size_zero);
    RUN_TEST(test_message_set_data_diff_data);
    RUN_TEST(test_message_set_timestamp);
}
