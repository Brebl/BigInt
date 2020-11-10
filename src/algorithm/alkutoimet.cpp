#include "class.h"

bool Laskukone::alustus(Laskukone luku2)
{
	//Tarkistetaan että 1. ja 2. luvun alkiot on positiivisia
	if (!tarkastus(*this, luku2)) {
		return false;
	}

	//Lasketaan kumpi luku on isompi
	kumpi_ = isompi(*this, luku2);
	if (kumpi_ < 0) {
		return false;
	}

	//Vastauksen etumerkin laskeminen
	pos_ = positiivisuus(2, kumpi_, *this, luku2);

	return true;
}