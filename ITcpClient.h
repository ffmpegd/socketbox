#ifndef __ITCPCLIENT_H__
#define __ITCPCLIENT_H__
#include "ISocket.h"

class ITcpClient : public ISocket
{
public:
	virtual bool Connect(const IString& ip, int port){IDebug::Assert(__func__);}
};

#endif//__ITCPCLIENT_H__
