#include "pch.h"

namespace brb
{
	Calc::operator bool() const
	{
		return !errors_;
	}
}