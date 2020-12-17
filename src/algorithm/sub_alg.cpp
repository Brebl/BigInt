//-------------------------------------------------------------------------------------------------
// function:	performs substitution
// return:		true(success) OR false(failure)
//-------------------------------------------------------------------------------------------------
#include "pch.h"

namespace brb
{
	void Calc::sub_alg(Calc num2)
	{
		//switch bigger number first
		{
			Calc org = *this;
			if(this->bs(num2) == Size::Smaller) {
				this->whole_ = num2.whole_;
				num2.whole_ = org.whole_;
			}
		}

		//substraction
		for (size_t i = 0; i < num2.whole_.size(); i++) {
			whole_[i] -= num2.whole_[i];
			if (whole_[i] < 0) {
				whole_[i + 1]--;
				whole_[i] += 10;
			}
		}

		//remove front-zeros
		while (!whole_.empty() && whole_.back() == 0)
			whole_.pop_back();

		//empty vector not allowed
		if (whole_.empty())
			whole_.emplace_back(0);

	}
}