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
    Rectangle();
    Rectangle(int largeur, int hauteur, const Coordonnee& ancrage);

    double aire();
    void afficher(ostream & s);

    // Getters/Setters
    int getLargeur();
    int getHauteur();

    void setLargeur(int largeur);
    void setHauteur(int longueur);

    ~Rectangle();

private:
    int _largeur;
    int _hauteur;
};

#endif