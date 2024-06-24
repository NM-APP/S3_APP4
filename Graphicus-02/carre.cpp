#include "carre.h"

Carre::Carre()
{
    setLargeur(1);
    ancrage = {0,0};
}

Carre::Carre(int cote, Coordonnee ancrage)
{
    setLargeur(cote);
    setHauteur(cote);
    ancrage = ancrage;
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

void Carre::setCote(int cote)
{
    setLargeur(cote);
    setHauteur(cote);
}

Carre::~Carre()
{
}
