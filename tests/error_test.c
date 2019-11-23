#include "test.h"

#define MAX_ERR_ARR_LAST_TESTED  111

void test_errorLog_alloc(){
    TEST_IGNORE_MESSAGE("TEST NOT IMPLEMENTED");
}

void test_errorLog_free(){
    TEST_IGNORE_MESSAGE("TEST NOT IMPLEMENTED");
}

void test_errorLog_create(){
    TEST_IGNORE_MESSAGE("TEST NOT IMPLEMENTED");
}

void test_errorLOg_log(){
    TEST_IGNORE_MESSAGE("TEST NOT IMPLEMENTED");
}

void test_error_getString() {
    TEST_ASSERT_EQUAL_STRING("message was null pointer", error_getString(ERROR_TYPENULL));
    TEST_ASSERT_EQUAL_STRING("negative values are not accepted as inputs", error_getString(ERROR_NEGVAL));
    TEST_ASSERT_EQUAL_STRING("Incorrect string value entered", error_getString(ERROR_STRING));
    TEST_ASSERT_EQUAL_STRING("unable to open the given address", error_getString(ERROR_OPEN));
    TEST_ASSERT_EQUAL_STRING("size value is not correct", error_getString(ERROR_SIZE));
    TEST_ASSERT_EQUAL_STRING("data value is not correct", error_getString(ERROR_DATA));
    TEST_ASSERT_EQUAL_STRING("data type is not correct", error_getString(ERROR_TYPEDATA));
    TEST_ASSERT_EQUAL_STRING("function not yet implemented", error_getString(ERROR_IMPLEMENTED));
    TEST_ASSERT_NULL_MESSAGE(error_getString(MAX_ERR_ARR_LAST_TESTED),"error_getString function needs to be updated with newest test values. errorArray[] was changed.");
}

void test_error_print(){
    TEST_IGNORE_MESSAGE("TEST NOT IMPLEMENTED");
}

void test_uliderror_MACRO(){
    TEST_IGNORE_MESSAGE("TEST NOT IMPLEMENTED");
}

void test_unit_error_file() {
    RUN_TEST(test_errorLog_alloc);
    RUN_TEST(test_errorLog_free);
    RUN_TEST(test_errorLog_create);
    RUN_TEST(test_error_getString);
    RUN_TEST(test_error_print);
    RUN_TEST(test_uliderror_MACRO);
}
