//-------------------------------------------------------------------------------------------------
//function:		finish the calculation
//-------------------------------------------------------------------------------------------------

#include "calc.h"

namespace brb
{
	void Calc::finish()
	{
		//set sign
		sign_ = final_sign_;

		//final check
		validate(*this);
	}
}