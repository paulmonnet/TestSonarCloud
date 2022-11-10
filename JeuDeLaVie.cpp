// JeuDeLaVie.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "GrilleDeVie.h"
#include <iostream>
#include <windows.h>

int main()
{
    GrilleDeVie b;
    while (true) {
        printf("%c%s%c%s", 27, "[2J", 27, "[1;1H");
        b.afficher();
        b.evolution();
        Sleep(1000);
    }

}
