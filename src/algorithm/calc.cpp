#include "pch.h"

namespace brb
{
	const Calc Pi = Calc("3","","16","113");
	const Calc::Vector Calc::Zero {0};
	const Calc::Vector Calc::One {1};

	Calc::Calc(std::string_view number, std::string_view s, std::string_view r, std::string_view d) :
		errors_(false)
	{
		//std::cout << "constructor\n";
		setValue(number, s, r, d);
	}

	Calc::~Calc() 
	{
		//std::cout << "destructor\n";
	}
	
}