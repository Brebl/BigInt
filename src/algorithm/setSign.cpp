//-------------------------------------------------------------------------------------------------
// function:	Sets the correct Sign for the result, based on the properties of the two numbers.
// cal:			Add, Sub, Mul, Div
// n2:			bigger, Smaller
// a:			num1
// b:			num2
// return:		Sign::Positive, Sign::Negative
//-------------------------------------------------------------------------------------------------

#include "pch.h"

namespace brb
{
	const Calc::Sign Calc::setSign(const Calculation cal, const Size n2, const Calc& a, const Calc& b)
	{
		constexpr auto pos{ Sign::Positive };
		constexpr auto neg{ Sign::Negative };

		switch (cal) {
		case Calculation::Add:	//addition
			switch (n2) {
			case Size::Bigger:	// a > b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return pos;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return neg;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return pos;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return neg;
			case Size::Smaller:	// a < b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return pos;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return neg;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return neg;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return pos;
			default:
				assert(false);
			}

		case Calculation::Sub:	//substract
			switch (n2) {
			case Size::Bigger:	//a > b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return pos;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return neg;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return pos;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return neg;
			case Size::Smaller:	//a < b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return neg;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return pos;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return pos;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return neg;
			default:
				assert(false);
			}

		case Calculation::Mul:	//multiply
			switch (n2) {
			case Size::Bigger:	//a > b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return pos;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return pos;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return neg;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return neg;
			case Size::Smaller:	//a < b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return pos;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return pos;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return neg;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return neg;
			default:
				assert(false);
			}

		case Calculation::Div:	//divide
			switch (n2) {
			case Size::Bigger:	//a > b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return pos;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return pos;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return neg;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return neg;
			case Size::Smaller:	//a < b
				if (a.sign_ == pos && b.sign_ == pos)	//++
					return pos;
				if (a.sign_ == neg && b.sign_ == neg)	//--
					return pos;
				if (a.sign_ == pos && b.sign_ == neg)	//+-
					return neg;
				if (a.sign_ == neg && b.sign_ == pos)	//-+
					return neg;
			default:
				assert(false);
			}
		default:
			assert(false);
		}
		return pos;
	}
}
