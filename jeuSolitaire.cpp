/*
 * jeuSolitaire.cpp
 *
 *  Created on: 2016-02-02
 *      Author: Antoine Lafleur
 */

//Programme principal du jeu de solitaire.

#include "Carte.h"
#include "Solitaire.h"
#include <algorithm> //permet d'utiliser random_shuffle.


using namespace std;

int main()
{
	//Création de la partie de Solitaire.
	Solitaire* partie = new Solitaire();

	cout << partie << endl;

	return 0;
}
