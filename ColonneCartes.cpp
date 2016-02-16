/*
 * ColonneCartes.cpp
 *
 *  Created on: 2016-02-04
 *      Author: Antoine Lafleur
 */

#include "ColonneCartes.h"
#include "Solitaire.h"

using namespace std;

ColonneCartes::ColonneCartes() : m_nbCartesVisibles(1)
{

}

void ColonneCartes::initColonneCartes(vector<Carte>& p_listeCartes)
{
	vector<Carte>::iterator iter;

	for(iter=p_listeCartes.begin(); iter != p_listeCartes.end(); ++iter)
	{
		this->m_lesCartes.push_back(*iter);
	}
}

void ColonneCartes::ajoute(const Carte& p_carte) {
	//Si valeur p_carte est égal à la valeur de m_carte.end() -1 et que la sorte est de couleur différente:
	//Je pousse la carte.
	if(m_lesCartes.empty())
	{
		if(p_carte.reqValeur() == Carte::ROI)
		{
			m_lesCartes.push_back(p_carte);
			m_nbCartesVisibles++;
		}
		else
		{
			cout << "Impossible d'ajouter cette carte!" << endl;
		}
	}
	else if (!m_lesCartes.empty())
	{
		if(m_lesCartes.back().estSuivante(p_carte) && !m_lesCartes.back().estMemeCouleur(p_carte))
		{
			m_lesCartes.push_back(p_carte);
			//Ajoute une carte visible.
			m_nbCartesVisibles++;
		}
		else
		{
			cout << "Impossible d'ajouter cette carte!" << endl;
		}
	}
}
void ColonneCartes::deplacePaquet(ColonneCartes& p_destination, int p_nombreCartes)
{
	vector<Carte> paquetADeplacer;
	vector<Carte>::iterator iter;
	int i =0;

	while(i < p_nombreCartes)
	{
		paquetADeplacer.push_back(m_lesCartes.back());
		supprimeDerniereCarte();
		i++;
	}

	for(iter = paquetADeplacer.begin(); iter != paquetADeplacer.end(); ++iter)
	{
		cout << paquetADeplacer.size() << endl;
		if(paquetADeplacer.size() !=0)
		{
			p_destination.ajoute(paquetADeplacer.back());
			paquetADeplacer.pop_back();
		}
		else if(paquetADeplacer.size() == 0)
		{
			break;
		}
	}
}

void ColonneCartes::supprimeDerniereCarte()
{
	m_lesCartes.pop_back();
	m_nbCartesVisibles--;
	if(m_nbCartesVisibles == 0 && m_lesCartes.size() >0)
	{
		m_nbCartesVisibles++;
	}
}
int ColonneCartes::reqNbCartesVisibles() const
{
	return m_nbCartesVisibles;
}

Carte ColonneCartes::derniereCarteColonne()
{
	return m_lesCartes.back();
}

int ColonneCartes::colonneEstVide() const
{
	return m_lesCartes.size();
}

std::ostream& operator<<(std::ostream & os, const ColonneCartes& p_colonneCartes)
{
	for(int i=0; i < p_colonneCartes.m_lesCartes.size(); i++)
	{
		if(i > (p_colonneCartes.m_lesCartes.size() - p_colonneCartes.m_nbCartesVisibles))
		{
			os << "?";
		}
		else
		{
			os << p_colonneCartes.m_lesCartes.back().reqValeur() << "'" << p_colonneCartes.m_lesCartes[i].reqSorte();
		}
	}
	return os;
}