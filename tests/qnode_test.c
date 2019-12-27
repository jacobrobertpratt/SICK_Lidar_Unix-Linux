
#include "test.h"

void test_qnode_alloc_dataNUll() {
    struct qnode_t * node = qnode_alloc(NULL);
    TEST_ASSERT_NULL(node);
}

void test_qnode_alloc_Message() {
    Message * msg = message_alloc();
    
    message_free(msg);
}

void test_unit_qnode() {
    RUN_TEST(test_qnode_alloc_dataNUll);
    RUN_TEST(test_qnode_alloc);
}
