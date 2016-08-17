#ifndef __ISOCKET_H__
#define __ISOCKET_H__
#include "IDebug.h"
#include "IAddress.h"
#include "SocketHandler.h"
#include "ISocketBuffer.h"

class ISocket
{
public:
	virtual bool Open(void){IDebug::Assert(__func__);};
	virtual bool Close(void){IDebug::Assert(__func__);}
	virtual int  SocketDomain(void){IDebug::Assert(__func__);}
	virtual int  SocketType(void){IDebug::Assert(__func__);}
	virtual int  SocketProtocol(void){IDebug::Assert(__func__);}
	virtual bool Send(ISocketBuffer&){IDebug::Assert(__func__);}
	virtual bool Recv(ISocketBuffer&){IDebug::Assert(__func__);}
	virtual bool SendTo(IAddress&, ISocketBuffer&){IDebug::Assert(__func__);}
	virtual bool RecvFrom(IAddress&, ISocketBuffer&){IDebug::Assert(__func__);}
	virtual void SetSocketHandler(const SocketHandler&){IDebug::Assert(__func__);}
	virtual SocketHandler& GetSocketHandler(void){IDebug::Assert(__func__);}
};

#endif//__ISOCKET_H__
