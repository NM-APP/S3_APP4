/********
 * Fichier: vecteur.h
 * Auteurs: dumn1101 boum3864
 * Date: 22 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Declaration de la classe vecteur.
 *              J'utilise size_t dans cette classe, car un vecteur 
 *              peut potentiellement avoir beaucoup d'éléments
********/

#include "couche.h"

#ifndef VECTEUR_H
#define VECTEUR_H

class Vecteur
{
    public:
        Vecteur();
        void vider();
        bool isVide();
        bool ajouter(Couche* couche);
        Couche* supprimer(size_t index);
        void afficher(ostream & s);

        // Getters/Setters
        int getCapacite();
        Couche* get(size_t index);

        ~Vecteur();

    private:
        static constexpr size_t _initialCapacity = 2;
        size_t _capacite;
        size_t _nombreElement;
        Couche** _vecteur;
        
        void _doublerCapacite();
};

#endif