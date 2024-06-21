/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec 
 *    les specifications de Graphicus. Ce fichier fait partie de 
 *    la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

const int MAX_FORMES = 5;

#include "forme.h"

class Couche
{
   public:
   	Couche();
   	~Couche();
    	bool addForme(Forme *forme);
    	Forme* supprimeForme(int index);
    	Forme* getForme(int index);
    	double getAire();
    	bool translater(int deltax, int deltay);
    	bool reinitialiser();
    	bool changerEtat(int etat);
    	void afficher(ostream & s);
    	
   
   private:
     Forme *formes[MAX_FORMES];
     // etat: 0 = Initialisee 1=Active 3=Inactive
     int _etat;
     int _nForme;
};

#endif
