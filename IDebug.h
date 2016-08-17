#ifndef __IDEBUG_H__
#define __IDEBUG_H__

class IDebug
{
public:
	static void Assert(const char *s){*(char*)0=0;}
};

#endif//__IDEBUG_H__
