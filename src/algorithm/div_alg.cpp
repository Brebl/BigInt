//-------------------------------------------------------------------------------------------------
//function:		Performs division
//parameters:	
//n1			Quotient
//n2			Divisor
//whole			Answer whole
//numer			Answer numerator
//denom			Answer denominator
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::div_alg(const Vector& n1, const Vector& n2, Vector& whole, Vector& numer, Vector& denom)
	{
		if (n2 == Zero) {
			throw std::runtime_error("cannot divide by zero");
		}

		Vector temp = Zero; 
		whole = Zero;
		numer = n1;
		denom = n2;

		//optimize
		if(n2 == One) {
			whole = n1;
			numer = Zero;
			denom = One;
			return;
		}

		//calculate whole
		while (compare(n1, temp) == Bs::Bigger) {
			add_alg(whole, One);
			add_alg(temp, n2);
		}

		//calculate part
		if (compare(n1, temp) == Bs::Smaller) {
			sub_alg(whole, One);
			sub_alg(temp, n2);
			sub_alg(numer, temp);		//becomes zero if division goes equal
		}
	}
}