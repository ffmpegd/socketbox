#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include "LinuxTcpOption.h"

bool LinuxTcpOption::AttachSocket(const ISocket& s)
{
	handler = s.GetSocketHandler();	
	return handler.IsValid();
}
bool LinuxTcpOption::GetTcpInfo(LinuxTcpInfo& info)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	socklen_t len = info.GetLength();
	return getsockopt(handler.GetHandler(), IPPROTO_TCP, TCP_INFO, info.GetBuffer(), &len)==0;
}
