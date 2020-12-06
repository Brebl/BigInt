// ------------------------------------------------------------------------------------------------
// function:	preforms addition
// ------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::add_alg(Calc& n2)
	{
		//numbers backwards because emplace_back
		std::reverse(num_.begin(), num_.end());
		std::reverse(n2.num_.begin(), n2.num_.end());

		//check capacity
		if (bs(n2) == Size::Smaller) {
			num_.reserve(n2.num_.size() + 1);
		}
		else {
			num_.reserve(num_.capacity() + 1);
		}

		//addition
		for (size_t i = 0; i < n2.num_.size(); i++) {
			if (i >= num_.size())
				num_.emplace_back(n2.num_[i]);
			else
				num_[i] += n2.num_[i];
			if (num_[i] < 0) {
				throw std::overflow_error("add algorithm addition");
			}
		}

		//move 10s to next element
		short temp = 0;
		for (size_t i = 0; i < num_.size(); i++) {
			if (num_[i] < 0) {
				throw std::overflow_error("add algorithm move 10s");
			}
			if (num_[i] > 9) {
				temp = num_[i];
				temp /= 10;
				num_[i] %= 10;
				if (i >= num_.size() - 1)
					num_.emplace_back(temp);
				else
					num_[i + 1] += temp;
			}
		}

		std::reverse(num_.begin(), num_.end());
	}
}
