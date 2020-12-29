// ------------------------------------------------------------------------------------------------
// function:	checks that no negative values found
// n1:			number1
// ------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::validate()
	{
		if (!this->whole_.empty()) {
			for (size_t i = 0; i < this->whole_.size(); i++) {
				if (this->whole_[i] < 0) {
					throw std::overflow_error(
						"Validate: num_ negative value at cell " + std::to_string(i) + "\n" +
						"value: " + std::to_string(this->whole_[i]));
				}
			}
		}
	}
}