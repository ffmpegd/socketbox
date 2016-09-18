#ifndef __LINUX_SOCKET_OPTION_H__
#define __LINUX_SOCKET_OPTION_H__
#include "ISocketOption.h"

class LinuxSocketOption : public ISocketOption
{
private:
	SocketHandler handler;

public:
	bool AttachSocket(const ISocket&);

	bool EnableReuseAddress(void);
	bool DisableReuseAddress(void);

	bool GetSocketError(int&);

	bool EnableBlock(void);
	bool DisableBlock(void);
};

#endif//__LINUX_SOCKET_OPTION_H__
