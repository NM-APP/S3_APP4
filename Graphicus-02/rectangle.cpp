/********
 * Fichier: Rectangle.cpp
 * Auteurs: Boum3864 - Dumn1101
 * Date: 13 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites
 *    
********/


#include "rectangle.h" 


Rectangle::Rectangle()
{
	ancrage.x = 0;
	ancrage.y = 0;
	_hauteur = 1;
	_largeur = 1;
	
}

Rectangle::Rectangle( int x, int y, int hauteur, int largeur)
{
	ancrage.x = x;
	ancrage.y = y;
	_hauteur = hauteur;
	_largeur = largeur;
	
}

double Rectangle::aire()
{
	return _hauteur*_largeur;
}
   
void Rectangle::afficher(ostream & s)
{
	s << "Rectangle(x = " << ancrage.x << ",y =" << ancrage.y << ", l=" << _largeur << ", h =" << _hauteur << ", aire=" << aire() << ")" << endl ; 
}   

Rectangle::~Rectangle()
{
}

void Rectangle::changerLargeur(int largeur)
{
	_largeur = largeur;
}

void Rectangle::changerHauteur(int hauteur)
{
	_hauteur = hauteur;
}

int Rectangle::getLargeur()
{	
	return _largeur;
}

int Rectangle::getHauteur()
{
	return _hauteur;
}

