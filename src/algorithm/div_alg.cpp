//-------------------------------------------------------------------------------------------------
//function:		Performs division
//-------------------------------------------------------------------------------------------------
/*
update:
-cannot divide by zero
*/

#include "pch.h"

namespace brb
{
	void Calc::div_alg(const Vector& n1, const Vector& n2, Vector& whole, Vector& numer, Vector& denom)
	{
		//check num2
		if (n2 == Zero.whole_) {
			throw std::runtime_error("cannot divide by zero");
		}

		//settings
		Vector temp = Zero.whole_; 
		whole = Zero.whole_;
		numer = n1;
		denom = n2;

		//calculate whole
		while (compare(n1, temp) == Bs::Bigger) {
			add_alg(whole, One.whole_);
			add_alg(temp, n2);
		}

		//calculate part
		if (compare(n1, temp) == Bs::Smaller) {
			sub_alg(whole, One.whole_);
			sub_alg(temp, n2);
			sub_alg(numer, temp);		//becomes zero if division goes equal
		}
	}
}