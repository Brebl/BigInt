//-------------------------------------------------------------------------------------------------
//function:		Set internal values num_, sign_, remainder_, divisor_
//-------------------------------------------------------------------------------------------------

#include "pch.h"

static short helper(const char);

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

		for (auto itr = number.rbegin(); itr != number.rend(); itr++) {
			num_.emplace_back(helper(*itr));
		}

		for (auto itr = remainder.rbegin(); itr != remainder.rend(); itr++) {
			remainder_.emplace_back(helper(*itr));
		}

		for (auto itr = divisor.rbegin(); itr != divisor.rend(); itr++) {
			divisor_.emplace_back(helper(*itr));
		}
	}
}

static short helper(const char c)
{
	switch (c) {
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
		std::cerr << "non-numeric value inputted: " << c;
		return (short)-1;
	}
}