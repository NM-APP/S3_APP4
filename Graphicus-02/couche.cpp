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
    _nombreFormes++;
    return true;
}

Forme* Couche::supprimerForme(int index)
{
    if(index >= 0 && index < MAX_FORMES && _formes[index])
    {
        Forme* formeSuprimee =  _formes[index];

        for(int i = index; i<_nombreFormes-1; i++)
        {
            _formes[i] = _formes[i+1];
            _formes[i+1] = nullptr;
        }

        _nombreFormes--;
        return formeSuprimee;
    }
    return nullptr;
}

Forme* Couche::getForme(int index)
{
    if(_formes[index])
        return _formes[index];
    return nullptr;
}

double Couche::aire()
{
    double aireTotale = 0;

    for(int i = 0; i<_nombreFormes; i++)
    {
        aireTotale = aireTotale + _formes[i]->aire();
    }
    return aireTotale;
}

bool Couche::translater(int deltaX, int deltaY)
{
    for(int i = 0; i<_nombreFormes; i++)
    {
        _formes[i]->translater(deltaX, deltaY);
    }
    return true;
}

bool Couche::reinitialiser()
{
    for(int i = 0; i<MAX_FORMES; i++)
    {
        _formes[i] = nullptr;
    }
    changerEtat(Etat::initialisee);
    _nombreFormes = 0;
    return true;
}

bool Couche::changerEtat(Etat etat)
{
    _etat = etat;
    return true;
}

void Couche::afficher(ostream & s)
{
    s << "État: " << etatToString() << endl;

    if(_nombreFormes > 0)
    {
        for(int i = 0; i < _nombreFormes; i++)
        {
            _formes[i]->afficher(s);
        }
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
            return "inactive";
        default:
            return "inconnu";
    }
}