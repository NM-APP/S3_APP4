/********
 * Fichier: graphicus-01.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : dumn1101 dumn1101
 * Date : 25 Juin 2024
 * Description: gestionnaire de tests pour l'application Graphicus. Ce
 *    fichier fait partie de la distribution de Graphicus.
********/
#include "tests.h"

using namespace std;

int main()
{
   Tests tests;
   //tests.tests_unitaires_formes();
   //tests.tests_unitaires_couche();
   //tests.tests_unitaires_vecteur();
   //tests.tests_unitaires_canevas();

   tests.tests_application();
   return 0;
}

