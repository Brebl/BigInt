//-------------------------------------------------------------------------------------------------
//function:		Digit is transferred from one column of digits to another column of more significant digits
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::carry(Vector& a)
	{
		short temp;
		for (size_t ind = 0; ind < a.size(); ind++) {
			if (a[ind] > 9) {
				temp = a[ind];
				temp /= 10;
				a[ind] %= 10;
				if (ind >= a.size() - 1)
					a.emplace_back(temp);
				else
					a[ind + 1] += temp;
				if (a[ind + 1] < 0) {
					throw std::overflow_error("carry");
				}
			}
		}
	}
}