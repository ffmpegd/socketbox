#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include "LinuxSocketOption.h"

bool LinuxSocketOption::AttachSocket(const ISocket& s)
{
	handler = s.GetSocketHandler();
	return handler.IsValid();
}

bool LinuxSocketOption::EnableReuseAddress(void)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	unsigned int flag = 1, len = sizeof(flag);
	return (setsockopt(handler.GetHandler(), SOL_SOCKET, SO_REUSEADDR, &flag, len)==0);
}
bool LinuxSocketOption::DisableReuseAddress(void)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	unsigned int flag = 0, len = sizeof(flag);
	return (setsockopt(handler.GetHandler(), SOL_SOCKET, SO_REUSEADDR, &flag, len)==0);
}
bool LinuxSocketOption::GetSocketError(int & e)
{	
	if( false == handler.IsValid() )
	{
		return false;
	}
	unsigned int len = sizeof(e);
	return (getsockopt(handler.GetHandler(), SOL_SOCKET, SO_ERROR, &e, &len)==0);
}
bool LinuxSocketOption::EnableBlock(void)
{	
	if( false == handler.IsValid() )
	{
		return false;
	}
	int flags = fcntl(handler.GetHandler(), F_GETFL, 0);
	if( -1 == flags )
	{
		return false;
	}
	return (fcntl(handler.GetHandler(), F_SETFL, flags & ~O_NONBLOCK)==0);
}
bool LinuxSocketOption::DisableBlock(void)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
	int flags = fcntl(handler.GetHandler(), F_GETFL, 0);
	if( -1 == flags )
	{
		return false;
	}
	return (fcntl(handler.GetHandler(), F_SETFL, flags | O_NONBLOCK)==0);
}
