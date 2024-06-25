/********
 * Fichier: vecteur.cpp
 * Auteurs: dumn1101 boum3864
 * Date: 16 juin 2024 (creation)
 * Description: Implementation des methodes decrites dans vecteur.h.
********/

#include "vecteur.h"

Vecteur::Vecteur()
{
    _vecteur = new Couche*[_initialCapacity];
    _capacite = _initialCapacity;
    _taille = 0;
}

void Vecteur::vider()
{
    for(size_t i = 0; i<_taille; i++)
    {
        delete _vecteur[i];
    }
    _taille = 0;
    _capacite = _initialCapacity;
    Couche** nouveauTableau = new Couche*[_initialCapacity];
    delete[] _vecteur;
    _vecteur = nouveauTableau;
}

bool Vecteur::isVide()
{
    if(_taille == 0)
        return true;
    return false;
}

bool Vecteur::ajouter(Couche* couche)
{
    if(!couche)
        return false;

    if(_capacite <= _taille)
        _doublerCapacite();

    _vecteur[_taille] = couche;
    _taille++;

    return true;
}

Couche* Vecteur::supprimer(size_t index)
{
    if(index < _capacite && _vecteur[index])
    {
        Couche* elementSuprime = _vecteur[index];

        for(size_t i = index; i<_taille-1; i++)
        {
            _vecteur[i] = _vecteur[i+1];
            _vecteur[i+1] = nullptr;
        }
        _taille--;
        return elementSuprime;
    }
    return nullptr;
}

void Vecteur::afficher(ostream & s)
{
    if(isVide())
    {
        s << "Le vecteur est vide !" << std::endl;
        return;
    }

    for(size_t i = 0; i<_taille; i++)
    {
        s << "--------- Élément " << i << " ---------" << std::endl;
        _vecteur[i]->afficher(s);
    }
}

size_t Vecteur::getTaille()
{
    return _taille;
}

size_t Vecteur::getCapacite()
{
    return _capacite;
}

Couche* Vecteur::get(size_t index)
{
    if(index < _taille && _vecteur[index])
        return _vecteur[index];
    return nullptr;
}

void Vecteur::_doublerCapacite()
{
    _capacite *= 2;
    Couche** vecteurDouble = new Couche*[_capacite];

    for(size_t i = 0; i<_taille; i++)
    {
        vecteurDouble[i] = _vecteur[i];
    }

    delete[] _vecteur;
    _vecteur = vecteurDouble;
}

Vecteur::~Vecteur()
{
    vider();
    delete[] _vecteur;
}

