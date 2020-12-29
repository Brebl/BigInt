//-------------------------------------------------------------------------------------------------
// function:	performs substitution
// return:		true(success) OR false(failure)
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::sub_alg(Vector& n1, Vector n2)
	{
		//switch bigger number first
		if (compare(n1, n2) == Bs::Smaller) {
			n1.swap(n2);
		}

		//substraction
		for (size_t i = 0; i< n2.size(); i++) {
			n1[i] -= n2[i];
			if (n1[i] < 0) {
				n1[i + 1]--;
				n1[i] += 10;
			}
		}

		//remove front-zeros
		while (!n1.empty() && n1.back() == 0)
			n1.pop_back();

		//empty vector not allowed
		if (n1.empty())
			n1.emplace_back(0);
	}
}