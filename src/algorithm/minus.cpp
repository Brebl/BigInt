//-------------------------------------------------------------------------------------------------
// function:	user interface function for substraction
// return:		true(success), false(failure)
//-------------------------------------------------------------------------------------------------

/*
P�ivitykset:

Todo:
-Murtolukujen huomioiminen
*/

#include "calc.h"

namespace brb
{
	bool Calc::operator -=(Calc num2)
	{
		try
		{
			Calc answ = *this;	//in case of throw, no modifications to *this
			answ.init(num2, Calculation::Sub);
			//substraction if same signs
			if (answ.sign_ == num2.sign_) {
				answ.sub_alg(num2);
			}
			//addition if different signs
			else {
				answ.add_alg(num2);
			}
			answ.finish();
			*this = answ;
			return true;
		}
		catch (const std::exception& e)
		{
			brb::err("Substraction failure: ", e.what());
			return false;
		}
	}
}