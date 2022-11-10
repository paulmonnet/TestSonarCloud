#pragma once
#include <vector>
#include "Cellule.h"
#include <iostream>

class GrilleDeVie
{
	const int HAUTEUR = 30, LARGEUR = 100, NB_CELLULES_DEPART= 300;

public:
	GrilleDeVie();
	void afficher();
	void evolution();
	int nbVoisins(int ordonnee, int abscisse);

private:
	std::vector<std::vector<Cellule>> grille;
};

