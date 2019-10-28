
#include "message_test.h"

// Represents the size of the Message struct (10/28/2019)
#define PREV_MSG_SIZE_BYTES     32

struct test_t {
    int a;
    char * b;
};

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
    int ret;
    Message * msg = message_alloc();
    struct test_t test;
    test.a = 5;
    test.b = strdup("test string");
    ret = message_set_data(msg,&test,sizeof(struct test_t),"test_struct");
    TEST_ASSERT_TRUE(0 == ret);
    TEST_ASSERT_NOT_NULL(msg->data);
    // At this point a message struct is allocated and data is set
    
    // If msg is NULL
    Message * msg2 = NULL;
    ret = message_reset(msg2);
    TEST_ASSERT_TRUE(ERROR_TYPENULL == ret);
    
    // If msg is not null, then reset
    ret = message_reset(msg);
    TEST_ASSERT_TRUE(msg->size == 0);
    TEST_ASSERT_TRUE(msg->time_stamp == -1);
    TEST_ASSERT_NULL(msg->data_type);
    
    TEST_ASSERT_TRUE(0 == ret);
    
    free(test.b);
    message_free(msg);
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
    
    int ret = 0;
    struct test_t test;
    Message * msg = NULL;
    
    // Test Message all NULL
    ret = message_set_data(NULL, NULL, 0, NULL);
    TEST_ASSERT_TRUE(ERROR_TYPENULL == ret);
    
    // Test all NULL but msg
    msg = message_alloc();
    ret = message_set_data(msg,NULL,0,NULL);
    TEST_ASSERT_TRUE(ERROR_TYPEDATA == ret);
                     
    // Test all NULL but msg and data, size = 0
    ret = message_set_data(msg,&test,0,NULL);
    TEST_ASSERT_TRUE(ERROR_SIZE == ret);
    
    // test data_type not NULL
    ret = message_set_data(msg,&test,sizeof(struct test_t),"test");
    TEST_ASSERT_EQUAL_STRING("test",msg->data_type);
    
    // Test only data NULL
    test.a = 5;
    test.b = strdup("test string 1");
    ret = message_set_data(msg,&test,sizeof(struct test_t),NULL);
    TEST_ASSERT_TRUE(0 == ret);
    struct test_t * test1 = (struct test_t *) msg->data;
    TEST_ASSERT_TRUE(5 == test1->a);
    TEST_ASSERT_EQUAL_STRING("test string 1", test1->b);
    
    // test change of data
    struct test_t test2;
    test2.a = 7;
    test2.b = strdup("test string 2");
    ret = message_set_data(msg,&test2,sizeof(struct test_t),NULL);
    TEST_ASSERT_TRUE(0 == ret);
    struct test_t * test3 = (struct test_t *) msg->data;
    TEST_ASSERT_TRUE(7 == test3->a);
    TEST_ASSERT_EQUAL_STRING("test string 2", test1->b);
    
    free(test.b);
    free(test2.b);
    message_free(msg);
}

void test_message_set_timestamp() {
    //TEST_FAIL_MESSAGE("Function and test function not yet implemented.");
    Message * msg = message_alloc();
    int ret;
    ret = message_set_timestamp(msg,100122);
    TEST_ASSERT_TRUE(100122 == msg->time_stamp);
    TEST_ASSERT_TRUE(ret == 0);
}

void test_unit_message_file() {
    RUN_TEST(test_message_alloc);
    RUN_TEST(test_message_reset);
    RUN_TEST(test_message_free);
    RUN_TEST(test_message_set_data);
    RUN_TEST(test_message_set_timestamp);
}
