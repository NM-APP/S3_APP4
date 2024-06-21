/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche()
{	
	_etat = 0;
	_nForme = 0;
}

Couche::~Couche()
{
}
bool Couche::changerEtat(int etat)
{	
	if (etat > 2 || etat<0)
	{
		return false;
	}
	else{
		_etat = etat;
		return true;
	}
}
bool Couche::addForme(Forme *forme)
{
	if ( _etat != 1 || _nForme > MAX_FORMES)
	{
		return false;
	}
	else
	{
		formes[_nForme] = forme;
		_nForme++;
		return true;
	}
}

Forme* Couche::getForme(int index)
{
	if( index<= _nForme || index >= 0)
	{	
		return formes[index];
	}
	else
	{
		return 0;
	} 
}

void Couche::afficher(ostream & s)
{
	if( _etat == 0)
	{
		s << "Etat: initialisee" << endl;
	}
	else if (_etat == 1)
	{
		s << "Etat: active" << endl;
	}
	else if (_etat == 2)
	{
		s << "Etat: inactive" << endl;
	}
	
	for( int i = 0; i < _nForme; i++)
	{
		formes[i]->afficher(s);
	}
}

double Couche::getAire()
{
	double somme;
	for( int i = 0; i<_nForme; i++)
	{
		somme = somme + formes[i]->aire();
	}
	return somme;
}

bool Couche::translater( int deltax, int deltay)
{
	if( _etat == 1)
	{
		for( int i = 0; i<_nForme; i++)
		{
			formes[i]->translater(deltax, deltay);
		}
		return true;
	}
	else
	{
		return false;
	}
}
Forme* Couche::supprimeForme(int index)
{
	if( _etat == 1 && index >= 0 && index < _nForme)
	{
		for( int i = index ; i < _nForme; i++)
		{
			formes[i] = formes[i+1];
			_nForme--;
		}
		return formes[index];
	}
	else
	{
		return 0 ;
	}
}

bool Couche::reinitialiser()
{
	_etat = 1;
	for(int i = 0; i <= _nForme+1; i++)
	{
		supprimeForme(0);
	}
	
	_etat = 0;
	return true;
}


























