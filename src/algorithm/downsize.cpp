//-------------------------------------------------------------------------------------------------
//function:		downsize fractions
//-------------------------------------------------------------------------------------------------
/*
todo:
timer
*/
#include "calc.h"

namespace brb 
{
	void Calc::downsize(Calc& n1)
	{
		//make new objects from remainder and divisor
		std::stringstream ss;
		for (auto&& i : n1.remainder_) {
			ss << i;
		}
		if (ss.bad()) {
			throw std::runtime_error("downsize failure");
		}
		Calc remainder{ ss.str() };
		ss.str(std::string());	//reset
		ss.clear();

		for (auto&& i : n1.divisor_) {
			ss << i;
		}
		if (ss.bad()) {
			throw std::runtime_error("downsize failure");
		}
		Calc divisor{ ss.str() };
		ss.str(std::string());
		ss.clear();

		//check if n1 is downsizeable
		Calc cntr{ "2" };
		Calc rem{ remainder };
		Calc div{ divisor };
		do {
			{//rem.divide(counter);
				Calc num1 = rem;
				Calc num2 = cntr;
				const Calc c_div = cntr;
				//calculate whole
				rem.num_ = One.num_;
				while (num1.bs(num2) == Size::Bigger) {
					rem += One;
					num2 += c_div;
				}
				//calculate part
				if (num1.bs(num2) == Size::Smaller) {
					rem -= One;
					num2 -= c_div;
					num1 -= num2;
					rem.remainder_ = num1.num_;		//becomes zero if division goes equal
				}
			}

			{//div.divide(counter);
				Calc num1 = div;
				Calc num2 = cntr;
				const Calc c_div = cntr;
				//calculate whole
				div.num_ = One.num_;
				while (num1.bs(num2) == Size::Bigger) {
					div += One;
					num2 += c_div;
				}
				//calculate part
				if (num1.bs(num2) == Size::Smaller) {
					div -= One;
					num2 -= c_div;
					num1 -= num2;
					div.remainder_ = num1.num_;
				}
			}

			//downsize
			if (rem.remainder_ == Zero.num_ && div.divisor_ == Zero.num_) {
				remainder = rem;
				divisor = div;
				cntr = Calc("2");
				brb::log("downsize succsess", "", mode::debug_only);
			}
			else {
				rem = remainder;
				div = divisor;
				cntr += One;
			}
		} while (cntr.bs(remainder) == Size::Smaller);

		n1.remainder_ = remainder.num_;
		n1.divisor_ = divisor.num_;
	}
}
