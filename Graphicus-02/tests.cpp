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
#include "cercle.h"
#include "carre.h"

void Tests::tests_unitaires_formes()
{
   // Tests sur les formes geometriques
}

void Tests::tests_unitaires_couche()
{
   Couche couche1;
   couche1.changerEtat(1);
   Carre carre1;
   Cercle cercle1(1,1,5);
   Rectangle rectangle1( 10, 10, 5, 10);
   Cercle cercle2(5, 5, 5);
   Carre carre2(45, 45, 20);
   Rectangle rectangle2;
   Forme *forme1 = &carre1;
   Forme *forme2 = &cercle1;
   Forme *forme3 = &rectangle1;
   Forme *forme4 = &cercle2;
   Forme *forme5 = &carre2;
   Forme *forme6 = &rectangle2;
   couche1.addForme(forme1);
   couche1.addForme(forme2);
   couche1.addForme(forme3);
   couche1.addForme(forme4);
   couche1.addForme(forme5);
   couche1.reinitialiser();  
   couche1.afficher(std::cout);
   std::cout << "aire totale =" << couche1.getAire(); 
    
   
   
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

void Tests::tests_unitaires_rectangle()
{
	Rectangle rectangle1;
	Rectangle rectangle2(10,10,10,10);
	rectangle1.afficher(std::cout);
	rectangle2.afficher(std::cout);	
}
void Tests::tests_unitaires_cercle()
{
	Cercle cercle1;
	Cercle cercle2(10,10,5);
	cercle1.afficher(std::cout);
	cercle2.afficher(std::cout);
	
}
void Tests::tests_unitaires_carre()
{
	Carre carre1;
	Carre carre2(10,10,5);
	carre1.afficher(std::cout);
	carre2.afficher(std::cout);
}












