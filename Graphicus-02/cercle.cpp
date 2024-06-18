#include "cercle.h"
#include "math.h"

Cercle::Cercle()
{
    std::cout << "Constructeur par défaut du cercle" << endl;
    this->_rayon = 1;
    this->ancrage = {0,0};
}

Cercle::Cercle(int rayon, Coordonnee ancrage)
{
    std::cout << "Constructeur spécifié du cercle" << endl;
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

Coordonnee Cercle::getAncrage()
{
    return ancrage;
}

void Cercle::setRayon(int rayon)
{
    this->_rayon = rayon;
}

void Cercle::setAncrage(Coordonnee ancrage)
{
    this->ancrage = ancrage;
}
