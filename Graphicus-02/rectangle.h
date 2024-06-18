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

    double aire() override;
    void afficher(ostream & s) override;

    // Getters/Setters
    int getLargeur();
    int getHauteur();
    Coordonnee getAncrage();

    void setLargeur(int largeur);
    void setHauteur(int longueur);
    void setAncrage(Coordonnee ancrage);

    ~Rectangle();

private:
    int _largeur;
    int _hauteur;
};

#endif