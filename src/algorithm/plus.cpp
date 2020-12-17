//-------------------------------------------------------------------------------------------------
// function:	user interface function for addition
//-------------------------------------------------------------------------------------------------
/*
Updates:
-operator overload
-remove VIRHE(i) macro
-switch to english
-Kymppien siirto seuraavaan soluun:
	while (vastaus[ind] > 9) {... muutettu muotoon
	if (vastaus[ind] > 9) {
	Tehostettu toimintaa koska vastaus[ind] ei pit�isi olla toista kertaa >9
-Poistettu Vektori vastaus
	koska luku_ ajaa saman asian
-Lis�tty VIRHE(i) makro
-Huomio negatiivisuuden

Todo:
-Murtolukujen huomioiminen
*/

#include "pch.h"

namespace brb
{
	Calc Calc::operator +=(Calc num2)	//this += num2
	{
		try
		{
			Calc answ = *this;	//in case of throw, no modifications to *this
			answ.init(num2, Calculation::Add);
			this->imp_frac();
			//addition if same signs
			if (answ.sign_ == num2.sign_) {
				answ.add_alg(num2);
			}
			//substract if different signs
			else {
				answ.sub_alg(num2);
			}
			this->prop_frac();
			answ.finish();
			answ.errors_ = false;
			return *this = answ;
		}
		catch (const std::exception& e) {
			brb::err("Addition failure: ", e.what());
			errors_ = true;
			return *this;
		}
	}

	Calc Calc::operator +(const Calc& num2) const		// answ = this + num2
	{
		Calc answ = *this;
		answ += num2;
		return answ;
	}

	Calc& Calc::operator ++()	//Preincrement
	{
		*this += One;
		return *this;
	}

	Calc Calc::operator ++(int)	//postincrement
	{
		Calc temp = *this;
		++* this;
		return temp;
	}
}