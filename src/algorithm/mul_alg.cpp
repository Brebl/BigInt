//-------------------------------------------------------------------------------------------------
//function:		Performs multiplication
//-------------------------------------------------------------------------------------------------

/*Kerto-algoritmi
Valmis
P‰ivitykset:
-Kymppien siirrossa while muutettu muotoon if, koska ei pit‰isi tapahtua toiseen kertaan. if (luku_[ind] > 9) {
-Kymppi‰ isommat siirret‰‰n aina for(num2) j‰lkeen ettei tule ylivuotoa, testattu 9*10e6000 ^2

Todo:

*/

#include "calc.h"

namespace brb
{
	void Calc::mul_alg(Calc& num2)
	{
		//capacity
		Vector answ;
		answ.reserve(num_.size() + num2.num_.size());

		//numbers backwards because emplace_back
		std::reverse(num_.begin(), num_.end());
		std::reverse(num2.num_.begin(), num2.num_.end());		

		//multiplication
		size_t ind = 0;
		short temp = 0;
		for (size_t i = 0; i < num_.size(); i++) {
			for (size_t j = 0; j < num2.num_.size(); j++) {
				ind = j + i;
				temp = num_[i] * num2.num_[j];
				do {
					if (ind >= answ.size())
						answ.emplace_back(temp % 10);
					else
						answ[ind] += temp % 10;
					if (answ[ind] < 0) {
						throw std::overflow_error("mul_alg");
					}
					temp /= 10;
					ind++;
				} while (temp > 0);
			}
			carry(answ);	//prevent overflow with large numbers
		}
	
		std::reverse(answ.begin(), answ.end());
		this->num_ = answ;
	}
}
