/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche()
{
    std::cout << "Constructeur par défault de couche." << endl;
}

bool Couche::ajouterForme(Forme* forme)
{
    
}

Forme* Couche::supprimerForme(int index)
{
    return nullptr;
}

Forme* Couche::getForme(int index)
{
    return nullptr;
}

double Couche::aire()
{
    return 0.0;
}

bool Couche::translater(int deltaX, int deltaY)
{
    return false;
}

bool Couche::reinitialiser()
{
    return false;
}

bool Couche::changerEtat()
{
    return false;
}

void Couche::afficher(ostream & s)
{
    
}