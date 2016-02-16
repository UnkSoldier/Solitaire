/*
 * Carte.h
 *
 *  Created on: 2016-02-02
 *      Author: etudiant
 */

#ifndef CARTE_H_
#define CARTE_H_

#include <iostream>
#include "ContratException.h"

class Carte
{
	public:
	enum Sorte { COEUR=1, CARREAU=2, PIQUE=3, TREFLE=4 };
	enum Valeur { AS=1, DEUX=2, TROIS=3, QUATRE=4, CINQ=5, SIX=6, SEPT=7,HUIT=8, NEUF=9, DIX=10, VALET=11, DAME=12, ROI=13};

	//Constructeur de la classe carte.
	Carte(int p_valeur, int p_sorte);

	//Destructeur de la classe carte.
	~Carte(){};

	//Opérateur << - Permet d'afficher les enumérateurs plus haut lors d'un cout.
	friend std::ostream& operator<<(std::ostream& os, const Carte& Source);

	bool estSuivante(const Carte& p_carte) const;
	bool estMemeCouleur(const Carte& p_carte) const;

	//Mutateurs
	std::string reqValeurString() const;
	std::string reqSorteString() const;

	//Accesseurs
	int reqSorte() const;
	int reqValeur() const;

	private:
	int m_sorte;
	int m_valeur;
	void verifieInvariant() const;



};

#endif /* CARTE_H_ */
