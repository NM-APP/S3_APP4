/********
 * Fichier: carre.h
 * Auteurs: Boum3864 Dumn1101
 * Date: 13 juin 2024 (creation) 
 * Modifie par : ...
 * Date : ...
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/

#ifndef CARRE_H
#define CARRE_H

#include "rectangle.h"


class Carre: public Rectangle
{
public:
	Carre();
	Carre(int x, int y, int cote);
	~Carre();
	double aire();
	void afficher( ostream & s );
	void changerCote(int cote);
	int getCote();
protected:
	int _cote;
	
};

#endif
