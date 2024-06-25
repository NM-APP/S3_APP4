/********
 * Fichier: carre.cpp
 * Auteurs: dumn1101 boum3864
 * Date: 16 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation de la classe carre.
********/

#include "carre.h"

Carre::Carre()
{
    _largeur = 1;
    ancrage = {0,0};
}

Carre::Carre(int cote, Coordonnee ancrage)
{
    _largeur = cote;
    _hauteur = cote;
    this->ancrage = ancrage;
}

void Carre::afficher(ostream &s)
{
        s << "Carré (x=" << ancrage.x  
                    << ", y=" << ancrage.y 
                    << ", c=" << getLargeur()
                    << ", aire=" << aire() 
                    << ")" << endl;
}

int Carre::getCote()
{
    return getLargeur();
}

void Carre::setDimension(int cote)
{
    _largeur = cote;
    _hauteur = cote;
}

Carre::~Carre()
{
}
