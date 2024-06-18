/********
 * Fichier: rectangle.cpp
 * Auteurs: dumn1101 boum3864
 * Date: 16 juin 2024 (creation)
 * Description: Implementation des methodes des classes decrites dans
 *    rectangle.h.
********/

#include "rectangle.h"

Rectangle::Rectangle()
{
    std::cout << "Constructeur par défaut du rectangle" << endl;
    this->_largeur = 1;
    this->_hauteur = 1;
    this->ancrage = {0,0};
}

Rectangle::Rectangle(int largeur, int hauteur, const Coordonnee &ancrage)
{
    std::cout << "Constructeur spécifié du rectangle" << endl;
    this->_largeur = largeur;
    this->_hauteur = hauteur;
    this->ancrage = ancrage;
}

double Rectangle::aire()
{
    return _largeur * _hauteur;
}

void Rectangle::afficher(ostream & s)
{
    s << "Rectangle (x=" << ancrage.x  
                    << ", y=" << ancrage.y 
                    << ", l=" << _largeur 
                    << ", h=" << _hauteur
                    << ", aire=" << aire() 
                    << ")" << endl;
}

int Rectangle::getLargeur()
{
    return this->_largeur;
}

int Rectangle::getHauteur()
{
    return this->_hauteur;
}

Coordonnee Rectangle::getAncrage()
{
    return this->ancrage;
}

void Rectangle::setLargeur(int largeur)
{
    this->_largeur = largeur;
}

void Rectangle::setHauteur(int hauteur)
{
    this->_hauteur = hauteur;
}

void Rectangle::setAncrage(Coordonnee ancrage)
{
    this->ancrage = ancrage;
}

Rectangle::~Rectangle()
{
    std::cout << "Destructeur de Rectangle" << endl;
}