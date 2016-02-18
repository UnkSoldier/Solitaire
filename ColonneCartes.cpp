/*
 * ColonneCartes.cpp
 *
 *  Created on: 2016-02-04
 *      Author: Antoine Lafleur
 */

#include "ColonneCartes.h"
#include "Solitaire.h"
#include <sstream>

using namespace std;

/**
 * \brief Constructeur par default. On assigne 1 aux carte visibles.
 *
 * \post Une instance de la classe.
 */
ColonneCartes::ColonneCartes() : m_nbCartesVisibles(1)
{

}

/** \fn void initColonneCartes(vector<Carte>& p_listeCartes)
 * \brief Initialisation de la colonne de carte. On y assigne les cartes.
 *
 * \param p_listeCartes La liste que devra contenir la colonne.
 */
void ColonneCartes::initColonneCartes(vector<Carte>& p_listeCartes)
{
	vector<Carte>::iterator iter;

	for(iter=p_listeCartes.begin(); iter != p_listeCartes.end(); ++iter)
	{
		this->m_lesCartes.push_back(*iter);
	}
}

/** \fn void ajoute(const Carte& p_carte)
 * \brief Fonction permettant d'ajouter une carte à la colonne.
 *
 * \param p_carte Carte à ajouter au bout de la colonne.
 */
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

/** \fn void deplacePaquet(colonneCartes& p_destination, int p_nombreCartes)
 * \brief Fonction permettant de déplacer une ou plusieurs cartes entre deux colonnes différentes.
 *
 * \param p_destination Colonne ou la ou les cartes doivent être ajoutées.
 * \param p_nombreCartes Le nombre de cartes que l'utilisateurs veut déplacer.
 */
void ColonneCartes::deplacePaquet(ColonneCartes& p_destination, int p_nombreCartes)
{
	vector<Carte> paquetADeplacer;
	vector<Carte>::iterator iter;
	int i =0;

	if(p_nombreCartes <= m_nbCartesVisibles) {
		while (i < p_nombreCartes) {
			paquetADeplacer.push_back(m_lesCartes.back());
			supprimeDerniereCarte();
			i++;
		}
	}
	else
	{
		cout << "Impossible de deplacer ces cartes." << endl;
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

/** \fn void supprimeDerniereCarte();
 * \brief Fonction qui supprime la carte située à la fin de la colonne. Si la carte supprimée
 * rend m_nbCartesVisibles à 0 et que la colonne n'est pas vide. On ajoute 1 pour afficher la dernière carte.
 *
 */
void ColonneCartes::supprimeDerniereCarte()
{
	m_lesCartes.pop_back();
	m_nbCartesVisibles--;
	if(m_nbCartesVisibles == 0 && m_lesCartes.size() >0)
	{
		m_nbCartesVisibles++;
	}
}

/** \fn int reqNbCartesVisibles()
 * \brief Fonction retournant la valeur membre m_nbCartesVisibles.
 *
 * \post La variable membre m_nbCartes Visible est retournée.
 */
int ColonneCartes::reqNbCartesVisibles() const
{
	return m_nbCartesVisibles;
}

/** \fn Carte derniereCarteColonne()
 * \brief Fonction retournant la dernière carte de la colonne.
 *
 * \post La dernière carte de la colonne est retournée.
 */
Carte ColonneCartes::derniereCarteColonne()
{
	return m_lesCartes.back();
}

/** \fn int colonneEstVide()
 * \brief Fonction permettant de connaître la taille de la colonne.
 *
 * \post La taille de la colonne est retournée.
 */
int ColonneCartes::colonneEstVide() const
{
	return m_lesCartes.size();
}

/** \fn std::string sortieFormate()
 * \brief Fonction qui formatte les informations de la colonne dans une string.
 *
 * \post Retourne une string avec toutes les informations requises de la colonne.
 */
std::string ColonneCartes::sortieFormate() const {
	std::string colonne;
	if(!this->m_lesCartes.empty())
	{
		for(int i = 0; i < this->m_lesCartes.size(); i++)
		{
			if(i >= this->m_lesCartes.size() - this->m_nbCartesVisibles)
			{
				colonne = colonne + " " + (m_lesCartes[i].reqValeurString() + "'" + m_lesCartes[i].reqSorteString());
			}
			else if(i < this->m_lesCartes.size() - this->m_nbCartesVisibles)
			{
				colonne = colonne + " ?";
			}
		}
	}
	else
	{
		colonne = "X";
	}
	return colonne;
}

/**
 * \brief Operateur<< surchargé permettant d'afficher toute la colonne retournée par la fonction sortieFormate().
 *
 * \post un ostream contenant toutes les informations de la colonne.
 */
std::ostream& operator<<(std::ostream & os, const ColonneCartes& p_colonneCartes)
{
	std::string sortie;
	sortie = p_colonneCartes.sortieFormate();
	os << sortie;
	return os;
}