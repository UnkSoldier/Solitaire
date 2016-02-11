/*
 * jeuSolitaire.cpp
 *
 *  Created on: 2016-02-02
 *      Author: Antoine Lafleur
 */

//Programme principal du jeu de solitaire.

#include "Carte.h"
#include "Solitaire.h"
#include <iostream>
#include "ColonneCartes.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm> //permet d'utiliser random_shuffle.
#include <ctime>
#include "ColonneCartes.h"

using namespace std;

int main()
{
	//Création de la partie de Solitaire.
	Solitaire* partie = new Solitaire();

	partie->avancerTalon();
	partie->deplacerTalonAPile(1);

	/*Carte carte1((Carte::Valeur) 1, (Carte::Sorte) 1); // As de Coeur
	Carte carte2((Carte::Valeur) 2, (Carte::Sorte) 1); // Deux de coeur
	Carte carte3((Carte::Valeur) 1, (Carte::Sorte) 3); // As de Pique
	Carte carte4((Carte::Valeur) 1, (Carte::Sorte) 4); // As de Trefle
	Carte carte5((Carte::Valeur) 13, (Carte::Sorte) 4); // Roi de Trefle
	Carte carte6((Carte::Valeur) 12, (Carte::Sorte) 1); // Reine de Coeur
	Carte carte7((Carte::Valeur) 11, (Carte::Sorte) 3); // Valet de Pique



	cout << carte1.estSuivante(carte2) << endl; // Faux (0)
	cout << carte2.estSuivante(carte1) << endl; // Vrai (1)

	ColonneCartes* colonne = new ColonneCartes();

	//colonne->initColonneCartes();

	colonne->ajoute(carte5);
	colonne->ajoute(carte6);
	colonne->ajoute(carte7);
	colonne->supprimeDerniereCarte();


	cout << "LOL!" << endl;
	/*cout << carte1.estMemeCouleur(carte2) << endl; //Vrai (1)
	cout << carte1.estMemeCouleur(carte3) << endl; //Faux (0)
	cout << carte1.estMemeCouleur(carte4) << endl; //Faux (0)
	cout << endl;
	cout << carte2.estMemeCouleur(carte1) << endl; //Vrai (1)
	cout << carte2.estMemeCouleur(carte3) << endl; //Faux (0)
	cout << carte2.estMemeCouleur(carte4) << endl; //Faux (0)
	cout << endl;
	cout << carte3.estMemeCouleur(carte1) << endl; //Faux (0)
	cout << carte3.estMemeCouleur(carte2) << endl; //Faux (0)
	cout << carte3.estMemeCouleur(carte4) << endl; //Vrai (1)
	cout << endl;
	cout << carte4.estMemeCouleur(carte1) << endl; //Faux (0)
	cout << carte4.estMemeCouleur(carte2) << endl; //Faux (0)
	cout << carte4.estMemeCouleur(carte3) << endl; //Vrai (1)*/

	int a = 0;
	a += 1;
	/*partie->avancerTalon();
	partie->avancerTalon();
	partie->avancerTalon();*/




	return 0;
}
