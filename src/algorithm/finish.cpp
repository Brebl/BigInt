//-------------------------------------------------------------------------------------------------
//function:		finish the calculation
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::finish()
	{
		sign_ = final_sign_;
		if (numerator_ == Zero) {
			denominator_ = Zero;
		}
		this->prop_frac();
		this->validate();
	}
}