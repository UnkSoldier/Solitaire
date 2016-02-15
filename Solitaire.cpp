/*
 * Solitaire.cpp
 *
 *  Created on: 2016-02-02
 *      Author: Antoine Lafleur
 */

#include "Solitaire.h"
#include <algorithm> // permet d'utiliser random_shuffle.
#include <ctime> //Permet d'utiliser time.
#include <sstream>

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
	brasserCartes(v);

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
void Solitaire::deplacerColonneAPile(int p_colonneSource, int pileDestination) {
	PRECONDITION(pileDestination >= 0 && pileDestination <= 3);
	PRECONDITION(p_colonneSource >= 0 && p_colonneSource <= 6);

	if (m_pile[pileDestination].empty())
	{
		if(m_colonnes[p_colonneSource].derniereCarteColonne().reqValeur() == Carte::AS)
		{
			m_pile[pileDestination].push(m_colonnes[p_colonneSource].derniereCarteColonne());
			m_colonnes[p_colonneSource].supprimeDerniereCarte();
		}
		else
		{
			cout << "eplacement Invalide!" << endl;
		}
	}
	else if(m_colonnes[p_colonneSource].derniereCarteColonne().reqSorte() == m_pile[pileDestination].top().reqSorte())
	{
		if(m_colonnes[p_colonneSource].derniereCarteColonne().reqValeur() == (m_pile[pileDestination].top().reqValeur() +1))
		{
			m_pile[pileDestination].push(m_colonnes->derniereCarteColonne());
			m_colonnes[p_colonneSource].supprimeDerniereCarte();
		}
	}
	else
	{
		cout << "Impossible d'ajouter la carte!" << endl;
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
bool Solitaire::verifieGagne() const
{
	bool talonEstVide, colonneSontVides;
	talonEstVide = m_talon.size() == 0;

	for(int i=0; i<7; i++)
		if(m_colonnes[i].colonneEstVide() == 0)
		{
			colonneSontVides = true;
		}
	else
		{
			colonneSontVides = false;
		}

	if(talonEstVide && colonneSontVides)
	{
		return true;
	}
	return false;
}
std::string Solitaire::reqEtatJeu() const
{
	std::ostringstream jeuFormate;
	jeuFormate << "Talon :" << m_talon.front() << "          " << "Piles   "  << m_pile[0] << "   " << m_pile[1]
			<< m_pile[2] << "   " << m_pile[3] << endl
	<< endl <<
	   "Col.0: " << this->m_colonnes[0] << endl
	<< "Col.1: " << this->m_colonnes[1] << endl
   	<< "Col.2: " << this->m_colonnes[2] << endl
	<< "Col.3: " << this->m_colonnes[3] << endl
	<< "Col.4: " << this->m_colonnes[4] << endl
	<< "Col.5: " << this->m_colonnes[5] << endl
    << "Col.6: " << this->m_colonnes[6] << endl
    << "Col.7: " << this->m_colonnes[7] << endl;

	return jeuFormate;
}