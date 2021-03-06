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

/* QNODE TESTS */

#include "../include/qnode.h"

void test_qnode_free_NULL();
void test_qnode_alloc();
void test_qnode_free();
void test_qnode_setData_null_data();
void test_qnode_setData_null_node();
void test_qnode_setData_node_data_set();
void test_qnode_setData();
void test_qnode_connect_curr_null();
void test_qnode_connect_next_null();
void test_qnode_connect_next_set();
void test_unit_qnode();

/* FIFO QUEUE TESTS */

#include "../include/fifo.h"

void test_fifo_alloc_general();
void test_fifo_setMaxSize_queue_null();
void test_fifo_setMaxSize_100();
void test_fifo_setMaxSize_0();
void test_fifo_setMaxSize_net_10();
void test_fifo_getSize_queue_null();
void test_fifo_getSize_init();
void test_fifo_free_queue_null();
void test_fifo_free_queue_full();
void test_fifo_free_init();
void test_fifo_push_queue_null();
void test_fifo_push_data_null();
void test_fifo_pop_queue_null();
void test_fifo_setType_queue_null();
void test_fifo_setType_string_null();
void test_fifo_push_one_message();
void test_fifo_pop_one_message();
void test_fifo_push_two_message();
void test_fifo_pop_two_message();
void test_fifo_push_pop_5_message();
void test_unit_fifo();

/* LIDAR TESTS */

#include "../include/lidar.h"

void test_unit_lidar();

/* SOPAS TESTS */

#include "../include/sopas.h"

void test_sopas_free_null();
void test_sopas_alloc();
void test_sopas_scanOnce_null_parameters();
void test_unit_sopas();

/* UTIL TESTS */

#include "../include/util.h"

void test_util_countTokens_NULL_str();
void test_util_countTokens_str_no_tokens();
void test_util_countTokens_str_two_tokens();
void test_util_countTokens_str_a_lot_of_tokens();
void test_util_stringToTokenArray_str_null();
void test_util_stringToTokenArray_token_null();
void test_util_stringToTokenArray_count_0();
void test_util_stringToTokenArray_one_str_token();
void test_util_stringToTokenArray_count_less_str_tokens();
void test_util_stringToTokenArray_count_equal_str_tokens();
void test_util_stringToTokenArray_token_zero_len();
void test_unit_util();

/* TELEGRAM TESTS */

#include "../include/telegram.h"

void test_telegram_free_null();
void test_telegram_alloc();
void test_unit_telegram();
