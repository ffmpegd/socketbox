#ifndef __SOCKET_HANDLER_H__
#define __SOCKET_HANDLER_H__


class SocketHandler
{
private:
	int socketfd;

public:
	SocketHandler()
	{
		socketfd = InvalidSocket();
	}
	SocketHandler(const int fd)
	{
		socketfd = fd;
	}

public:
	void SetHandler(const int fd)
	{
		socketfd = fd;
	}
	const int GetHandler(void) const
	{
		return socketfd;
	}
	const bool IsValid(void) const
	{
		return (InvalidSocket() != socketfd);
	}
	const int InvalidSocket(void) const
	{
		return -1;
	}
};

#endif//__SOCKET_HANDLER_H__
