// ------------------------------------------------------------------------------------------------
// function:	check that calculation had no errors and current result is accurate
// ------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	Calc::operator bool() const
	{
		return !errors_;
	}
}