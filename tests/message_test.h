#include "../include/message.h"
#include "unity.h"

typedef struct test_struct_t {
    int integer;
    char * testChar;
} TestStruct;

void test_message_alloc();

void test_message_reset();

void test_message_free();

void test_message_set_data();

void test_unit_message_file();
