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
		std::stringstream output;
		if (sign_ == Sign::Negative) {
			output << "-";
		}

		//no endls
		if (a == 0) {
			size_t th = num_.size() - 1;
			output << *num_.rbegin();
			for (auto itr = num_.rbegin() + 1; itr != num_.rend(); itr++) {
				if ((th % 3 == 0) && sep) {
					output << " ";
				}
				th--;
				output << *itr;
			}
		}
		//endls
		else {
			size_t th = num_.size() - 1;
			int temp = a;
			output << *num_.rbegin();
			for (auto itr = num_.rbegin() + 1; itr != num_.rend(); itr++) {
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
		if (remainder_ != Zero.num_) {
			output << " ";
			for (auto itr = remainder_.rbegin(); itr != remainder_.rend(); itr++) {
				output << *itr;
			}
			output << "/";
			for (auto itr = divisor_.rbegin(); itr != divisor_.rend(); itr++) {
				output << *itr;
			}
		}
		return output.str();
	}
}

