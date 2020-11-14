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
	bool Calc::operator *=(Calc num2)
	{
		try
		{
			Calc answ = *this;	//in case of throw, no modifications to *this
			answ.init(num2, Calculation::Mul);
			answ.mul_alg(num2);
			answ.finish();
			*this = answ;
			return true;
		}
		catch (const std::exception& e)
		{
			brb::err("Multiplication failure: ", e.what());
			return false;
		}
	}
}
