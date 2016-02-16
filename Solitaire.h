/*
 * Solitaire.h
 *
 *  Created on: 2016-02-02
 *      Author: Antoine Lafleur
 */

#ifndef SOLITAIRE_H_
#define SOLITAIRE_H_

#include "Carte.h"
#include "ColonneCartes.h"
#include <queue>
#include <stack>

using namespace std;

class Solitaire
{
	public:
	//Constructeur de la classe.
	Solitaire();

	//Destructeur de la classe
	virtual ~Solitaire(){};

	void avancerTalon();
	void deplacerColonneAColonne(int p_colonneSource, int p_colonneDestination, int p_nbCartes);
	void deplacerTalonAColone(int p_colonneDestination);
	void deplacerTalonAPile(int p_pileDestination);
	void deplacerColonneAPile(int p_colonneSource, int pileDestination);
	bool verifieGagne() const;

	std::string verifieCartePile(int p_pileSource) const;
	std::string reqEtatJeu() const;

	private:
	std::queue<Carte> m_talon;
	ColonneCartes m_colonnes[7];
	std::stack<Carte> m_pile[4];

	void creerJeuCartes(vector<Carte> &v) const;
	void brasserCartes(vector<Carte> &v) const;
};


#endif /* SOLITAIRE_H_ */
