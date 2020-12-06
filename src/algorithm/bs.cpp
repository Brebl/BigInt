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
		if (num_.size() == n2.num_.size()) {
			for (size_t i = 0; i < num_.size(); i++) {
				if (num_[i] > n2.num_[i])
					return Size::Bigger;
				if (n2.num_[i] > num_[i])
					return Size::Smaller;
			}
			//fractions check here
			//return Size::Bigger; 
			//return Size::Smaller;

			return Size::Bigger;	// option to return Size::Equal
		}

		//different amount of numbers
		if (num_.size() > n2.num_.size()) {
			return Size::Bigger;
		}
		if (num_.size() < n2.num_.size()) {
			return Size::Smaller;
		}

		//Size failure
		assert(false && "wtf!?");
		return Size::Bigger;
	}
}
