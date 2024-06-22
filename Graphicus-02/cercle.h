/********
 * Fichier: cercle.h
 * Auteurs: dumn1101 boum3864
 * Date: 16 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe cercle.
********/

#ifndef CERCLE_H
#define CERCLE_H

#include "forme.h"

class Cercle : public Forme
{
public:
    Cercle();
    Cercle(int rayon, Coordonnee ancrage);

    double aire() override;
    void afficher(ostream & s) override;

    // Getters/Setters
    int getRayon();
    void setRayon(int rayon);

    ~Cercle();

private:
    int _rayon;
};

#endif