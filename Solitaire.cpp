/*
 * Solitaire.cpp
 *
 *  Created on: 2016-02-02
 *      Author: Antoine Lafleur
 */

#include "Solitaire.h"
#include <algorithm> // permet d'utiliser random_shuffle.
#include <ctime> //Permet d'utiliser time.


using namespace std;

/**
 * \brief Fonction permettant de brasser le paquet de carte.
 *  Trouvée sur le site cplusplus.com.
 */

int myrandom (int i) { return std::rand()%i;}

Solitaire::Solitaire()
{
	vector<Carte> v;
	creerJeuCartes(v);
	//brasserCartes(v);

	/*for(int i = 0; i<=6; i++) {
		vector<Carte> listeDeCartes;
		for(int j=0; j < i+1 ; j++) {
			listeDeCartes.push_back(v.back());
			v.pop_back();
		}
		this->m_colonnes[i].initColonneCartes(listeDeCartes);
	}*/

	for ( int i = 0; i < v.size() ;++i){
		this->m_talon.push(v[i]);
	}
}

void Solitaire::brasserCartes(vector<Carte> &v) const {//Melange le jeu de carte dans le vector.
	srand((unsigned int)time(0));
	random_shuffle(v.begin(), v.end(), myrandom);
}

void Solitaire::creerJeuCartes(vector<Carte> &v) const {
	Carte carte1((Carte::Valeur) 13, (Carte::Sorte) 1); // Roi de Coeur
	v.push_back(carte1);
	Carte carte2((Carte::Valeur) 12, (Carte::Sorte) 3); // Dame de Pique
	v.push_back(carte2);
	Carte carte3((Carte::Valeur) 11, (Carte::Sorte) 2); // Valet de Carreau
	v.push_back(carte3);

	/*
	Carte carte4((Carte::Valeur) 1, (Carte::Sorte) 4); // As de Trefle
	v.push_back(carte4);
	Carte carte5((Carte::Valeur) 13, (Carte::Sorte) 4); // Roi de Trefle
	v.push_back(carte5);
	Carte carte6((Carte::Valeur) 12, (Carte::Sorte) 1); // Reine de Coeur
	v.push_back(carte6);
	Carte carte7((Carte::Valeur) 11, (Carte::Sorte) 3); // Valet de Pique
	v.push_back(carte7);*/


	/*for(int i=1; i <= 4; i++)
	{
		for(int j = 1; j<=13;j++)
		{
			Carte carte((Carte::Valeur) j, (Carte::Sorte) i);
			v.push_back(carte);
		}
	}*/
}

void Solitaire::avancerTalon()
{
	m_talon.push(m_talon.front());
	m_talon.pop();
}

void Solitaire::deplacerColonneAColonne(int p_colonneSource, int p_colonneDestination, int p_nbCartes)
{
	PRECONDITION(p_colonneSource >=0 && p_colonneSource <=6);
	PRECONDITION(p_colonneDestination >=0 && p_colonneDestination <=6);

	m_colonnes[p_colonneSource].deplacePaquet(m_colonnes[p_colonneDestination], p_nbCartes);
}

void Solitaire::deplacerTalonAPile(int p_pileDestination)
{
	PRECONDITION(p_pileDestination >=0 && p_pileDestination <=3);

	//Verification si la pile est vide. Si tel est le cas, seul les As peuvent débuter la pile.
	if(m_pile[p_pileDestination].empty())
	{
		if(m_talon.front().reqValeur() == Carte::AS)
		{
			m_pile[p_pileDestination].push(m_talon.front());
			m_talon.pop();
		}
		else
		{
			cout << "Coup Invalide!" << endl;
		}
	}
	else if(this->m_talon.front().estSuivante(m_pile[p_pileDestination].top()) &&
			this->m_talon.front().reqSorte() == m_pile[p_pileDestination].top().reqSorte())
	{
		m_pile[p_pileDestination].push(m_talon.front());
		m_talon.pop();
	}
	else
	{
		cout << "Impossible d'ajouter cette carte a la pile!" << endl;
	}
}
void Solitaire::deplacerColonneAPile(int p_colonneSource, int pileDestination)
{
	PRECONDITION(pileDestination >=0 && pileDestination <=3);
	PRECONDITION(p_colonneSource >=0 && p_colonneSource <=6);

	if(m_pile[pileDestination].empty())
	{
		if(m_pile[pileDestination].empty())
		{
			//Si la pile est vide, seul les as ont le droit de débuter la pile.
			if(m_pile[pileDestination].empty())
			{
				if(m_colonnes[p_colonneSource].derniereCarteColonne().reqValeur() == Carte::AS)
				{
					m_pile[pileDestination].push(m_colonnes[p_colonneSource].derniereCarteColonne());
					m_colonnes[p_colonneSource].supprimeDerniereCarte();
				}
			}
			else if(this->m_colonnes[p_colonneSource].derniereCarteColonne().estSuivante(m_colonnes->derniereCarteColonne()) &&
					this->m_colonnes[p_colonneSource].derniereCarteColonne().reqSorte() == m_pile[pileDestination].top().reqSorte())
			{
				m_pile[pileDestination].push(m_colonnes->derniereCarteColonne());
				m_colonnes[p_colonneSource].supprimeDerniereCarte();
			}
			else
			{
				cout << "Impossible d'ajouter cette carte a la pile!" << endl;
			}
		}

	}

}

void Solitaire::deplacerTalonAColone(int p_colonneDestination) {
	PRECONDITION(p_colonneDestination >= 0 && p_colonneDestination <= 6);

	int temp;
	temp = this->m_colonnes[p_colonneDestination].reqNbCartesVisibles();
	m_colonnes[p_colonneDestination].ajoute(m_talon.front());

	//Je vérifie si reqNbCartesVisibles de la colonne a été modifiée
	if (temp == this->m_colonnes[p_colonneDestination].reqNbCartesVisibles()) {
		cout << "Erreur" << endl;
	}
	else if (temp != (this->m_colonnes[p_colonneDestination].reqNbCartesVisibles())) {
		cout << "Retrait de la carte!" << endl;
		m_talon.pop();
	}
}