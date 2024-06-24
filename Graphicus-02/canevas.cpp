/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet 
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    canevas.h. Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas()
{
   _coucheActive = nullptr;
}

Canevas::~Canevas()
{
   _canevas.vider();
}

bool Canevas::ajouterCouche()
{
   Couche* couche = new Couche();

   if(!_coucheActive)
   {
      couche->changerEtat(Couche::Etat::active);
      _coucheActive = couche;
   }
   else
   {
      couche->changerEtat(Couche::Etat::initialisee);
   }

   _canevas.ajouter(couche);

   return true;
}

bool Canevas::retirerCouche(int index)
{
   if(!_canevas.get(index))
      return false;

   if(_canevas.get(index) == _coucheActive)
      _coucheActive == nullptr;

   _canevas.get(index)->reinitialiser();

   if(_canevas.supprimer(index))
      return true;
   else
      return false;
}

bool Canevas::reinitialiser()
{
   _canevas.vider();
   _coucheActive = nullptr;
   return true;
}

bool Canevas::reinitialiserCouche(int index)
{
   Couche* couche = _canevas.get(index);
   if(couche)
   {
      couche->reinitialiser();
      couche->changerEtat(Couche::Etat::initialisee);

      if(couche == _coucheActive)
         _coucheActive == nullptr;

      return true;
   }
   return false;
}


bool Canevas::activerCouche(int index)
{
   Couche* couche = _canevas.get(index);
   if(couche)
   {
      _coucheActive->changerEtat(Couche::Etat::inactive);
      couche->changerEtat(Couche::Etat::active);
      _coucheActive = couche;

      return true;
   }
   return false;
}

bool Canevas::desactiverCouche(int index)
{
   Couche* couche = _canevas.get(index);
   if(couche)
   {
      couche->changerEtat(Couche::Etat::inactive);

      if(couche == _coucheActive)
         _coucheActive = nullptr;

      return true;
   }
   return false;
}


bool Canevas::ajouterForme(Forme *p_forme)
{
   if(!_coucheActive || !p_forme)
      return false;
   
   _coucheActive->ajouterForme(p_forme);
   return true;
}

bool Canevas::retirerForme(int index)
{
   if(!_coucheActive)
      return false;
   
   if(_coucheActive->supprimerForme(index))
      return true;

   return false;
}

double Canevas::aire()
{
   double aireTotale = 0;
   for(int i = 0; i<_canevas.getTaille(); i++)
   {
      aireTotale += _canevas.get(i)->aire();
   }
   return aireTotale;
}

bool Canevas::translater(int deltaX, int deltaY)
{
   if(_coucheActive)
   {
      _coucheActive->translater(deltaX, deltaY);
      return true;
   }
   return false;
}

void Canevas::afficher(ostream & s)
{

   if(_canevas.isVide())
   {
      s << "----- Aucune couche -----" << endl;
   }

   for(int i = 0; i<_canevas.getTaille(); i++)
   {
      s << "----- Couche " << i << " -----" << endl;
      _canevas.get(i)->afficher(s);
   }
}
