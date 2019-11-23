
#include "test.h"

void test_socket_free_sock_null() {
    int ret = 0;
    Socket * sock = NULL;
    ret = socket_free(sock);
    TEST_ASSERT_TRUE(ret == ERROR_TYPENULL);
}

void test_socket_alloc() {
    Socket * sock = socket_alloc();
    TEST_ASSERT_NOT_NULL(sock);
    
    TEST_ASSERT_TRUE(sock->sockid == 0);
    TEST_ASSERT_TRUE(sock->port == 0);
    TEST_ASSERT_TRUE(sock->type == TCP);
    TEST_ASSERT_TRUE(sock->ip == NULL);
    
    socket_free(sock);
}

void test_socket_free() {
    int ret = 0;
    Socket * sock = socket_alloc();
    TEST_ASSERT_NOT_NULL(sock);
    ret = socket_free(sock);
    TEST_ASSERT_TRUE(ret == 0);
}

void test_socket_setIP_sock_null() {
    int ret = 0;
    Socket * sock = NULL;
    ret = socket_setIP(sock, "123.123.123.123");
    TEST_ASSERT_TRUE(ret == ERROR_TYPENULL);
}

void test_socket_setIP() {
    int ret = 0;
    Socket * sock = socket_alloc();
    ret = socket_setIP(sock, "123.123.123.123");
    TEST_ASSERT_TRUE(ret == 0);
    TEST_ASSERT_EQUAL_STRING(sock->ip, "123.123.123.123");
    socket_free(sock);
}

void test_socket_setIP_small_address() {
    int ret = 0;
    Socket * sock = socket_alloc();
    ret = socket_setIP(sock, ".2.3.4");
    TEST_ASSERT_TRUE(ret == ERROR_STRING);
    socket_free(sock);
}

void test_socket_setIP_large_address() {
    int ret = 0;
    Socket * sock = socket_alloc();
    ret = socket_setIP(sock, "1234.123.123.123");
    TEST_ASSERT_TRUE(ret == ERROR_STRING);
    socket_free(sock);
}

void test_socket_setPort_sock_null() {
    int ret = 0;
    Socket * sock = NULL;
    ret = socket_setPort(sock, "1234");
    TEST_ASSERT_TRUE(ret == ERROR_TYPENULL);
}

void test_socket_setPort_small_address() {
    int ret = 0;
    Socket * sock = socket_alloc();
    ret = socket_setPort(sock, "");
    TEST_ASSERT_TRUE(ret == ERROR_STRING);
    socket_free(sock);
}

void test_socket_setPort_large_address() {
    int ret = 0;
    Socket * sock = socket_alloc();
    ret = socket_setPort(sock, "12345");
    TEST_ASSERT_TRUE(ret == ERROR_STRING);
    socket_free(sock);
}

void test_socket_setPort() {
    int ret = 0;
    Socket * sock = socket_alloc();
    ret = socket_setPort(sock, "1234");
    TEST_ASSERT_TRUE(ret == 0);
    TEST_ASSERT_TRUE(sock->port == 1234);
    socket_free(sock);
}

void test_socket_setType_sock_null() {
    int ret = 0;
    Socket * sock = NULL;
    ret = socket_setType(sock, TCP);
    TEST_ASSERT_TRUE(ret == ERROR_TYPENULL);
}

void test_socket_setType_UDP() {
    int ret = 0;
    Socket * sock = socket_alloc();
    ret = socket_setType(sock, UDP);
    TEST_ASSERT_TRUE(ret == 0);
    TEST_ASSERT_TRUE(sock->type == UDP);
    socket_free(sock);
}

void test_unit_socket_file() {
    RUN_TEST(test_socket_free_sock_null);
    RUN_TEST(test_socket_alloc);
    RUN_TEST(test_socket_free);
    RUN_TEST(test_socket_setIP_sock_null);
    RUN_TEST(test_socket_setIP);
    RUN_TEST(test_socket_setIP_small_address);
    RUN_TEST(test_socket_setIP_large_address);
    RUN_TEST(test_socket_setPort_sock_null);
    RUN_TEST(test_socket_setPort_small_address);
    RUN_TEST(test_socket_setPort_large_address);
    RUN_TEST(test_socket_setPort);
    RUN_TEST(test_socket_setType_sock_null);
    RUN_TEST(test_socket_setType_UDP);
}
