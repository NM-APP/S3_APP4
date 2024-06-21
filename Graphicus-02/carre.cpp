/********
 * Fichier: carre.cpp
 * Auteurs: Boum3864 - Dumn1101
 * Date: 13 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites
 *    
********/


#include "carre.h"

Carre::Carre()
{
	ancrage.x = 0;
	ancrage.y = 0;
	_cote = 1;
} 

Carre::Carre(int x, int y, int cote)
{
	ancrage.x = x;
	ancrage.y = y;
	_cote = cote;
}

Carre::~Carre()
{
}

double Carre::aire()
{
	return _cote*_cote;
}

int Carre::getCote()
{
	return _cote;
}

void Carre::afficher(ostream & s)
{
	s << "Carre(x = " << ancrage.x << ",y =" << ancrage.y << ", c=" << _cote << ", aire=" << aire() << ")" << endl ; 
}   
