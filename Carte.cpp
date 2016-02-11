/*
 * Carte.cpp
 *
 *  Created on: 2016-02-02
 *      Author: etudiant
 */

#include "Carte.h"

using namespace std;

Carte::Carte(int p_valeur, int p_sorte) : m_valeur(p_valeur), m_sorte(p_sorte)
{
	//Vérification des préconditions.
	PRECONDITION(p_valeur >=1 && p_valeur <=13);
	PRECONDITION(p_sorte >=1 && p_sorte <=4);

	//Vérification des postconditions.
	POSTCONDITION(m_sorte == p_sorte);
	POSTCONDITION(m_valeur == m_valeur);

	//Verification des invariants.
	INVARIANTS();
}

void Carte::asgSorte(const int& p_sorte)
{
	m_sorte = p_sorte;
}
void Carte::asgValeur(const int& p_valeur)
{
	m_valeur = p_valeur;
}

int Carte::reqSorte() const
{
	return m_sorte;
}
int Carte::reqValeur() const
{
	return m_valeur;
}
bool Carte::estSuivante(const Carte& p_carte) const
{
	if(this->m_valeur == (p_carte.m_valeur + 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Carte::estMemeCouleur(const Carte& p_carte) const
{
	if(this->m_sorte == COEUR && (p_carte.m_sorte == CARREAU || p_carte.m_sorte == COEUR))
	{
		return true;
	}
		else if(this->m_sorte == CARREAU && (p_carte.m_sorte == CARREAU || p_carte.m_sorte == COEUR))
	{
		return true;
	}
		else if(this->m_sorte == PIQUE && (p_carte.m_sorte == PIQUE || p_carte.m_sorte == TREFLE))
	{
		return true;
	}
		else if(this->m_sorte == TREFLE && (p_carte.m_sorte == PIQUE || p_carte.m_sorte == TREFLE))
	{
		return true;
	}
	else
	{
		return false;
	}
}



void Carte::verifieInvariant() const
{
	INVARIANT(m_sorte >=1 && m_sorte <=13);
	INVARIANT(m_valeur >=1 && m_sorte <=4);
}
