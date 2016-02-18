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
		//Si le choix est 3, je demande sur quelle pile la carte du talon doit être déplacée.
		else if(choixDuJoueur == 3){
			int pileDestination;
			cout << "Entrez la pile de destination de la carte[0,3]: ";
			cin >> pileDestination;
			if(pileDestination >=0 && pileDestination <4){
				partie->deplacerTalonAPile(pileDestination);
			}
			else
			{
				cout << "Erreur! la pile choisie doit etre entre 0 et 3." << endl;
			}
		}
		//Si le choix est 4, la colonne source, la colonne de destination et le nombre de carte est demandé.
		else if(choixDuJoueur == 4) {
			int colonneSource, colonneDestination, nbCarte;
			cout << "Entrez le numero de la colonne source [0,6]: ";
			cin >> colonneSource;
			cout << endl << "Entrez le numero de la colonne de destination [0,6]: ";
			cin >> colonneDestination;
			cout << endl << "Entrez le nombre de carte a deplacer: ";
			cin >> nbCarte;

			partie->deplacerColonneAColonne(colonneSource, colonneDestination, nbCarte);
		}
		//Si le choix est 5, la colonne source est demandée ainsi que la pile de destination.
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
		//Si le choix est 6, on brise la boucle While pour quitter le programme.
		else if(choixDuJoueur == 6)
		{
			break;
		}
		cin.ignore();
		cout << partie->reqEtatJeu();
		victoire = partie->verifieGagne();
	}
	cout << "Fin de la partie!" << endl;
	std::string fin;
	cout << "Appuyez une une touche pour continuer..." << endl;
	cin >> fin;
	delete partie;

	return 0;
}
