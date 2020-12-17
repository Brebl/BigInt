//-------------------------------------------------------------------------------------------------
//function:		equal and inequal comparisons
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	bool Calc::operator ==(const Calc& num2) const
	{
		if (whole_ == num2.whole_) {
			if (sign_ == num2.sign_) {
				if (numerator_ == num2.numerator_) {
					if (denominator_ == num2.denominator_) {
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
		if (whole_ == num2.whole_) {
			if (sign_ == num2.sign_) {
				if (numerator_ == num2.numerator_) {
					if (denominator_ == num2.denominator_) {
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