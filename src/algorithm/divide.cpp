//-------------------------------------------------------------------------------------------------
// function:	user interface function for division
// return:		true(succeess), false(failure)
//-------------------------------------------------------------------------------------------------

/*
todo:

*/
#include "calc.h"

namespace brb
{
	bool Calc::divide(Calc num2)
	{
		try
		{
			//use this as a backup
			Calc answ = *this;

			//init
			answ.init(num2, Calculation::Div);

			//division
			answ.div_alg(num2);

			//finishing touch
			answ.finish();
			*this = answ;
			return true;
		}
		catch (const std::exception& e)
		{
			brb::err("Division failure: ", e.what());
			return false;
		}
	}
}





