#include "carre.h"

Carre::Carre()
{
    this->_cote = 1;
    this->ancrage = {0,0};
}

Carre::Carre(int cote, Coordonnee ancrage)
{
    this->_cote = cote;
    this->ancrage = ancrage;
}

double Carre::aire()
{
    return _cote*_cote;
}

void Carre::afficher(ostream &s)
{
        s << "Carré (x=" << ancrage.x  
                    << ", y=" << ancrage.y 
                    << ", c=" << _cote
                    << ", aire=" << aire() 
                    << ")" << endl;
}

int Carre::getCote()
{
    return _cote;
}

void Carre::setCote(int cote)
{
    this->_cote = cote;
}

Carre::~Carre()
{
}
