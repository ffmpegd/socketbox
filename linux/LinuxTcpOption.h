#ifndef __LINUXTCPOPTION_H__
#define __LINUXTCPOPTION_H__
#include "ISocketOption.h"
#include "LinuxTcpInfo.h"

class LinuxTcpOption : public ISocketOption
{
private:
	SocketHandler handler;

public:
	bool AttachSocket(const ISocket&);

public:
	bool GetTcpInfo(LinuxTcpInfo&);
};

#endif//__LINUXTCPOPTION_H__
