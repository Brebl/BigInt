#include "calc.h"

namespace brb
{
	Calc::operator bool() const
	{
		return !errors_;
	}
}