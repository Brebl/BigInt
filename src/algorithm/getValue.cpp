//-------------------------------------------------------------------------------------------------
// function:	print values to stringstream
// a:			how many digits before endl
// sep:			thousands separator, yep/no
//-------------------------------------------------------------------------------------------------


#include "pch.h"

namespace brb
{
	const std::string Calc::getValue(int a, bool sep) const
	{
		std::ostringstream output;
		if (sign_ == Sign::Negative) {
			output << "-";
		}

		//no endls
		if (a == 0) {
			size_t th = whole_.size() - 1;
			output << *whole_.rbegin();
			for (auto itr = whole_.rbegin() + 1; itr != whole_.rend(); itr++) {
				if ((th % 3 == 0) && sep) {
					output << " ";
				}
				th--;
				output << *itr;
			}
		}
		//endls
		else {
			size_t th = whole_.size() - 1;
			int temp = a;
			output << *whole_.rbegin();
			for (auto itr = whole_.rbegin() + 1; itr != whole_.rend(); itr++) {
				if ((th % 3 == 0) && sep) {
					output << " ";
				}
				th--;
				output << *itr;
				temp--;
				if (temp <= 0) {
					output << std::endl;
					temp = a;
				}				
			}
		}
		//std::cout << "\nNumber of digits: " << num_.size() << std::endl;

		//fractions
		if (numerator_ != Zero) {
			output << " ";
			for (auto itr = numerator_.rbegin(); itr != numerator_.rend(); itr++) {
				output << *itr;
			}
			output << "/";
			for (auto itr = denominator_.rbegin(); itr != denominator_.rend(); itr++) {
				output << *itr;
			}
		}
		return output.str();
	}
}

