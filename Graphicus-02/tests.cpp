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
#include "couche.h"

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
   Couche couche;
   Carre carre;
   Cercle cercle;
   Rectangle rectangle;
   Carre carre2;
   Cercle cercle2;

   couche.changerEtat(Couche::Etat::active);
   couche.ajouterForme(&carre);
   couche.ajouterForme(&carre2);
   couche.ajouterForme(&cercle);
   couche.ajouterForme(&cercle2);
   couche.ajouterForme(&rectangle);

   couche.afficher(std::cout);
   couche.translater(20,-10);
   couche.afficher(std::cout);
   // Test aire()
   //couche.afficher(std::cout);
   //std::cout << "Aire totale : " << couche.aire() <<  std::endl;
   //couche.supprimerForme(3);
   //std::cout << "Aire totale : " << couche.aire() <<  std::endl;
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
