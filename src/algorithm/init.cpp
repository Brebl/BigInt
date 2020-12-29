//-------------------------------------------------------------------------------------------------
//function:		Initialize calculation
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::init(Calc& num2, const Calculation c)
	{
		this->validate();
		num2.validate();

		this->imp_frac();
		num2.imp_frac();

		lcd(*this, num2);

		//get sign for answer
		final_sign_ = setSign(c, compare(this->numerator_, num2.numerator_), *this, num2);
	}
}