
#include "test.h"

void test_util_countTokens_NULL_str() {
    int ret = countTokens(NULL,' ');
    TEST_ASSERT_EQUAL_INT(-1,ret);
}

void test_util_countTokens_str_no_tokens() {
    char * str = strdup("thisisatestwithnotokens");
    int ret = countTokens(str,' ');
    TEST_ASSERT_EQUAL_INT(1,ret);
    free(str);
}

void test_util_countTokens_str_two_tokens() {
    char * str = strdup("thisisatestwith onetokens");
    int ret = countTokens(str,' ');
    TEST_ASSERT_EQUAL_INT(2,ret);
    free(str);
}

void test_util_countTokens_str_a_lot_of_tokens() {
    char * str = strdup("this is a test with many tokens");
    int ret = countTokens(str,' ');
    TEST_ASSERT_EQUAL_INT(7,ret);
    free(str);
}

void test_util_stringToTokenArray_str_null() {
    int ret = stringToTokenArray(NULL, NULL," ", 5);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
}

void test_util_stringToTokenArray_token_null() {
    char * arr[5];
    char * str = strdup("test");
    int ret = stringToTokenArray(str,arr,NULL, 5);
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL,ret);
    free(str);
}

void test_util_stringToTokenArray_token_zero_len() {
    char * arr[5];
    char * str = strdup("test");
    int ret = stringToTokenArray(str, arr,"", 5);
    TEST_ASSERT_EQUAL_INT(ERROR_SIZE,ret);
    free(str);
}

void test_util_stringToTokenArray_count_0() {
    char * arr[5];
    char * str = strdup("test");
    int ret = stringToTokenArray(str, arr," ", 0);
    TEST_ASSERT_EQUAL_INT(ERROR_SIZE, ret);
    free(str);
}

void test_util_stringToTokenArray_one_str_token() {
    char * arr[1];
    char * str = strdup("test");
    stringToTokenArray(str, arr, " ", 1);
    TEST_ASSERT_EQUAL_MEMORY(str,arr[0],sizeof(*str));
    free(str);
}

void test_util_stringToTokenArray_count_less_str_tokens() {
    char * arr[1];
    char * str = strdup("test test");
    stringToTokenArray(str, arr, " ", 1);
    TEST_ASSERT_EQUAL_MEMORY(str,arr[0],sizeof(*str));
    free(str);
}

void test_util_stringToTokenArray_count_equal_str_tokens() {
    char * arr[3];
    char * str = strdup("one two");
    stringToTokenArray(str, arr, " ", 3);
    TEST_ASSERT_EQUAL_STRING("one",arr[0]);
    TEST_ASSERT_EQUAL_STRING("two",arr[1]);
    TEST_ASSERT_NULL(arr[2]);
    free(str);
}

void test_unit_util() {
    RUN_TEST(test_util_countTokens_NULL_str);
    RUN_TEST(test_util_countTokens_str_no_tokens);
    RUN_TEST(test_util_countTokens_str_two_tokens);
    RUN_TEST(test_util_countTokens_str_a_lot_of_tokens);
    RUN_TEST(test_util_stringToTokenArray_str_null);
    RUN_TEST(test_util_stringToTokenArray_token_null);
    RUN_TEST(test_util_stringToTokenArray_count_0);
    RUN_TEST(test_util_stringToTokenArray_one_str_token);
    RUN_TEST(test_util_stringToTokenArray_count_less_str_tokens);
    RUN_TEST(test_util_stringToTokenArray_count_equal_str_tokens);
    RUN_TEST(test_util_stringToTokenArray_token_zero_len);
}
