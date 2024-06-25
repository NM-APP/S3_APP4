/********
 * Fichier: cercle.cpp
 * Auteurs: dumn1101 boum3864
 * Date: 16 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation de la classe cercle.
********/


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
                    << ", r=" << _rayon
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
