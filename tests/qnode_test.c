
#include "test.h"

void test_qnode_free_NULL() {
    int ret;
    QNode * node = NULL;
    ret = qnode_free(node);
    TEST_ASSERT_NULL(node);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL, ret);
}

void test_qnode_alloc() {
    QNode * node = NULL;
    node = qnode_alloc();
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_NULL(node->data);
    TEST_ASSERT_NULL(node->next);
    free(node);
}

void test_qnode_free() {
    int ret = 0;
    QNode * node = qnode_alloc();
    ret = qnode_free(node);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_qnode_setData_null_data() {
    int ret = 0;
    QNode * node = qnode_alloc();
    ret = qnode_setData(node, NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL, ret);
    qnode_free(node);
}

void test_qnode_setData_null_node() {
    int ret = 0;
    ret = qnode_setData(NULL, NULL);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL, ret);
}

void test_qnode_setData_node_data_set() {
    int ret = 0;
    QNode * node = qnode_alloc();
    Message * msg1 = message_alloc();
    Message * msg2 = message_alloc();
    
    node->data = msg1;
    ret = qnode_setData(node,msg2);
    TEST_ASSERT_EQUAL_INT(ERROR_REPDATA, ret);
    ret = message_free(msg1);
    ret = message_free(msg2);
    node->data = NULL; // Must set pointer to null before freeing node
    ret = qnode_free(node);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_qnode_setData() {
    int ret = 0;
    QNode * node = qnode_alloc();
    Message * msg = message_alloc();
    ret = qnode_setData(node, msg);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_NOT_NULL(node->data);
    TEST_ASSERT_EQUAL_MEMORY(node->data, msg, sizeof(*msg));
    ret = message_free(msg);
    TEST_ASSERT_EQUAL_INT(0, ret);
    node->data = NULL;
    ret = qnode_free(node);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_qnode_connect_curr_null(){
    int ret = 0;
    QNode * node1 = NULL;
    QNode * node2 = qnode_alloc();
    ret = qnode_connect(node1, node2);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL, ret);
    ret = qnode_free(node2);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_qnode_connect_next_null(){
    int ret = 0;
    QNode * node1 = qnode_alloc();
    QNode * node2 = NULL;
    ret = qnode_connect(node1, node2);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL, ret);
    ret = qnode_free(node1);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_qnode_connect_next_set() {
    int ret = 0;
    QNode * node1 = qnode_alloc();
    QNode * node2 = qnode_alloc();
    QNode * node3 = qnode_alloc();
    node1->next = node2;
    TEST_ASSERT_EQUAL_MEMORY(node1->next,node2,sizeof(*node2));
    ret = qnode_connect(node1,node3);
    TEST_ASSERT_EQUAL_INT(ERROR_REPDATA, ret);
    ret = qnode_free(node2);
    TEST_ASSERT_EQUAL_INT(0, ret);
    ret = qnode_free(node1);
    TEST_ASSERT_EQUAL_INT(0, ret);
    ret = qnode_free(node3);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_qnode_connect() {
    int ret = 0;
    QNode * node1 = qnode_alloc();
    QNode * node2 = qnode_alloc();
    
    ret = qnode_connect(node1,node2);
    TEST_ASSERT_EQUAL_INT(0, ret);
    TEST_ASSERT_NOT_NULL(node1->next);
    TEST_ASSERT_EQUAL_MEMORY(node1->next,node2,sizeof(*node2));
    
    ret = qnode_free(node2);
    TEST_ASSERT_EQUAL_INT(0, ret);
    node1->next = NULL;
    ret = qnode_free(node1);
    TEST_ASSERT_EQUAL_INT(0, ret);
}

void test_unit_qnode() {
    RUN_TEST(test_qnode_free_NULL);
    RUN_TEST(test_qnode_alloc);
    RUN_TEST(test_qnode_free);
    RUN_TEST(test_qnode_setData_null_data);
    RUN_TEST(test_qnode_setData_null_node);
    RUN_TEST(test_qnode_setData_node_data_set);
    RUN_TEST(test_qnode_setData);
    RUN_TEST(test_qnode_connect_curr_null);
    RUN_TEST(test_qnode_connect_next_null);
    RUN_TEST(test_qnode_connect_next_set);
    RUN_TEST(test_qnode_connect);
    
}
