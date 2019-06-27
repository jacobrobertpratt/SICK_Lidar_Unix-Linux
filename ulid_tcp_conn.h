#ifndef __ULID_TCP_CONNECTION__
#define __ULID_TCP_CONNECTION__
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
*/

#include "ulid_common.h"

/*  */
int CreateTCPConnection(TcpSocket * sock);

/*  */
int DestroyTCPConnection(TcpSocket * sock);

/*  */
int ExchangeTCPMessage(TcpSocket * sock, Message * packet);

#endif
