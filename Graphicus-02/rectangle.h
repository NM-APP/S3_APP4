/********
 * Fichier: rectangle.h
 * Auteurs: dumn1101 boum3864
 * Date: 16 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe rectangle.
********/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "forme.h"

class Rectangle : public Forme
{
    public:
        Rectangle(int largeur = 0, int hauteur = 0);
        ~Rectangle();
        double aire();
        void afficher();

    private:
        int largeur;
        int hauteur;
};

#endif