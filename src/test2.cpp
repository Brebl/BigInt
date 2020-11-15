#include "calc.h"

void test2()
{
	brb::Calc a{ "5" };
	brb::Calc b{ "5" };
	brb::Calc c{ "7" };
	//a = b + c;
	
	if (a != b) {
		std::cout << "different";
	}
	else {
		std::cout << "same";
	}
}