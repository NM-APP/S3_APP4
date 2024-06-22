/********
 * Fichier: vecteur.h
 * Auteurs: boum3864 - dumn1101 
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef VECTEUR_H
#define VECTEUR_H



#include <iostream>
#include "couche.h"

class Vecteur
{
public:
	Vecteur();
	~Vecteur();
	int getTaille();
	int getCapacite();
	void doublerCapacite();
	int addCouche(Couche *couche);
	void viderVecteur();
	bool isVecteurVide();
	Couche* getVecteur(int index);
	Couche* supprimerVecteur(int index);
	
	
private:
	int _capacite;
	Couche *vecteur;
	int _taille;
};






#endif 
