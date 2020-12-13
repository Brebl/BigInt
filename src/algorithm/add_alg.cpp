// ------------------------------------------------------------------------------------------------
// function:	preforms addition
// ------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::add_alg(Calc& n2)
	{
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
		carry(num_);
	}
}
