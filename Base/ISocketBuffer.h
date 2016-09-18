#ifndef __ISOCKETBUFFER_H__
#define __ISOCKETBUFFER_H__
#include "IDebug.h"

class ISocketBuffer
{
public:
	virtual bool Alloc(int size){IDebug::Assert(__func__);}
	virtual void *GetData(void){IDebug::Assert(__func__);}

	virtual void  SetLength(int){IDebug::Assert(__func__);}
	virtual const int GetLength(void) const {IDebug::Assert(__func__);}

	virtual const void SetResult(int){IDebug::Assert(__func__);}
	virtual const int GetResult(void) const {IDebug::Assert(__func__);}

	virtual const int GetSize(void) const {IDebug::Assert(__func__);}

public:
	virtual ISocketBuffer& operator=(ISocketBuffer& b){IDebug::Assert(__func__);}
	virtual ISocketBuffer& operator=(const class IString& s){IDebug::Assert(__func__);}
};

#endif//__ISOCKETBUFFER_H__
