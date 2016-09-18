#ifndef __IUDPSERVER_H__
#define __IUDPSERVER_H__
#include "ISocket.h"

class IUdpServer : public ISocket
{
public:
	virtual bool Bind(const class IString& ip, int port){IDebug::Assert(__func__);}
};

#endif//__IUDPSERVER_H__
