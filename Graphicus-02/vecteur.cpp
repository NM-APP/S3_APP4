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
    _nombreElement = 0;
}

void Vecteur::vider()
{
    for(size_t i = 0; i<_nombreElement; i++)
    {
        _vecteur[i]->~Couche();
        _vecteur[i] = nullptr;
    }
    _nombreElement = 0;
    _capacite = _initialCapacity;
    Couche** nouveauTableau = new Couche*[_initialCapacity];
    delete[] _vecteur;
    _vecteur = nouveauTableau;
}

bool Vecteur::isVide()
{
    if(_nombreElement == 0)
        return true;
    return false;
}

bool Vecteur::ajouter(Couche* couche)
{
    if(_capacite <= _nombreElement)
    {
        _doublerCapacite();
    }

    _vecteur[_nombreElement] = couche;
    _nombreElement++;

    return true;
}

Couche* Vecteur::supprimer(size_t index)
{
    if(index < _capacite && _vecteur[index])
    {
        Couche* elementSuprime = _vecteur[index];

        for(size_t i = index; i<_nombreElement-1; i++)
        {
            _vecteur[i] = _vecteur[i+1];
            _vecteur[i+1] = nullptr;
        }
        _nombreElement--;
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

    for(size_t i = 0; i<_nombreElement; i++)
    {
        s << "--------- Élément " << i << " ---------" << std::endl;
        _vecteur[i]->afficher(s);
    }
}

int Vecteur::getCapacite()
{
    return _capacite;
}

Couche* Vecteur::get(size_t index)
{
    if(index < _nombreElement && _vecteur[index])
        return _vecteur[index];
    return nullptr;
}

void Vecteur::_doublerCapacite()
{
    _capacite *= 2;
    Couche** vecteurDouble = new Couche*[_capacite];

    for(size_t i = 0; i<_nombreElement; i++)
    {
        vecteurDouble[i] = _vecteur[i];
    }

    delete[] _vecteur;
    _vecteur = vecteurDouble;

    cout << "Vecteur doublée, la capacité à passé de " << _capacite/2 << " à " << _capacite << std::endl;
}

Vecteur::~Vecteur()
{
    vider();
    delete[] _vecteur;
}

