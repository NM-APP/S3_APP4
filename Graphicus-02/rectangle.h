/********
 * Fichier: Rectangle.h
 * Auteurs: Boum3864 Dumn1101
 * Date: 13 juin 2024 (creation) 
 * Modifie par : ...
 * Date : ...
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"


class Rectangle: public Forme
{
public:
	Rectangle();
	Rectangle(int x, int y, int hauteur, int largeur);
	~Rectangle();
	double aire();
	void afficher( ostream & s );
	void changerLargeur(int longueur);
	void changerHauteur(int hauteur);
	int getLargeur();
	int getHauteur();
protected:
	int _hauteur;
	int _largeur;
	
};

#endif
