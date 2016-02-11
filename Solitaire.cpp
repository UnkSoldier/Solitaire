/*
 * Solitaire.cpp
 *
 *  Created on: 2016-02-02
 *      Author: Antoine Lafleur
 */

#include "Solitaire.h"
#include "ColonneCartes.h"
#include "Carte.h"
#include <vector>
#include <stack>
#include <iostream>
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

	for(int i = 0; i<=6; i++) {
		vector<Carte> listeDeCartes;
		for(int j=0; j < i+1 ; j++) {
			listeDeCartes.push_back(v.back());
			v.pop_back();
		}
		this->m_colonnes[i].initColonneCartes(listeDeCartes);
	}

	for ( int i = 0; i < v.size() ;++i){
		this->m_talon.push(v[i]);
	}
}

void Solitaire::brasserCartes(vector<Carte> &v) const {//Melange le jeu de carte dans le vector.
	srand((unsigned int)time(0));
	random_shuffle(v.begin(), v.end(), myrandom);
}

void Solitaire::creerJeuCartes(vector<Carte> &v) const {
	for(int i=1; i <= 4; i++)
	{
		for(int j = 1; j<=13;j++)
		{
			Carte carte((Carte::Valeur) j, (Carte::Sorte) i);
			v.push_back(carte);
		}
	}
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

	//
	m_colonnes[p_colonneSource].deplacePaquet(m_colonnes[p_colonneDestination], p_nbCartes);
}

void Solitaire::deplacerTalonAPile(int p_pileDestination)
{
	PRECONDITION(p_pileDestination >=0 && p_pileDestination <=3);

	//Verification si la pile est vide. Si elle est vide, seul les As peuvent débuter la pile.
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
		m_pile->pop();
	}
	else
	{
		cout << "Impossible d'ajouter cette carte à la pile!" << endl;
	}
}