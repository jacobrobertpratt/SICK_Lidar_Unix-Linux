
#include "test.h"

void test_telegram_free_null(){
    Telegram * tele = NULL;
    TEST_ASSERT_EQUAL_INT(ERROR_TYPENULL, telegram_free(&tele));
    TEST_ASSERT_NULL(tele);
}

void test_telegram_alloc() {
    Telegram * tele = NULL;
    tele = telegram_alloc();
    TEST_ASSERT_NOT_NULL(tele);
    TEST_ASSERT_EQUAL_INT(TELEGRAM_STRUCT_CODE, tele->struct_code);
    TEST_ASSERT_EQUAL_INT(0, tele->device_number);
    TEST_ASSERT_EQUAL_INT(0, tele->device_timestamp);
    TEST_ASSERT_EQUAL_INT(0, tele->sys_timestamp);
    TEST_ASSERT_EQUAL_INT(0, tele->layer_angle);
    TEST_ASSERT_EQUAL_INT(0, tele->scan_freq.num);
    TEST_ASSERT_EQUAL_INT(0, tele->scan_freq.den);
    TEST_ASSERT_EQUAL_INT(0, tele->channel);
    TEST_ASSERT_EQUAL_INT(0, tele->dist_unit);
    TEST_ASSERT_EQUAL_INT(1, tele->scale_factor);
    TEST_ASSERT_EQUAL_INT(0, tele->start_angle.num);
    TEST_ASSERT_EQUAL_INT(0, tele->start_angle.den);
    TEST_ASSERT_EQUAL_INT(1, tele->angular_step.num);
    TEST_ASSERT_EQUAL_INT(1, tele->angular_step.den);
    TEST_ASSERT_EQUAL_INT(0, tele->data_count);
    TEST_ASSERT_EQUAL_INT(0, tele->data_format);
    TEST_ASSERT_NULL(tele->data);
    // ensures the structure size is the same -> test with a main()
    TEST_ASSERT_EQUAL_UINT32(72,sizeof(*tele));
    telegram_free(&tele);
}

void test_unit_telegram() {
    RUN_TEST(test_telegram_free_null);
    RUN_TEST(test_telegram_alloc);
}
