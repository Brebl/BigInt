#include "calc.h"

void test2()
{
	brb::Calc a{ "5" };
	brb::Calc b{ "5" };

	a++;
	++b;
	
	if (a == b) {
		std::cout << "same";
	}
	else {
		std::cout << "diff";
	}
}