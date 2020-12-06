// ------------------------------------------------------------------------------------------------
// function:	checks that no negative values found
// n1:			number1
// ------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::validate(const Calc& n)
	{
		if (!n.num_.empty()) {
			for (size_t i = 0; i < n.num_.size(); i++) {
				if (n.num_[i] < 0) {
					throw std::overflow_error(
						"Validate: num_ negative value at cell " + std::to_string(i) + "\n" +
						"value: " + std::to_string(n.num_[i]));
				}
			}
		}
	}
}