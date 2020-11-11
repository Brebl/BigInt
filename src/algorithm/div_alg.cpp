//-------------------------------------------------------------------------------------------------
//function:		Performs division
//-------------------------------------------------------------------------------------------------
/*
update:
-cannot divide by zero
*/

#include "calc.h"

namespace brb
{
	void Calc::div_alg(Calc& num2)
	{
		//check num2
		if (num2.num_ == Zero.num_ && num2.remainder_ == Zero.remainder_) {
			throw std::runtime_error("cannot divide by zero");
		}

		//settings
		const Sign fi_sign = this->final_sign_;
		this->sign_ = Sign::Positive;
		num2.sign_ = Sign::Positive;
		Calc num1 = *this;
		const Calc c_div = num2; //constant divider 

		//calculate whole
		this->num_ = One.num_;
		while (num1.bs(num2) == Size::Bigger) {
			this->plus(One);
			num2.plus(c_div);
		}

		//calculate part
		if (num1.bs(num2) == Size::Smaller) {
			this->minus(One);
			num2.minus(c_div);
			num1.minus(num2);
			remainder_ = num1.num_;		//becomes zero if division goes equal
			divisor_ = c_div.num_;
		}
		
		//downsizing
		downsize(*this);

		this->final_sign_ = fi_sign;
	}
}