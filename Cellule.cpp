#include "Cellule.h"

Cellule::Cellule()
{
	present = false;
	futur = false;
}

void Cellule::setFutur(bool destin)
{
	futur = destin;
}

bool Cellule::getFutur()
{
	return futur;
}


bool Cellule::getPresent()
{
	return present;
}

void Cellule::setPresent(bool auVentre)
{
	present = auVentre;
}
