#include "test.h"

void test_fifo_alloc_general() {
    Fifo * queue = fifo_alloc();
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->tail);
    TEST_ASSERT_EQUAL_INT(50, queue->max);
    TEST_ASSERT_EQUAL_INT(0, queue->size);
    TEST_ASSERT_EQUAL_STRING("",queue->type);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
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
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_setMaxSize_0() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setMaxSize(queue, 0);
    TEST_ASSERT_EQUAL_INT(ERROR_SIZE,ret);
    TEST_ASSERT_EQUAL_INT(50,queue->max);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_setMaxSize_net_10() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setMaxSize(queue, -1);
    TEST_ASSERT_EQUAL_INT(ERROR_SIZE,ret);
    TEST_ASSERT_EQUAL_INT(50,queue->max);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_getSize_queue_null() {
    Fifo * queue = NULL;
    int ret = fifo_getSize(queue);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_getSize_init() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_getSize(queue);
    TEST_ASSERT_EQUAL_INT(0,ret);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_free_queue_null() {
    int ret = fifo_free(NULL, NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_free_queue_full() {
    Fifo * queue = fifo_alloc();
    int i;
    for(i = 0; i < 10; i++) {
        Message * msg = message_alloc();
        fifo_push(queue, msg);
    }
    TEST_ASSERT_EQUAL_INT(10, fifo_getSize(queue));
    int ret = fifo_free(queue, message_free);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_fifo_free_init() {
    Fifo * queue = fifo_alloc();
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
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
    TEST_ASSERT_EQUAL_INT(0, fifo_free(queue, NULL));
}

void test_fifo_pop_queue_null() {
    TEST_ASSERT_NULL(fifo_pop(NULL));
}

void test_fifo_setType_queue_null() {
    int ret = fifo_setType(NULL, "asdf");
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_fifo_setType_string_null() {
    Fifo * queue = fifo_alloc();
    int ret = fifo_setType(queue, NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_push_one_message() {
    Fifo * queue = fifo_alloc();
    Message * msg = message_alloc();
    int ret = fifo_push(queue, msg);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_INT(1, queue->size);
    TEST_ASSERT_EQUAL_MEMORY(queue->head->data,msg,sizeof(*msg));
    TEST_ASSERT_EQUAL_MEMORY(queue->tail->data,msg,sizeof(*msg));
    Message * retmsg = fifo_pop(queue);
    message_free(retmsg);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_pop_one_message() {
    Fifo * queue = fifo_alloc();
    Message * msg = message_alloc();
    fifo_push(queue, msg);
    TEST_ASSERT_EQUAL_INT(1, fifo_getSize(queue));
    Message * retmsg = fifo_pop(queue);
    TEST_ASSERT_EQUAL_MEMORY(msg,retmsg,sizeof(*msg));
    TEST_ASSERT_EQUAL_INT(0, fifo_getSize(queue));
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->tail);
    message_free(retmsg);
    TEST_ASSERT_EQUAL_INT(0, fifo_free(queue, NULL));
}

void test_fifo_push_two_message() {
    Fifo * queue = fifo_alloc();
    Message * msg1 = message_alloc();
    Message * msg2 = message_alloc();
    int ret = fifo_push(queue, msg1);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_INT(1, queue->size);
    ret = fifo_push(queue, msg2);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_EQUAL_INT(2, queue->size);
    TEST_ASSERT_EQUAL_MEMORY(queue->head->data,msg1,sizeof(*msg1));
    TEST_ASSERT_EQUAL_MEMORY(queue->tail->data,msg2,sizeof(*msg2));
    msg1 = fifo_pop(queue);
    msg2 = fifo_pop(queue);
    message_free(msg1);
    message_free(msg2);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_pop_two_message() {
    Fifo * queue = fifo_alloc();
    Message * msg1 = message_alloc();
    Message * msg2 = message_alloc();
    fifo_push(queue, msg1);
    fifo_push(queue, msg2);
    Message * ret1 = fifo_pop(queue);
    TEST_ASSERT_NOT_NULL(ret1);
    TEST_ASSERT_EQUAL_MEMORY(ret1,msg1,sizeof(*msg1));
    TEST_ASSERT_EQUAL_INT(1,fifo_getSize(queue));
    Message * ret2 = fifo_pop(queue);
    TEST_ASSERT_NOT_NULL(ret2);
    TEST_ASSERT_EQUAL_MEMORY(ret2,msg2,sizeof(*msg1));
    TEST_ASSERT_EQUAL_INT(0,fifo_getSize(queue));
    message_free(msg1);
    message_free(msg2);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
}

void test_fifo_push_pop_5_message() {
    Fifo * queue = fifo_alloc();
    Message * msg1 = message_alloc();
    message_setData(msg1,"test1",sizeof("test1"));
    Message * msg2 = message_alloc();
    message_setData(msg2,"test2test2",sizeof("test2test2"));
    Message * msg3 = message_alloc();
    message_setData(msg3,"test3 123",sizeof("test3 123"));
    Message * msg4 = message_alloc();
    message_setData(msg4,"asdfadsf",sizeof("asdfadsf"));
    Message * msg5 = message_alloc();
    message_setData(msg5,"12341234",sizeof("12341234"));
    fifo_push(queue, msg1);
    fifo_push(queue, msg2);
    fifo_push(queue, msg3);
    fifo_push(queue, msg4);
    fifo_push(queue, msg5);
    Message * ret = fifo_pop(queue);
    TEST_ASSERT_EQUAL_MEMORY(ret,msg1,sizeof(*msg1));
    TEST_ASSERT_EQUAL_STRING("test1",ret->data);
    message_free(ret);
    ret = fifo_pop(queue);
    TEST_ASSERT_EQUAL_MEMORY(ret,msg2,sizeof(*msg2));
    TEST_ASSERT_EQUAL_STRING("test2test2",ret->data);
    message_free(ret);
    ret = fifo_pop(queue);
    TEST_ASSERT_EQUAL_MEMORY(ret,msg3,sizeof(*msg3));
    TEST_ASSERT_EQUAL_STRING("test3 123",ret->data);
    message_free(ret);
    ret = fifo_pop(queue);
    TEST_ASSERT_EQUAL_MEMORY(ret,msg4,sizeof(*msg4));
    TEST_ASSERT_EQUAL_STRING("asdfadsf",ret->data);
    message_free(ret);
    ret = fifo_pop(queue);
    TEST_ASSERT_EQUAL_MEMORY(ret,msg5,sizeof(*msg5));
    TEST_ASSERT_EQUAL_STRING("12341234",ret->data);
    message_free(ret);
    TEST_ASSERT_EQUAL_INT(0,fifo_free(queue, NULL));
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
    RUN_TEST(test_fifo_free_queue_full);
    RUN_TEST(test_fifo_free_init);
    RUN_TEST(test_fifo_push_queue_null);
    RUN_TEST(test_fifo_push_data_null);
    RUN_TEST(test_fifo_pop_queue_null);
    RUN_TEST(test_fifo_setType_queue_null);
    RUN_TEST(test_fifo_setType_string_null);
    RUN_TEST(test_fifo_push_one_message);
    RUN_TEST(test_fifo_pop_one_message);
    RUN_TEST(test_fifo_push_two_message);
    RUN_TEST(test_fifo_pop_two_message);
    RUN_TEST(test_fifo_push_pop_5_message);
}

