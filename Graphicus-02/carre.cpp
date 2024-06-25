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
