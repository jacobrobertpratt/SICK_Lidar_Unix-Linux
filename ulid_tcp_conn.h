#ifndef __ULID_TCP_CONNECTION__
#define __ULID_TCP_CONNECTION__

#include "ulid_common.h"

/*  */
int SetIPAddress(Lidar * lidar, const char * address);

/*  */
int CreateTCPConnection(TcpSocket * sock);

/*  */
int DestroyTCPConnection(TcpSocket * sock);

/*  */
int ExchangeTCPMessage(TcpSocket * sock, Message * packet);

#endif
