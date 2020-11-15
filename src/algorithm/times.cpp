//-------------------------------------------------------------------------------------------------
// function:	user interface function for multiplication
// return:		true(succeess), false(failure)
//-------------------------------------------------------------------------------------------------
/*
Päivitykset:

Todo:
-Murtolukujen huomioiminen

*/

#include "calc.h"

namespace brb
{
	Calc Calc::operator *=(Calc num2)		//this *= num2
	{
		try
		{
			Calc answ = *this;	//in case of throw, no modifications to *this
			answ.init(num2, Calculation::Mul);
			answ.mul_alg(num2);
			answ.finish();
			answ.errors_ = false;
			return *this = answ;
		}
		catch (const std::exception& e)
		{
			brb::err("Multiplication failure: ", e.what());
			errors_ = true;
			return *this;
		}
	}

	Calc Calc::operator *(const Calc& num2) const		// answ = this * num2
	{
		Calc answ = *this;
		answ *= num2;
		return answ;
	}
}
