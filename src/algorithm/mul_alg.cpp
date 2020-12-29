//-------------------------------------------------------------------------------------------------
//function:		Performs multiplication
//-------------------------------------------------------------------------------------------------

/*Kerto-algoritmi
Valmis
P�ivitykset:
-Kymppien siirrossa while muutettu muotoon if, koska ei pit�isi tapahtua toiseen kertaan. if (luku_[ind] > 9) {
-Kymppi� isommat siirret��n aina for(num2) j�lkeen ettei tule ylivuotoa, testattu 9*10e6000 ^2

Todo:

*/

#include "pch.h"

namespace brb
{
	void Calc::mul_alg(Vector& n1, const Vector& n2)
	{
		//capacity
		Vector answ;
		answ.reserve(n1.size() + n2.size());

		//multiplication
		size_t ind = 0;
		short temp = 0;
		for (size_t i = 0; i < n1.size(); i++) {
			for (size_t j = 0; j < n2.size(); j++) {
				ind = j + i;
				temp = n1[i] * n2[j];
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
		n1 = answ;
	}
}
