//-------------------------------------------------------------------------------------------------
//function:		finish the calculation
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::finish()
	{
		sign_ = final_sign_;
		if (numerator_ == Zero.whole_) {
			denominator_ = Zero.whole_;
		}
		validate(*this);
	}
}