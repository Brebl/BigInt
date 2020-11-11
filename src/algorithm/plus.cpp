//-------------------------------------------------------------------------------------------------
// function:	user interface function for addition
// return:		true(succeess), false(failure)
//-------------------------------------------------------------------------------------------------
/*
Updates:
-top-level exception handling
-remove VIRHE(i) macro
-switch to english
-Kymppien siirto seuraavaan soluun:
	while (vastaus[ind] > 9) {... muutettu muotoon
	if (vastaus[ind] > 9) {
	Tehostettu toimintaa koska vastaus[ind] ei pitäisi olla toista kertaa >9
-Poistettu Vektori vastaus
	koska luku_ ajaa saman asian
-Lisätty VIRHE(i) makro
-Huomio negatiivisuuden

Todo:
-Murtolukujen huomioiminen
*/

#include "calc.h"

namespace brb
{
	bool Calc::plus(Calc num2)
	{
		try
		{
			Calc answ = *this;	//in case of throw, no modifications to *this
			answ.init(num2, Calculation::Add);
			//addition if same signs
			if (answ.sign_ == num2.sign_) {
				answ.add_alg(num2);
			}
			//substract if different signs
			else {
				answ.sub_alg(num2);
			}
			answ.finish();
			*this = answ;
			return true;
		}
		catch (const std::exception& e) {
			brb::err("Addition failure: ", e.what());
			return false;
		}
	}
}