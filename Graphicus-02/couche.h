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
        initialisee,
        active,
        inactive
    };

    Couche();

    bool ajouterForme(Forme* forme);
    Forme* supprimerForme(int index);
    Forme* getForme(int index);
    double aire();
    bool translater(int deltaX, int deltaY);
    bool reinitialiser();
    bool changerEtat(Etat etat);
    void afficher(ostream & s);
    std::string etatToString();

  private:
    Forme* _formes[MAX_FORMES];

    // États :  1->Initialisée   2->Active   3->Inactive
    Etat _etat;
    int _nombreFormes;
};

#endif
