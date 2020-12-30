//-------------------------------------------------------------------------------------------------
//function:		downsize fractions
//-------------------------------------------------------------------------------------------------
/*
todo:
timer
*/
#include "pch.h"

namespace brb 
{
	void Calc::downsize(Calc& n1)
	{
		Vector counter {2};
		Vector numerator, denominator, temp1, temp2;

		//check if n1 is downsizeable
		if(n1.numerator_ == Zero){
			return;
		}

		do {
			//is numerator divisible with counter?
			div_alg(n1.numerator_,counter,numerator,temp1,temp2);
			if(temp1 != Zero) {
				//if not
				add_alg(counter, One);
				continue;
			}

			//is denominator divisible with counter?
			div_alg(n1.denominator_,counter,denominator,temp1,temp2);
			if(temp1 != Zero) {
				//if not
				add_alg(counter, One);
				continue;
			}

			//downsize
			n1.numerator_ = numerator;
			n1.denominator_ = denominator;
			brb::log("downsize succsess", "", Mode::debug_only);
			counter = Vector{2};

		} while (compare(counter, n1.numerator_) == Bs::Smaller);
	}
}
