//-------------------------------------------------------------------------------------------------
//function:		Set internal values num_, sign_, remainder_, divisor_
//-------------------------------------------------------------------------------------------------

#include "pch.h"

static short helper(const char*);

namespace brb
{
	void Calc::setValue(std::string_view number, std::string_view s, std::string_view remainder, std::string_view divisor)
	{
		if (s == "-") {
			sign_ = Sign::Negative;
		}
		else {
			sign_ = Sign::Positive;
		}
		num_.clear();
		divisor_.clear();
		remainder_.clear();

		for (size_t i = 0; i < number.size(); i++) {
			num_.emplace_back(helper(&number[i]));
		}

		for (size_t i = 0; i < remainder.size(); i++) {
			remainder_.emplace_back(helper(&remainder[i]));
		}

		for (size_t i = 0; i < divisor.size(); i++) {
			divisor_.emplace_back(helper(&divisor[i]));
		}
	}
}

static short helper(const char* c)
{
	switch (*c) {
	case '0':
		return (short)0;
	case '1':
		return (short)1;
	case '2':
		return (short)2;
	case '3':
		return (short)3;
	case '4':
		return (short)4;
	case '5':
		return (short)5;
	case '6':
		return (short)6;
	case '7':
		return (short)7;
	case '8':
		return (short)8;
	case '9':
		return (short)9;
	default:
		std::cerr << "non-numeric value inputted: " << *c;
		return (short)-1;
	}
}