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
	protected:
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
		enum class Bs {
			Bigger,
			Smaller,
			Equal
		};

		//data members
		Vector	whole_;			// 
		Sign	sign_;			// +/-
		Sign	final_sign_;	// sign after calculations
		Vector	numerator_;		// osoittaja
		Vector	denominator_;	// nimittäjä
		bool errors_;			// fail-flag

		//setup
		void				init(Calc&, const Calculation);
		static const Bs		compare(const Vector&, const Vector&);
		static const Sign	setSign(const Calculation, const Bs, const Calc&, const Calc&);	//sets correct sign for result (+/-)
		void				validate();
		void				finish();

		//algorithms
		void add_alg(Vector&, const Vector&);
		void sub_alg(Vector&, Vector);
		void mul_alg(Vector&, const Vector&);
		void div_alg(const Vector&, const Vector&, Vector&, Vector&, Vector&);
		void carry(Vector&);
		void downsize(Calc&);
		void imp_frac();
		void prop_frac();
		static void lcd(Calc&, Calc&);

	public:
		Calc(std::string_view = "0", std::string_view = "", std::string_view = "0", std::string_view = "0");
		Calc(std::stringstream);
		~Calc();
		void setValue(std::string_view, std::string_view = "", std::string_view = "0", std::string_view = "0");
		const std::string getValue(int = 0, bool = false) const;
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


