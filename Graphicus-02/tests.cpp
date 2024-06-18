/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : ...
 * Date : ...
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"
#include "rectangle.h"
#include "carre.h"
#include "cercle.h"

void Tests::tests_unitaires_formes()
{
   // Tests sur les formes geometriques
   Rectangle rect;
   rect.afficher(std::cout);
   Rectangle rect2(3,3,{2,2});
   rect2.afficher(std::cout);

   std::cout << "\n\n";

   Carre carre;
   carre.afficher(std::cout);
   Carre carre2(3,{2,2});
   carre2.afficher(std::cout);

   std::cout << "\n\n";

   Cercle cercle;
   cercle.afficher(std::cout);
   Cercle cercle2(3,{2,2});
   cercle2.afficher(std::cout);

   std::cout << "\n\n";
}

void Tests::tests_unitaires_couche()
{
   // Tests sur la classe Couche
}

void Tests::tests_unitaires_vecteur()
{
   // Tests sur la classe Vecteur
}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
}

void Tests::tests_unitaires()
{
   // Fait tous les tests unitaires
   tests_unitaires_formes();
   tests_unitaires_couche();
   tests_unitaires_vecteur();
   tests_unitaires_canevas();
}

void Tests::tests_application()
{
   // Fait tous les tests applicatifs
   tests_application_cas_01();
   tests_application_cas_02();
}

void Tests::tests_application_cas_01()
{
   cout << "TESTS APPLICATION (CAS 01)" << endl;

   // Il faut ajouter les operations realisant ce scenario de test.
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
