
#include "cercle.h"

Cercle::Cercle()
{
	ancrage.x = 0;
	ancrage.y = 0;
	_rayon = 1;
}

Cercle::Cercle(int x, int y, int rayon)
{
	ancrage.x = x;
	ancrage.y = y;
	_rayon = rayon;
}

Cercle::~Cercle()
{
}

double Cercle::aire()
{	
	return (M_PI*_rayon*_rayon);
}

void Cercle::changerRayon(int rayon)
{
	_rayon = rayon;
}

int Cercle::getRayon()
{
	return _rayon;
}

void Cercle::afficher(ostream & s)
{
	s << "Cercle(x = " << ancrage.x << ",y =" << ancrage.y << ", r="<< _rayon << ", aire=" << aire() << ")" << endl ; 
}


