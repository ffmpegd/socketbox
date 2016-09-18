#ifndef __ITCPSERVER_H__
#define __ITCPSERVER_H__
#include "ISocket.h"

class ITcpServer : public ISocket
{
public:
	virtual bool Bind(const class IString &ip, int port){IDebug::Assert(__func__);}
	virtual bool Listen(int backlog){IDebug::Assert(__func__);}
	virtual bool Accept(class ISocket &s){IDebug::Assert(__func__);}
};

#endif//__ITCPSERVER_H__
