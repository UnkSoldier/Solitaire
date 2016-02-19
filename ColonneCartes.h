/*
 * ColonnesCartes.h
 *
 *  Created on: 2016-02-02
 *      Author: etudiant
 */

#ifndef COLONNECARTES_H_
#define COLONNECARTES_H_

#include "Carte.h"
#include <vector>

using namespace std;

class ColonneCartes
{
	public:
	//Constructeur d'une colonne
	ColonneCartes();

	//destructeur des colonnes.
	virtual ~ColonneCartes(){};

	void initColonneCartes(std::vector<Carte> & p_listeCartes);
	void ajoute(const Carte & p_carte);
	void deplacePaquet(ColonneCartes& p_destination, int p_nombreCartes);
	void supprimeDerniereCarte();
	Carte derniereCarteColonne();
	int colonneEstVide() const;
	Carte carteALaPosition(int p_position);
	int reqTailleColonne() const;

	int reqNbCartesVisibles() const;
	friend std::ostream& operator<<(std::ostream & os,const ColonneCartes& p_colonneCartes);
	std::string sortieFormate() const;

	private:

	std::vector<Carte> m_lesCartes;
	int m_nbCartesVisibles;

};



#endif /* COLONNECARTES_H_ */
