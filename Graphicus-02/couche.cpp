/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    couche.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

Couche::Couche()
{
    std::cout << "Constructeur par défault de couche." << endl;
    _etat = Etat::initialisee;
    _nombreFormes = 0;
}

bool Couche::ajouterForme(Forme* forme)
{
    if(_etat != Etat::active)
        return false;

    if(_nombreFormes >= MAX_FORMES)
        return false;

    _formes[_nombreFormes] = forme;
    ++_nombreFormes;
    return true;
}

Forme* Couche::supprimerForme(int index)
{
    // Pas Fini
    //if(index >= 0 || index < MAX_FORMES && _formes[index])
        
    return nullptr;
}

Forme* Couche::getForme(int index)
{
    return _formes[index];
}

double Couche::aire()
{
    return 0.0;
}

bool Couche::translater(int deltaX, int deltaY)
{
    return false;
}

bool Couche::reinitialiser()
{
    return false;
}

bool Couche::changerEtat(Etat etat)
{
    _etat = etat;
    return true;
}

void Couche::afficher(ostream & s)
{
    s << "État: " << etatToString() << endl;

    for(int i = 0; i < _nombreFormes; i++)
    {
        _formes[i]->afficher(s);
    }
}

std::string Couche::etatToString()
{
    switch(_etat)
    {
        case Etat::initialisee:
            return "initialisee";
        case Etat::active:
            return "active";
        case Etat::inactive:
            return "active";
        default:
            return "inconnu";
    }
}