// ------------------------------------------------------------------------------------------------
// function:	preforms addition
// ------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	void Calc::add_alg(Vector& n1, const Vector& n2)
	{
		//check capacity
		if (compare(n1, n2) == Bs::Smaller) {
			n1.reserve(n2.size() + 1);
		}
		else {
			n1.reserve(n1.capacity() + 1);
		}

		//addition
		for (size_t i = 0; i < n2.size(); i++) {
			if (i >= n1.size())
				n1.emplace_back(n2[i]);
			else
				n1[i] += n2[i];
			if (n1[i] < 0) {
				throw std::overflow_error("add algorithm addition");
			}
		}
		carry(n1);

		n1.shrink_to_fit();
	}
}
