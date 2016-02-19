/*
 * Carte.cpp
 *
 *  Created on: 2016-02-02
 *      Author: etudiant
 */

#include "Carte.h"
#include <sstream>

using namespace std;

Carte::Carte(int p_valeur, int p_sorte) : m_valeur(p_valeur), m_sorte(p_sorte)
{
	//Vérification des préconditions.
	PRECONDITION(p_valeur >=1 && p_valeur <=13);
	PRECONDITION(p_sorte >=1 && p_sorte <=4);

	//Vérification des postconditions.
	POSTCONDITION(m_sorte == p_sorte);
	POSTCONDITION(m_valeur == p_valeur);

	//Verification des invariants.
	INVARIANTS();
}

int Carte::reqSorte() const
{
	return m_sorte;
}
int Carte::reqValeur() const
{
	return m_valeur;
}
std::string Carte::reqValeurString() const {
	std::string valeurString;
	switch (this->reqValeur())
	{
		case 1: valeurString = "A";
			break;
		case 2: valeurString = "2";
			break;
		case 3: valeurString = "3";
			break;
		case 4: valeurString = "4";
			break;
		case 5: valeurString = "5";
			break;
		case 6: valeurString = "6";
			break;
		case 7: valeurString = "7";
			break;
		case 8: valeurString = "8";
			break;
		case 9: valeurString = "9";
			break;
		case 10: valeurString = "10";
			break;
		case 11: valeurString = "V";
			break;
		case 12: valeurString = "D";
			break;
		case 13: valeurString = "R";
	}
	return valeurString;
}
std::string Carte::reqSorteString() const {
	std::string sorteString;
	switch (this->reqSorte())
	{
		case 1: sorteString = "CO";
			break;
		case 2: sorteString = "CA";
			break;
		case 3: sorteString = "PI";
			break;
		case 4: sorteString = "TR";
			break;
	}
	return sorteString;
}
bool Carte::estSuivante(const Carte& p_carte) const
{
	if(this->m_valeur == p_carte.reqValeur() + 1)
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
std::ostream& operator<<(ostream &os, const Carte& Source){
	std::string valeurTemp, sorteTemp;
	valeurTemp = Source.reqValeurString();
	sorteTemp = Source.reqSorteString();

	os << valeurTemp << "'" << sorteTemp;

	return os;
}