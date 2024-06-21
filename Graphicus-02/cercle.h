/********
 * Fichier: cercle.h
 * Auteurs: Boum3864 Dumn1101
 * Date: 13 juin 2024 (creation) 
 * Modifie par : ...
 * Date : ...
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/

#ifndef CERCLE_H
#define CERCLE_H
# define M_PI           3.14159265358979323846

#include "forme.h"



class Cercle: public Forme
{
public:
	Cercle();
	Cercle(int x, int y, int rayon);
	~Cercle();
	double aire();
	void afficher( ostream & s );
	void changerRayon(int rayon);
	int getRayon();
	
protected:
	int _rayon;
	
};

#endif
