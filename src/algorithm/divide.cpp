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
			Calc answ = *this;	//in case of throw, use *this
			answ.init(num2, Calculation::Div);
			answ.div_alg(num2);
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





