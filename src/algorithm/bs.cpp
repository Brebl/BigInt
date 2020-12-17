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
	const Calc::Size Calc::bs(const Calc& n2)
	{
		//same ammount of numbers
		if (whole_.size() == n2.whole_.size()) {
			for (size_t i = 0; i < whole_.size(); i++) {
				if (whole_[i] > n2.whole_[i])
					return Size::Bigger;
				if (n2.whole_[i] > whole_[i])
					return Size::Smaller;
			}
			//fractions check here
			//return Size::Bigger; 
			//return Size::Smaller;

			return Size::Bigger;	// option to return Size::Equal
		}

		//different amount of numbers
		if (whole_.size() > n2.whole_.size()) {
			return Size::Bigger;
		}
		if (whole_.size() < n2.whole_.size()) {
			return Size::Smaller;
		}

		//Size failure
		assert(false && "wtf!?");
		return Size::Bigger;
	}
}
