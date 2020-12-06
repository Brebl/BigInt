//-------------------------------------------------------------------------------------------------
//function:		Initialize calculation
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::init(const Calc& num2, const Calculation c)
	{
		//check for positive values
		validate(*this);
		validate(num2);

		//get sign for answer
		final_sign_ = setSign(c, bs(num2), *this, num2);
	}
}