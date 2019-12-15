/* STANDARD HEADERS */
#include <stdio.h>
#include <stdlib.h>

/* LOCAL HEADERS */
#include "unity.h"

/* MESSAGE TESTS */
#include "../include/message.h"

void test_message_alloc();

void test_message_reset();

void test_message_free();

void test_message_set_data_works();

void test_message_set_data_null_msg();

void test_message_set_data_null_data();

void test_message_set_data_size_zero();

void test_message_set_data_diff_data();

void test_message_set_timestamp();

void test_unit_message_file(); // File that holds all RUN_TEST calls


/* ERROR TESTS */
#include "../include/error.h"

void test_errorLog_alloc();

void test_errorLog_free();

void test_errorLog_create();

void test_errorLOg_log();

void test_error_getString();

void test_error_print();

void test_uliderror_MACRO();

void test_unit_error_file(); // Main callable file

/* SOCKET TESTS */
#include "../include/socket.h"

/* A mock server is setup under mock_lidar.c which is compiled
    separatley. This is used internally to test the socket class. */

void test_socket_free_sock_null();

void test_socket_alloc();

void test_socket_free();

void test_socket_setIP_sock_null();

void test_socket_setIP();

void test_socket_setIP_small_address();

void test_socket_setIP_large_address();

void test_socket_setPort_sock_null();

void test_socket_setPort_small_address();

void test_socket_setPort_large_address();

void test_socket_setPort();

void test_socket_setType_sock_null();

void test_socket_setType_UDP();

void test_socket_connect_null_sock();

void test_socket_connect_no_port();

void test_socket_connect_no_IP();

void test_socket_connect();

void test_socket_connect_alreadyConnected();

void test_socket_sendData_null_sock();

void test_socket_sendData_not_connected();

void test_socket_send_recv_data();

void test_socket_recvData_not_connected();

void test_unit_socket_file();

/* LIST TESTS */
#include "../include/list.h"

// TODO: 

void test_unit_list_file();


