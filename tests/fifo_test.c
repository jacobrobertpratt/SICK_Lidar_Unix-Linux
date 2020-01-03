#include "test.h"

void test_fifo_alloc_general() {
    Fifo * queue = fifo_alloc();
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->tail);
    TEST_ASSERT_EQUAL_INT(50, queue->max);
    TEST_ASSERT_EQUAL_INT(0, queue->size);
    TEST_ASSERT_EQUAL_STRING("",queue->type);
    free(queue);
}

void test_fifo_setMaxSize_queue_null() {
    Fifo * queue = NULL;
    int ret = fifo_setMaxSize(queue, 100);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_setMaxSize_100() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setMaxSize(queue, 100);
    TEST_ASSERT_EQUAL_INT(0,ret);
    TEST_ASSERT_EQUAL_INT(100,queue->max);
    free(queue);
}

void test_fifo_setMaxSize_0() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setMaxSize(queue, 0);
    TEST_ASSERT_EQUAL_INT(ERROR_SIZE,ret);
    TEST_ASSERT_EQUAL_INT(50,queue->max);
    free(queue);
}

void test_fifo_setMaxSize_net_10() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setMaxSize(queue, -1);
    TEST_ASSERT_EQUAL_INT(ERROR_SIZE,ret);
    TEST_ASSERT_EQUAL_INT(50,queue->max);
    free(queue);
}

void test_fifo_getSize_queue_null() {
    Fifo * queue = NULL;
    int ret = fifo_getSize(queue);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
    free(queue);
}

void test_fifo_getSize_init() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_getSize(queue);
    TEST_ASSERT_EQUAL_INT(0,ret);
    free(queue);
}

void test_fifo_free_queue_null() {
    int ret = fifo_free(NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_free_init() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_free(queue);
    TEST_ASSERT_EQUAL_INT(0,ret);
}

void test_fifo_push_queue_null() {
    Message * msg = message_alloc();
    int ret = fifo_push(NULL,msg);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
    message_free(msg);
}

void test_fifo_push_data_null() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_push(queue,NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
    free(queue);
}

void test_fifo_reset_queue_null() {
    int ret = fifo_reset(NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_pop_queue_null() {
    TEST_ASSERT_NULL(fifo_pop(NULL));
}

void test_fifo_dalloc_callback_queue_null() {
    int ret = fifo_setDealloc_Callback(NULL, test_fifo_free_init);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_dalloc_callback_func_null() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setDealloc_Callback(queue, NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
    free(queue);
}

void test_fifo_setType_queue_null() {
    int ret = fifo_setType(NULL,"asdf");
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_setType_string_null() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setType(queue,NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
    free(queue);
}

void test_fifo_push_one_message() {
    Fifo * queue = fifo_alloc();
    Message * msg = message_alloc();
    int ret = fifo_push(queue, msg);
    TEST_ASSERT_EQUAL_INT(0,ret);
    //TEST_ASSERT_EQUAL_PTR
    //TEST_ASSERT_EQUAL_MEMORY
    TEST_ASSERT_EQUAL_INT(1,queue->size);
    message_free(msg);
    fifo_free(queue);
}



void test_unit_fifo() {
    RUN_TEST(test_fifo_alloc_general);
    RUN_TEST(test_fifo_setMaxSize_queue_null);
    RUN_TEST(test_fifo_setMaxSize_100);
    RUN_TEST(test_fifo_setMaxSize_0);
    RUN_TEST(test_fifo_setMaxSize_net_10);
    RUN_TEST(test_fifo_getSize_queue_null);
    RUN_TEST(test_fifo_getSize_init);
    RUN_TEST(test_fifo_free_queue_null);
    RUN_TEST(test_fifo_free_init);
    RUN_TEST(test_fifo_push_queue_null);
    RUN_TEST(test_fifo_push_data_null);
    RUN_TEST(test_fifo_reset_queue_null);
    RUN_TEST(test_fifo_pop_queue_null);
    RUN_TEST(test_fifo_dalloc_callback_queue_null);
    RUN_TEST(test_fifo_dalloc_callback_func_null);
    RUN_TEST(test_fifo_setType_queue_null);
    RUN_TEST(test_fifo_setType_string_null);
    RUN_TEST(test_fifo_push_one_message);
}

