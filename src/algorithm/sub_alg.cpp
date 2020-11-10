//-------------------------------------------------------------------------------------------------
// function:	performs substitution
// return:		true(success) OR false(failure)
//-------------------------------------------------------------------------------------------------
#include "calc.h"

namespace brb
{
	void Calc::sub_alg(Calc& num2)
	{
		//switch bigger number first
		{
			Calc org = *this;
			if(this->bs(num2) == Size::Smaller) {
				this->num_ = num2.num_;
				num2.num_ = org.num_;
			}
		}
		//reverse numbers
		std::reverse(num_.begin(), num_.end());
		std::reverse(num2.num_.begin(), num2.num_.end());

		//substraction
		for (size_t i = 0; i < num2.num_.size(); i++) {
			num_[i] -= num2.num_[i];
			if (num_[i] < 0) {
				num_[i + 1]--;
				num_[i] += 10;
			}
		}

		//remove front-zeros
		while (!num_.empty() && num_.back() == 0)
			num_.pop_back();

		//check for empty vector
		if (num_.empty())
			num_.emplace_back(0);

		//reverse right way around
		std::reverse(num_.begin(), num_.end());
	}
}