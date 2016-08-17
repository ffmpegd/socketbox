#ifndef __ISOCKETBUFFER_H__
#define __ISOCKETBUFFER_H__

class ISocketBuffer
{
public:
	virtual void *GetData(void){IDebug::Assert(__func__);}
	virtual void  SetLength(int){IDebug::Assert(__func__);}
	virtual const int   GetLength(void){IDebug::Assert(__func__);}
	virtual void  SetResult(int){IDebug::Assert(__func__);}
	virtual const int   GetResult(void){IDebug::Assert(__func__);}
	virtual const int   GetSize(void){IDebug::Assert(__func__);}
};

#endif//__ISOCKETBUFFER_H__
