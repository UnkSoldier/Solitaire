/*
 * jeuSolitaire.cpp
 *
 *  Created on: 2016-02-02
 *      Author: Antoine Lafleur
 */

//Programme principal du jeu de solitaire.

#include "Carte.h"
#include "Solitaire.h"
#include <sstream>
#include <algorithm> //permet d'utiliser random_shuffle.

using namespace std;

std::string afficherMenu()
{
	ostringstream os;
	os << "***************************" << endl
	<< "          Menu" << endl
	<< "***************************" << endl
	<<
		"1. Prochaine carte du talon." << endl
	<< "2. Deplacer une carte du talon vers une colonne." << endl
	<< "3. Deplacer une carte du talon vers une pile."	 << endl
	<< "4. Deplacer une/des carte(s) d'une colonne vers une autre." << endl
	<< "5. Deplacer une carte d'une colonne vers une pile" << endl
	<< "6. Quitter" << endl
	<< "*********************************************************" << endl;

	return os.str();
}

int main()
{
	bool victoire;
	cout << "Bienvenue dans le jeu de Solitaire!" << endl;

	Solitaire* partie = new Solitaire();
	cout << "Creation d'une nouvelle partie!" << endl << endl;

	//J'affiche le jeu.
	cout << partie->reqEtatJeu() << endl;

	while(victoire == false)
	{
		int choixDuJoueur;

		cout << afficherMenu();
		cout << "Entrez votre choix: ";
		cin >> choixDuJoueur;

		//Si le choix est 1, je fais avancer le Talon.
		if(choixDuJoueur == 1)
		{
			cout << "J'avance le talon d'une carte!" << endl;
			partie->avancerTalon();
		}


			//Si le choix est deux, je demander la colonne de destination de la carte (0 et 6)
		else if(choixDuJoueur == 2)
		{
			int colonneDestination;
			cout << "Entrez la colonne de destination de la carte [0,6] : ";
			cin >> colonneDestination;
			if(colonneDestination >= 0 && colonneDestination <7)
			{
			partie->deplacerTalonAColone(colonneDestination);
			}
			else
			{
				cout << "Erreur! La colonne doit etre entre 0 et 6!" << endl;
			}
		}
		else if(choixDuJoueur == 5){
			int pileDestination, colonneSource;
			cout << "Entrez la colonne source [0,6]: ";
			cin >> colonneSource;
			cout << "Entrez la pile de destination de la carte [0,3]: ";
			cin >> pileDestination;
			if((pileDestination >= 0 && pileDestination <4) && (colonneSource >=0 && colonneSource <7))
			{
				partie->deplacerColonneAPile(colonneSource,pileDestination);
			}
			else
			{
				cout << "Erreur!" << endl;
			}
		}
		cin.ignore();
		cout << partie->reqEtatJeu();
		victoire = partie->verifieGagne();
	}
	cout << "Fin de la partie!" << endl;
	delete partie;

	return 0;
}
