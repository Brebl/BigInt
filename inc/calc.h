//*************************************************************************************************
//BigInt calculator
//*************************************************************************************************
/*
Todo:
-divide with fractions
-multiply with fractions
-add with fractions
-substract with fractions
-add test cases
*/
/*
done:
-more operators
-operator overload
-fractions downsizing eg 4/6 --> 2/3
-divide
-multiply
-minus
-plus
*/

#pragma once
#include <brb2/brb2.h>
#include "pch.h"

namespace brb
{
	class Calc {
		using Vector = std::vector<short>;
	private:
		enum class Calculation {
			Add,	//addition
			Sub,	//substraction
			Mul,	//multiplication
			Div		//division
		};
		enum class Sign {
			Positive,
			Negative
		};
		enum class Size {
			Bigger,
			Smaller,
			Equal
		};

		//data members
		Vector	num_;			// number
		Sign	sign_;			// +/-
		Sign	final_sign_;	// sign after calculations
		Vector	remainder_;		// fractions
		Vector	divisor_;		// fractions
		bool errors_;

		//setup
		void		init(const Calc&, const Calculation);
		const Size	bs(const Calc&);	//bigger/smaller
		const Sign	setSign(const Calculation, const Size, const Calc&, const Calc&);	//sets correct sign for result (+/-)
		void		validate(const Calc&);
		void		finish();

		//algorithms
		void add_alg(Calc&);
		void sub_alg(Calc&);
		void mul_alg(Calc&);
		void div_alg(Calc&);
		void carry(Vector&);
		void downsize(Calc&);

	public:
		Calc(std::string_view = "0", std::string_view = "", std::string_view = "0", std::string_view = "0");
		~Calc();
		void setValue(std::string_view, std::string_view = "", std::string_view = "0", std::string_view = "0");
		void getValue(int = 0, bool = false);
		operator bool() const;				// check that calculation had no errors
		bool operator !=(const Calc&) const;
		bool operator ==(const Calc&) const;
		
		Calc operator +=(Calc);				// A += B
		Calc operator +(const Calc&) const;	// A = B + C
		Calc& operator ++();				// ++A
		Calc operator ++(int);				// A++

		Calc operator -=(Calc);				// A -= B
		Calc operator -(const Calc&) const;	// A = B - C
		Calc& operator --();				// --A
		Calc operator --(int);				// A--

		Calc operator *=(Calc);				// A *= B
		Calc operator *(const Calc&) const;	// A = B * C

		Calc operator /=(Calc);				// A /= B
		Calc operator /(const Calc&) const;	// A = B / C
	};

	extern const Calc Zero;
	extern const Calc One;
	extern const Calc Pi;
}


