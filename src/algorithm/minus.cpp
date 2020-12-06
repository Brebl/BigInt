//-------------------------------------------------------------------------------------------------
// function:	user interface function for substraction
//-------------------------------------------------------------------------------------------------

/*
P�ivitykset:

Todo:
-Murtolukujen huomioiminen
*/

#include "pch.h"

namespace brb
{
	Calc Calc::operator -=(Calc num2)	// this -= num2
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
			answ.errors_ = false;
			return *this = answ;
		}
		catch (const std::exception& e)
		{
			brb::err("Substraction failure: ", e.what());
			errors_ = true;
			return *this;
		}
	}

	Calc Calc::operator -(const Calc& num2) const		// answ = this - num2
	{
		Calc answ = *this;
		answ += num2;
		return answ;
	}

	Calc& Calc::operator --()	//Predecrement
	{
		*this -= One;
		return *this;
	}

	Calc Calc::operator --(int)	//postdecrement
	{
		Calc temp = *this;
		--* this;
		return temp;
	}
}
