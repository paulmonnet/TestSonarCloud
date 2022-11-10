#include "GrilleDeVie.h"

GrilleDeVie::GrilleDeVie()
{

	//Initialisation
	for (int i = 0; i < GrilleDeVie::HAUTEUR; i++)
	{
		std::vector<Cellule> v;
		for (int j = 0; j < LARGEUR; j++)
		{
			v.push_back(Cellule());
		}
		grille.push_back(v);
	}

	//Randomisation
	for (int i = 0; i < NB_CELLULES_DEPART; i++)
	{
		int r1 = rand() % HAUTEUR;
		int r2 = rand() % LARGEUR;
		while (grille[r1][r2].getPresent() == true) {
			r1 = rand() % HAUTEUR;
			r2 = rand() % LARGEUR;
		}

		grille[r1][r2].setPresent(true);
		grille[r1][r2].setFutur(true);
	}
}

void GrilleDeVie::afficher()
{
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 0; j < LARGEUR; j++)
		{
			if (grille[i][j].getPresent() == false)
				std::cout << ".";
			else
				std::cout << "*";

		}
		std::cout << "\n";
	}
}

void GrilleDeVie::evolution()
{

	//calcul du futur
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 0; j < LARGEUR; j++)
		{
			int currentNb = nbVoisins(i, j);

			if (grille[i][j].getPresent()) {
				if (currentNb-1 != 2 && currentNb-1 != 3) {
					grille[i][j].setFutur(false);
				}
			}else
				if (currentNb == 3) {
					grille[i][j].setFutur(true);
				}
		}
	}

	//application futur
	for (int i = 0; i < HAUTEUR; i++)
	{
		for (int j = 0; j < LARGEUR; j++)
		{
			grille[i][j].setPresent(grille[i][j].getFutur());
		}
	}
}

/// <summary>
/// Retourne le nombre de voisins d'une cellule.
/// </summary>
/// <param name="c"></param>
/// <returns></returns>
int GrilleDeVie::nbVoisins(int ordonnee, int abscisse) {

	int result = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((ordonnee - 1 + i) >= 0 && (abscisse - 1 + j) >= 0 && (ordonnee - 1 + i) <HAUTEUR && (abscisse - 1 + j) < LARGEUR) {
				if (grille[ordonnee - 1 + i][abscisse - 1 + j].getPresent())
					result++;

			}
		}
	}
	return result;
}

