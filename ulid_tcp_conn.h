#ifndef __ULID_TCP_CONNECTION__
#define __ULID_TCP_CONNECTION__

#include "ulid_common.h"

/* CreateSocketStruct()
*  @param none
*  @return A TcpSocket structure that is allocated. Sets all integers to 0, all structures
*          to NULL. Returns NULL on failure.
*  Must remember to deallocate the TcpSocket strut using DestroySocket(TcpSocket * socket)
*/
TcpSocket * TCPCreateSocketStruct();


/*  TCPDestroySocket(TcpSocket * sock)
 *  */
int TCPDestroySocket(TcpSocket * sock);


/*  TCPSetIPAddress(Lidar * lidar, const char * address)
 *  */
int TCPSetIPAddress(Lidar * lidar, const char * address);


/*  TCPSetPortNumber(Lidar * lidar, const char * port)
 *  */
int TCPSetPortNumber(Lidar * lidar, const char * port);


/*  TCPCreateConnection(TcpSocket * sock)
 *  */
int TCPCreateConnection(TcpSocket * sock);


/*  TCPCloseConnection(TcpSocket * sock)
 *  */
int TCPCloseConnection(TcpSocket * sock);


/*  TCPExchangeMessage(TcpSocket * sock, Message * packet)
 *   */
int TCPExchangeMessage(TcpSocket * sock, char * sendMsg, char * retMsg);



#endif
