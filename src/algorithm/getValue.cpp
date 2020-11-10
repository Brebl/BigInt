//-------------------------------------------------------------------------------------------------
// function:	print values to stdout
// a:			how many numbers before endl
// sep:			thousands separator, yep/no
//-------------------------------------------------------------------------------------------------


#include "calc.h"

namespace brb
{
	void Calc::getValue(int a, bool sep)
	{
		if (sign_ == Sign::Negative) {
			std::cout << "-";
		}

		size_t th;
		//no endls
		if (a == 0) {
			for (size_t i = 0; i < num_.size(); i++) {
				th = num_.size() - i;
				if (!(th %= 3) && sep) {
					if (i != 0)
						std::cout << " ";
				}
				std::cout << num_[i];
			}
		}
		//endls
		else {
			int temp = a;
			for (size_t i = 0; i < num_.size(); i++) {
				th = num_.size() - i;
				if (!(th %= 3) && sep) {
					if (i != 0)
						std::cout << " ";
				}
				std::cout << num_[i];
				temp--;
				if (temp <= 0) {
					std::cout << std::endl;
					temp = a;
				}
			}
		}
		std::cout << "\nNumber of digits: " << num_.size() << std::endl;

		//remainder
		if (remainder_ != Zero.num_) {
			std::cout << "Remainder: ";
			for (auto&& i : remainder_)
				std::cout << i;
			std::cout << "\nDivisor: ";
			for (auto&& i : divisor_)
				std::cout << i;
		}
		std::cout << "\n\n";
	}
}
