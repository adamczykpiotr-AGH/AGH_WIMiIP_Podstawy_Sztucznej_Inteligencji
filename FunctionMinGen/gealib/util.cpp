#include "util.h"
#include <math.h>
#include <type_traits>

using namespace gealib;

#pragma warning(push)
#pragma warning(disable:4244)

longint gealib::uround(ftype val)
{
	if (std::is_same<ftype, double>::value)
	{
		if (sizeof(longint) == 64)
			return llround(val);
		else
			return lround(val);
	}
	else
	{
		if (sizeof(longint) == 64)
			return llroundf(val);
		else
			return lroundf(val);
	}
}
#pragma warning(pop)