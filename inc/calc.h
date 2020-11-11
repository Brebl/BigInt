//*************************************************************************************************
//BigInt calculator
//*************************************************************************************************
/*
Todo:
-operator overload
-fractions downsizing eg 4/6 --> 2/3
-divide with fractions
-multiply with fractions
-add with fractions
-substract with fractions
-add test cases
*/

#pragma once
#include <brb2.h>

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

		//variables
		Vector	num_;			// number
		Sign	sign_;			// +/-
		Sign	final_sign_;	// sign after calculations
		Vector	remainder_;		// fractions
		Vector	divisor_;		// fractions

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
		bool plus(Calc);
		bool minus(Calc);
		bool times(Calc);
		bool divide(Calc);
	};

	extern const Calc One;
	extern const Calc Zero;
	extern const Calc Pi;
}


