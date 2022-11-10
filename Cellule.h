#pragma once
#include <vector>


class Cellule
{
public:
	Cellule();
	void setFutur(bool destin);
	bool getFutur();
	bool getPresent();
	void setPresent(bool auVentre);
	
private:
	bool present, futur;
};

