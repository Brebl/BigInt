// ------------------------------------------------------------------------------------------------
// function:	Tells whether the first number is greater or smaller than the second
// n2:			Second number
// return:		Size::Bigger OR Size::Smaller
// ------------------------------------------------------------------------------------------------

/*
Todo:
-check fractions
*/

#include "pch.h"

namespace brb
{
	const Calc::Bs Calc::compare(const Vector& n1, const Vector& n2)
	{
		//same ammount of numbers
		if (n1.size() == n2.size()) {
			for (auto i = n1.rbegin(), j = n2.rbegin(); i != n1.rend(); i++, j++) {
				if (*i > *j)
					return Bs::Bigger;
				if (*i < *j)
					return Bs::Smaller;
			}
			return Bs::Bigger;	// option to return Size::Equal
		}

		//different amount of numbers
		if (n1.size() > n2.size()) {
			return Bs::Bigger;
		}
		if (n1.size() < n2.size()) {
			return Bs::Smaller;
		}

		//Size failure
		assert(false && "wtf!?");
		return Bs::Bigger;
	}
}
