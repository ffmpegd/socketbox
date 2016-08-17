#ifndef __SOCKET_BUFFER_H__
#define __SOCKET_BUFFER_H__
#include "ISocketBuffer.h"

class SocketBuffer : public ISocketBuffer
{
private:
	char *data;
	int size;
	int length;
	int result;

public:
	SocketBuffer(void);
	~SocketBuffer(void);
	SocketBuffer(int);
	SocketBuffer(const class IString&);

public:
	bool Alloc(int size);
	void *GetData(void);

	void  SetLength(int);
	const int GetLength(void) const;

	const void SetResult(int);
	const int GetResult(void) const;

	const int GetSize(void) const;

public:
	ISocketBuffer& operator=(ISocketBuffer& b);
	ISocketBuffer& operator=(const class IString& s);
};

#endif//__SOCKET_BUFFER_H__
