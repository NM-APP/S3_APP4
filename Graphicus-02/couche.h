/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : dumn1101 boum3864
 * Date : 17 Juin 2024
 * Description: Declaration de la classe pour une couche dans un
 *    canevas. La classe gere un tableau de formes en accord avec 
 *    les specifications de Graphicus. Ce fichier fait partie de 
 *    la distribution de Graphicus.
********/

#ifndef COUCHE_H
#define COUCHE_H

#include "forme.h"
#include <memory>

const int MAX_FORMES = 5;

// A completer

class Couche
{
  public:
    enum class Etat
    {
        Initialisee,
        Active,
        Inactive
    };

    Couche();

    bool ajouterForme(Forme* formes);
    Forme* supprimerForme(int index);
    Forme* getForme(int index);
    double aire();
    bool translater(int deltaX, int deltaY);
    bool reinitialiser();
    bool changerEtat();
    void afficher(ostream & s);

  private:
    Forme* formes[MAX_FORMES];

    // États :  1->Initialisée   2->Active   3->Inactive
    Etat _etat;
};

#endif
