#include "carre.h"

Carre::Carre()
{
    std::cout << "Constructeur par défaut du carré" << endl;
    this->_cote = 1;
    this->ancrage = {0,0};
}

Carre::Carre(int cote, Coordonnee ancrage)
{
    std::cout << "Constructeur spécifié du carré" << endl;
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

Coordonnee Carre::getAncrage()
{
    return ancrage;
}

void Carre::setCote(int cote)
{
    this->_cote = cote;
}

void Carre::setAncrage(Coordonnee ancrage)
{
    this->ancrage = ancrage;
}

Carre::~Carre()
{
}
