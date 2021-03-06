//-------------------------------------------------------------------------------------------------
// function:	user interface function for division
//-------------------------------------------------------------------------------------------------

/*
todo:

*/
#include "pch.h"

namespace brb
{
	Calc Calc::operator /=(Calc num2)	//this /= num2
	{
		try
		{
			Calc answ = *this;	//in case of throw, no modifications to *this
			answ.init(num2, Calculation::Div);

			answ.mul_alg(answ.denominator_, num2.numerator_);
			answ.mul_alg(answ.numerator_, num2.denominator_);

			answ.finish();
			answ.errors_ = false;
			return *this = answ;
		}
		catch (const std::exception& e)
		{
			brb::err("Division failure: ", e.what());
			errors_ = true;
			return *this;
		}
	}

	Calc Calc::operator /(const Calc& num2) const		// answ = this / num2
	{
		Calc answ = *this;
		answ /= num2;
		return answ;
	}
}





