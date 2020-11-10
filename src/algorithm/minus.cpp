//-------------------------------------------------------------------------------------------------
// function:	user interface function for substraction
// return:		true(success), false(failure)
//-------------------------------------------------------------------------------------------------

/*
Päivitykset:

Todo:
-Murtolukujen huomioiminen
*/

#include "calc.h"

namespace brb
{
	bool Calc::minus(Calc num2)
	{
		try
		{
			//use this as a backup
			Calc answ = *this;

			//init
			answ.init(num2, Calculation::Sub);

			//substraction if same signs
			if (answ.sign_ == num2.sign_) {
				answ.sub_alg(num2);
			}
			//addition if different signs
			else {
				answ.add_alg(num2);
			}

			//finish
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