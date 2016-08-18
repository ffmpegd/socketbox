#include <stdlib.h>
#include <string.h>
#include "IString.h"
#include "SocketBuffer.h"


SocketBuffer::SocketBuffer(void)
{
	data = (char*)0;	
	size = 0;
	length = 0;
	result = 0;
}
SocketBuffer::~SocketBuffer(void)
{	
	if( data )
	{
		delete data;
	}
	data = (char*)0;	
	size = 0;
	length = 0;
	result = 0;
}
SocketBuffer::SocketBuffer(int sz)
{
	data = (char*)0;	
	size = 0;
	length = 0;
	result = 0;
	Alloc(sz);
}
SocketBuffer::SocketBuffer(const IString& s)
{
	data = (char*)0;	
	size = 0;
	length = 0;
	result = 0;
	*this = s;
}

bool SocketBuffer::Alloc(int sz)
{
	if( data )
	{
		delete data;
		data = (char*)0;
	}
	data = new char[sz];
	if( data )
	{
		size = sz;
		length = 0;
		result = 0;
	}
	return !!data;
}
void* SocketBuffer::GetData(void)
{
	return (void*)data;
}

void  SocketBuffer::SetLength(int l)
{
	length = l;
}
const int SocketBuffer::GetLength(void) const
{
	return length;
}

const void SocketBuffer::SetResult(int r)
{
	result = r;
}
const int SocketBuffer::GetResult(void) const
{
	return result;
}

const int SocketBuffer::GetSize(void) const
{
	return size;
}

ISocketBuffer& SocketBuffer::operator=(ISocketBuffer& b)
{
	if( b.GetSize() > 0 && Alloc(b.GetSize()) )
	{
		memcpy(data, b.GetData(), size);	
		length = b.GetLength();
		result = b.GetResult();
	}
	return *this;
}
ISocketBuffer& SocketBuffer::operator=(const class IString& s)
{
	if( s.empty() || !Alloc(s.length()+1) )
	{
		if( data )
		{
			delete data;
		}
		data = (char*)0;
		size = 0;
		length = 0;
		result = 0;
	}
	memcpy(data, s.data(), size-1);
	result = length = size - 1;
	return *this;
}
