//-------------------------------------------------------------------------------------------------
// function:	print values to stdout
// a:			how many digits before endl
// sep:			thousands separator, yep/no
//-------------------------------------------------------------------------------------------------


#include "pch.h"

namespace brb
{
	void Calc::getValue(int a, bool sep)
	{
		if (sign_ == Sign::Negative) {
			std::cout << "-";
		}

		//no endls
		if (a == 0) {
			size_t th = num_.size() - 1;
			std::cout << *num_.rbegin();
			for (auto itr = num_.rbegin() + 1; itr != num_.rend(); itr++) {
				if ((th % 3 == 0) && sep) {
					std::cout << " ";
				}
				th--;
				std::cout << *itr;
			}
		}
		//endls
		else {
			size_t th = num_.size() - 1;
			int temp = a;
			std::cout << *num_.rbegin();
			for (auto itr = num_.rbegin() + 1; itr != num_.rend(); itr++) {
				if ((th % 3 == 0) && sep) {
					std::cout << " ";
				}
				th--;
				std::cout << *itr;
				temp--;
				if (temp <= 0) {
					std::cout << std::endl;
					temp = a;
				}				
			}
		}
		//std::cout << "\nNumber of digits: " << num_.size() << std::endl;

		//fractions
		if (remainder_ != Zero.num_) {
			std::cout << " ";
			for (auto itr = remainder_.rbegin(); itr != remainder_.rend(); itr++) {
				std::cout << *itr;
			}
			std::cout << "/";
			for (auto itr = divisor_.rbegin(); itr != divisor_.rend(); itr++) {
				std::cout << *itr;
			}
		}
	}
}
