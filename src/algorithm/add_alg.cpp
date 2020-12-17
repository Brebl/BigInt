// ------------------------------------------------------------------------------------------------
// function:	preforms addition
// ------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::add_alg(Calc n2)
	{
		//check capacity
		if (bs(n2) == Size::Smaller) {
			this->numerator_.reserve(n2.numerator_.size() + 1);
		}
		else {
			whole_.reserve(whole_.capacity() + 1);
		}

		//addition
		for (size_t i = 0; i < n2.whole_.size(); i++) {
			if (i >= whole_.size())
				whole_.emplace_back(n2.whole_[i]);
			else
				whole_[i] += n2.whole_[i];
			if (whole_[i] < 0) {
				throw std::overflow_error("add algorithm addition");
			}
		}
		carry(whole_);
	}
}
