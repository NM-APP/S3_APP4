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

#include "forme.h"

class Carre : public Forme
{
public:
    Carre();
    Carre(int cote, Coordonnee ancrage);

    double aire() override;
    void afficher(ostream & s) override;
    
    // Getters/Setters
    int getCote();
    Coordonnee getAncrage();

    void setCote(int cote);
    void setAncrage(Coordonnee ancrage);

    ~Carre();

private:
    int _cote;
};

#endif