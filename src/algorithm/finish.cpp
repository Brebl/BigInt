//-------------------------------------------------------------------------------------------------
//function:		finish the calculation
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::finish()
	{
		sign_ = final_sign_;
		if (remainder_ == Zero.num_) {
			divisor_ = Zero.num_;
		}
		validate(*this);
	}
}