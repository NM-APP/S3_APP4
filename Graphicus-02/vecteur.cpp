/********
 * Fichier: vecteur.cpp
 * Auteurs: Boum3864 - Dumn1101 
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "vecteur.h"

Vecteur::Vecteur()
{
	_taille = 0;
	_capacite = 1;
	vecteur = nullptr;
}
Vecteur::~Vecteur()
{
	delete[] vecteur;
}

int Vecteur::getTaille()
{
	return _taille;
}
int Vecteur::getCapacite()
{
	return _capacite;
}

void Vecteur::doublerCapacite()
{
	_capacite = _capacite*2;
}

int Vecteur::addCouche(Couche *couche)
{
	if(_taille<=_capacite)
	{
		doublerCapacite();
	}
	vecteur[_taille] = *couche;
	_taille++;
	return true;
}
void Vecteur::viderVecteur()
{
	delete[] vecteur;
	_taille = 0;
	_capacite = 1;
}
bool Vecteur::isVecteurVide()
{
	if(_taille == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
Couche* Vecteur::getVecteur(int index)
{
	if(index>_taille || 0>index)
	{
		return nullptr;
	}
	else
	{
		 return &vecteur[index];
	}
}

Couche* Vecteur::supprimerVecteur(int index)
{	
	if(index>_taille || index<0)
	{
		return nullptr;
	}
	else
	{
		Couche* supprime = &vecteur[index];
		for(int i=index; i<= _taille; i++)
		{
			vecteur[i] = vecteur[i+1];
			_taille--;
		}
		return supprime;	
	}
}


