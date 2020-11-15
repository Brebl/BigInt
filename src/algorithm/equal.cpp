//-------------------------------------------------------------------------------------------------
//function:		equal and inequal comparisons
//-------------------------------------------------------------------------------------------------

#include "calc.h"

namespace brb
{
	bool Calc::operator ==(const Calc& num2) const
	{
		if (num_ == num2.num_) {
			if (sign_ == num2.sign_) {
				if (remainder_ == num2.remainder_) {
					if (divisor_ == num2.divisor_) {
						if (errors_ == num2.errors_) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	bool Calc::operator !=(const Calc& num2) const
	{
		if (num_ == num2.num_) {
			if (sign_ == num2.sign_) {
				if (remainder_ == num2.remainder_) {
					if (divisor_ == num2.divisor_) {
						if (errors_ == num2.errors_) {
							return false;
						}
					}
				}
			}
		}
		return true;
	}
}