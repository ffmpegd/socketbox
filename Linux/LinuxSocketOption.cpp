#include "LinuxSocketOption.h"

bool LinuxSocketOption::SetSocket(const ISocket& s)
{
	handler = s.GetSocketHandler();
}

bool LinuxSocketOption::EnableReuseAddress(void)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
}
bool LinuxSocketOption::DisableReuseAddress(void)
{
	if( false == handler.IsValid() )
	{
		return false;
	}
}
