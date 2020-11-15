#include "calc.h"

void test2()
{
	brb::Calc a{ "0" };
	brb::Calc b{ "5" };
	brb::Calc c{ "7" };
	a = b + c;
	if (!a) {
		std::cout << "error";
		exit(-1);
	}
	a.getValue();
	b.getValue();
	c.getValue();
	++a;
	a.getValue();
	a += brb::Calc{ "3" };
	a /= b;
	a.getValue();
}