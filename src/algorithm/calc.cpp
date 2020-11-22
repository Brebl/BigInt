#include "calc.h"

namespace brb
{
	const Calc Zero = Calc("0");
	const Calc One = Calc("1");
	const Calc Pi = Calc("3","","16","113");

	Calc::Calc(std::string_view number, std::string_view s, std::string_view r, std::string_view d) :
		errors_(false)
	{
		setValue(number, s, r, d);
	}

	Calc::~Calc() 
	{
		
	}
	
}