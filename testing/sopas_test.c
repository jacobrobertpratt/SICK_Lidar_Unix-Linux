
#include "test.h"

void test_sopas_free_null() {
    Sopas * sopas = NULL;
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL, sopas_free(&sopas));
}

void test_sopas_alloc() {
    Sopas * sopas = sopas_alloc();
    TEST_ASSERT_EQUAL_HEX(SOPAS_STRUCT_CODE,sopas->struct_code);
    TEST_ASSERT_EQUAL_INT(0, sopas->level);
    for(int i = 0; i < 9; i++)
        TEST_ASSERT_EQUAL_INT(0,sopas->password[i]);
    TEST_ASSERT_NOT_NULL(sopas->sock);
    sopas_free(&sopas);
    TEST_ASSERT_NULL(sopas);
}

void test_sopas_scanOnce_null_parameters() {
    Sopas * sopas = NULL;
    Telegram * tele = NULL;
    TEST_ASSERT_EQUAL_INT(sopas_scanOnce(sopas,tele),ERROR_TYPENULL);
    sopas = sopas_alloc();
    TEST_ASSERT_EQUAL_INT(sopas_scanOnce(sopas,tele),ERROR_SOCKCONNECT);
    sopas_free(&sopas);
}

void test_sopas_scanOnce_() {
    /* TODO: Test sopas with an allocated sopas struct and connect to the
        mock lidar which is in the tests folder. Then check results against a
        local version of the results. */
    
    // Currently need to fix how to access mock lidar. 
}

void test_unit_sopas() {
    RUN_TEST(test_sopas_free_null);
    RUN_TEST(test_sopas_alloc);
    RUN_TEST(test_sopas_scanOnce_null_parameters);
    //RUN_TEST();
}
