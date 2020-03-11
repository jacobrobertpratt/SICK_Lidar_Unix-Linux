
#include "test.h"

// Create an exact response image from the TIM551 lidar
const char * mockRetMsg = "sRA LMDscandata 1 1 F510AB 0 0 5932 5933 5B87697D 5B88808C 0 0 1 0 0 5DC 36 0 1 DIST1 3F800000 00000000 FFF92230 2710 10F 292 290 28D 291 290 28F 27B 269 28B 28D 28C 28E 28E 28F 28E 290 290 293 298 299 297 294 29B 298 2A2 29B 1F3 191 191 19E 195 19F 234 2C0 2D0 2CD 2D5 2D5 2E6 2F0 2F6 2F6 300 310 2BA 2B6 2C4 2D6 2E7 2F2 2F7 2FA 303 30D 319 333 347 356 361 371 388 39E 3A5 3C1 388 1C6 19C 19F 1A9 1A4 1A8 1A0 4C7 510 537 56A 5A4 5DB 62C 66F 6C2 72D 785 7FD 895 973 92E 938 928 91F 917 911 916 956 A90 0 B79 B55 BAA BC5 AE2 B3B B84 BC3 BCE BD2 868 77F 6B9 6C1 6C6 6D5 6DB 6E5 6F3 6ED 6FB 706 70F 719 72E 738 746 751 75B 770 77B 792 7A3 7B1 7D3 7E2 7F6 811 822 83E 847 876 F16 84A E73 644 CCC 569 B90 B91 BD0 CCD D26 CF8 CCA CA1 C71 C49 C25 BFF BCC BA3 BD3 D23 E4B 1724 17E7 18C1 19A9 1265 1250 1232 1212 11F1 11D4 11B8 1195 125F 1391 14E2 1669 1868 199D 1995 197C 196D 1961 1955 1898 95E 956 957 95F 95E 953 95C 956 95B 963 91F 865 6A4 5F8 513 50C 4F 8E B0 B5 BE CA CC D1 D3 D4 DB CE D2 D5 D2 D4 D4 CD D9 DE D1 CF D7 D3 CD D2 D4 D4 D3 C6 B1 9D 94 0 0 370 367 346 223 221 225 224 26D 317 30E 30A 303 2F5 2ED 2D1 2CC 2D7 2D1 233 298 2BF 2B6 2AF 2AC 2A9 2A5 29E 2A0 299 296 292 294 28E 289 289 1 RSSI1 3F800000 00000000 FFF92230 2710 10F E6 E6 E6 E6 E6 E6 C3 B0 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E6 E1 E6 DB E6 D8 BD C3 C3 CB C8 C0 95 D8 E6 DB DE DB E6 E6 E6 DB E1 E6 D3 D0 CB C8 C8 D8 D6 D3 D0 D3 C8 C6 C0 CE C8 C6 C8 C8 BB C0 A5 9A B0 CB CE CB CB";

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

void test_sopas_scanOnce_mock_lidar() {
    
    // GENERAL STRUCTURE OF PROGRAM
    Sopas * sopas = sopas_alloc();
    Telegram * tele = telegram_alloc();
    
    socket_setIP(sopas->sock, "127.0.0.1"); // local IP address
    socket_setPort(sopas->sock, 9999); // test port number matches with Mock Lidar
    socket_connect(sopas->sock);
    
    if(sopas->sock->connected)
        TEST_MESSAGE("socket connected");
    
    sopas_scanOnce(sopas, tele);
    
    telegram_free(&tele);
    
    sopas_free(&sopas);
}

void test_unit_sopas() {
    RUN_TEST(test_sopas_free_null);
    RUN_TEST(test_sopas_alloc);
    RUN_TEST(test_sopas_scanOnce_null_parameters);
    RUN_TEST(test_sopas_scanOnce_mock_lidar);
}
