#include "cercle.h"
#include "math.h"

Cercle::Cercle()
{
    this->_rayon = 1;
    this->ancrage = {0,0};
}

Cercle::Cercle(int rayon, Coordonnee ancrage)
{
    this->_rayon = rayon;
    this->ancrage = ancrage;
}

double Cercle::aire()
{
    return M_PI * pow(_rayon, 2);
}

void Cercle::afficher(ostream &s)
{
        s << "Cercle (x=" << ancrage.x  
                    << ", y=" << ancrage.y 
                    << ", l=" << _rayon
                    << ", aire=" << aire() 
                    << ")" << endl;
}

int Cercle::getRayon()
{
    return _rayon;
}

void Cercle::setRayon(int rayon)
{
    this->_rayon = rayon;
}
Cercle::~Cercle()
{
}
