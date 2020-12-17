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
	void Calc::div_alg(Calc& num2)
	{
		//check num2
		if (num2.whole_ == Zero.whole_ && num2.numerator_ == Zero.numerator_) {
			throw std::runtime_error("cannot divide by zero");
		}

		//settings
		const Sign fi_sign = this->final_sign_;
		this->sign_ = Sign::Positive;
		num2.sign_ = Sign::Positive;
		Calc num1 = *this;
		const Calc c_div = num2; //constant divider 

		//calculate whole
		whole_ = One.whole_;
		while (num1.bs(num2) == Size::Bigger) {
			this->add_alg(One);
			num2.add_alg(c_div);
		}

		//calculate part
		if (num1.bs(num2) == Size::Smaller) {
			this->sub_alg(One);
			num2.sub_alg(c_div);
			num1.sub_alg(num2);
			numerator_ = num1.whole_;		//becomes zero if division goes equal
			denominator_ = c_div.whole_;
			if (numerator_ != Zero.whole_) {
				downsize(*this);
			}
		}
		
		this->final_sign_ = fi_sign;
	}
}