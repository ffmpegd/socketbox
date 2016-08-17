#ifndef __LINUX_SOCKET_OPTION_H__
#define __LINUX_SOCKET_OPTION_H__
#include "ISocket.h"

class LinuxSocketOption : public ISocketOption
{
private:
	SocketHandler handler;

public:
	bool SetSocket(const ISocket&);
	bool EnableReuseAddress(void);
	bool DisableReuseAddress(void);
};

#endif//__LINUX_SOCKET_OPTION_H__
