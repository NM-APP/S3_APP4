/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : dumn1101 boum3864
 * Date : 25 Juin 2024
 * Description: Declaration de la classe Canevas. La classe Canevas gere un 
 *    vecteur de pointeur de couches en accord avec les specifications de Graphicus.
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "vecteur.h"
#include "forme.h"
#include "couche.h"

using namespace std;

class Canevas
{
public:
   Canevas();
   ~Canevas();
   
   bool ajouterCouche();
   bool retirerCouche(int index);

   bool reinitialiser();
   bool reinitialiserCouche(int index);
   
   bool activerCouche(int index);
   bool desactiverCouche(int index);
   
   bool ajouterForme(Forme *p_forme);
   bool retirerForme(int index);
   
   double aire();
   bool translater(int deltaX, int deltaY);
   void afficher(ostream & s);

private:
   Vecteur _canevas;
   Couche* _coucheActive;
};

#endif
