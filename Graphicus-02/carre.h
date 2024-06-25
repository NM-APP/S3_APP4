/********
 * Fichier: carre.h
 * Auteurs: dumn1101 boum3864
 * Date: 16 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe carre.
********/

#ifndef CARRE_H
#define CARRE_H

#include "rectangle.h"

class Carre : public Rectangle
{
public:
    Carre();
    Carre(int cote, Coordonnee ancrage);

    void afficher(ostream & s);
    
    // Getters/Setters
    int getCote();
    void setCote(int cote);

    ~Carre();
};

#endif