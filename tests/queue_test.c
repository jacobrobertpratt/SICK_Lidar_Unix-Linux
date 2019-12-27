#include "test.h"

void test_queue_alloc() {
    Message * msg = message_alloc();
    
    message_free(msg);
}

void test_unit_queue_file() {
    test_queue_alloc();
}
