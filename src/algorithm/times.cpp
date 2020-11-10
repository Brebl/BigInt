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
	bool Calc::times(Calc num2)
	{
		try
		{
			//use this as a backup
			Calc answ = *this;

			//init
			answ.init(num2, Calculation::Mul);

			//multiplication
			answ.mul_alg(num2);

			//finishing touch
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
