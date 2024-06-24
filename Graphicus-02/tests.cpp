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
#include "vecteur.h"
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
   Vecteur vecteur;

   Couche couche;
   Couche couche2;

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

   vecteur.ajouter(&couche);
   vecteur.ajouter(&couche2);
   vecteur.ajouter(&couche2);
   vecteur.ajouter(&couche2);

   vecteur.afficher(std::cout);

   vecteur.supprimer(0);

   vecteur.afficher(std::cout);

   vecteur.vider();

   vecteur.afficher(std::cout);

}

void Tests::tests_unitaires_canevas()
{
   // Tests sur la classe Canevas
   Canevas canevas;

   canevas.ajouterCouche();
   canevas.ajouterForme(new Carre());
   canevas.ajouterForme(new Rectangle());
   canevas.ajouterCouche();
   canevas.ajouterForme(new Cercle());
   canevas.ajouterCouche();
   canevas.activerCouche(2);
   canevas.ajouterForme(new Rectangle(2,3,{12,10}));
   canevas.ajouterForme(new Carre(69,{12,10}));

   canevas.retirerForme(0);
   canevas.translater(100, 1000);
   std::cout << "Aire totale : " << canevas.aire() << std::endl;

   canevas.afficher(std::cout);
   std::cout << "\n\n\n";

   canevas.reinitialiser();

   canevas.afficher(std::cout);
   std::cout << "\n\n\n";
   

   //canevas.retirerCouche(0);
   //canevas.reinitialiserCouche(1);

   //canevas.afficher(std::cout);

   // Test pour nullptr
   int* ptr = nullptr;
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
   // Définitions des séquences d'échappement pour les couleurs
   const std::string RESET = "\033[0m";
   const std::string ROUGE = "\033[31m";
   const std::string VERT = "\033[32m";
   const std::string CYAN = "\033[36m";

   std::cout << "TESTS APPLICATION (CAS 01)\n\n";

   Canevas canevas;

   // Étape 1 à 2
   std::cout << "\n" << CYAN << "====================== Étape 1 et 2 ======================" << RESET << "\n";
   std::cout << VERT << "Étape 1: Affichage du canevas" << RESET << "\n";
   canevas.afficher(std::cout);
   std::cout << VERT << "\nÉtape 2: Affichage de l'aire totale du canevas" << RESET;
   std::cout << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 3 à 5
   std::cout << "\n" << CYAN << "====================== Étapes 3 à 5 ======================" << RESET << "\n";
   std::cout << VERT << "Étape 3: Ajout de 5 couches au canevas" << RESET << "\n";
   for(int i = 0; i<5; i++)
   {
      if(canevas.ajouterCouche())
         std::cout << "Réussite : Ajout d'une couche vide" << endl;
      else
         std::cout << ROUGE << "Échec : Impossible d'ajouter une couche" << RESET << endl;
   }
   std::cout << VERT << "Étape 4: Affichage du canevas" << RESET << "\n";
   canevas.afficher(std::cout);
   std::cout << VERT << "\nÉtape 5: Affichage de l'aire totale du canevas" << RESET;
   std::cout << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 6 à 9
   std::cout << "\n" << CYAN << "====================== Étapes 6 à 9 ======================" << RESET << "\n";
   std::cout << VERT << "Étape 6: Activation de la couche 2 et ajout de formes" << RESET << "\n";

   Cercle* cercle1 = new Cercle(5, {0, 1});
   Carre* carre1 = new Carre(6, {1, 2});
   Rectangle* rectangle1 = new Rectangle(4, 9, {2, 3});

   if(canevas.activerCouche(2))
      std::cout << "Réussite : Activation de la couche 2" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 2" << RESET << endl;

   if(canevas.ajouterForme(cercle1))
      std::cout << "Réussite : Ajout d'un cercle (x=0, y=1, rayon=5)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un cercle" << RESET << endl;

   if(canevas.ajouterForme(carre1))
      std::cout << "Réussite : Ajout d'un carré (x=1, y=2, côté=6)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un carré" << RESET << endl;

   if(canevas.ajouterForme(rectangle1))
      std::cout << "Réussite : Ajout d'un rectangle (x=2, y=3, largeur=4, hauteur=9)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un rectangle" << RESET << endl;

   std::cout << VERT << "Étape 7: Activation de la couche 1 et ajout de forme" << RESET << "\n";
   if(canevas.activerCouche(1))
      std::cout << "Réussite : Activation de la couche 1" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 1" << RESET << endl;

   Rectangle* rectangle2 = new Rectangle(12, 3, {0, 0});

   if(canevas.ajouterForme(rectangle2))
      std::cout << "Réussite : Ajout d'un rectangle (x=0, y=0, largeur=12, hauteur=3)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un rectangle" << RESET << endl;

   std::cout << VERT << "Étape 8: Affichage du canevas" << RESET << "\n";
   canevas.afficher(std::cout);
   std::cout << VERT << "\nÉtape 9: Affichage de l'aire totale du canevas" << RESET;
   std::cout << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 10 à 13
   std::cout << "\n" << CYAN << "====================== Étapes 10 à 13 ======================" << RESET << "\n";
   std::cout << VERT << "Étape 10: Activation de la couche 0 et ajout de formes" << RESET << "\n";

   Cercle* cercle3 = new Cercle(1, {0, 0});
   Carre* carre3 = new Carre(1, {0, 0});
   Rectangle* rectangle3 = new Rectangle(1, 1, {0, 0});

   if(canevas.activerCouche(0))
      std::cout << "Réussite : Activation de la couche 0" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 0" << RESET << endl;
   if(canevas.ajouterForme(rectangle3))
      std::cout << "Réussite : Ajout d'un rectangle (x=0, y=0, largeur=1, hauteur=1)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un rectangle" << RESET << endl;

   if(canevas.ajouterForme(carre3))
      std::cout << "Réussite : Ajout d'un carré (x=0, y=0, côté=1)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un carré" << RESET << endl;

   if(canevas.ajouterForme(cercle3))
      std::cout << "Réussite : Ajout d'un cercle (x=0, y=0, rayon=1)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un cercle" << RESET << endl;

   std::cout << VERT << "Étape 11: Activation de la couche 2 et application d'une translation de (x=2, y=1)" << RESET << "\n";
   if(canevas.activerCouche(2))
      std::cout << "Réussite : Activation de la couche 2" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 2" << RESET << endl;

   if(canevas.translater(2, 1))
      std::cout << "Réussite : Translation de la couche 2" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible de translater la couche 2" << RESET << endl;

   std::cout << VERT << "Étape 12: Affichage du canevas" << RESET << "\n";
   canevas.afficher(std::cout);
   std::cout << VERT << "\nÉtape 13: Affichage de l'aire totale du canevas" << RESET;
   std::cout << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 14 à 20
   std::cout << "\n" << CYAN << "====================== Étapes 14 à 20 ======================" << RESET << "\n";
   std::cout << VERT << "Étape 14: Activation de la couche 0 et retrait de la deuxième forme" << RESET << "\n";
   if(canevas.activerCouche(0))
      std::cout << "Réussite : Activation de la couche 0" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 0" << RESET << endl;

   if(canevas.retirerForme(1))
      std::cout << "Réussite : la deuxième forme (index 1) a bien été retirée" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible de retirer la deuxième forme (index 1)" << RESET << endl;

   std::cout << VERT << "Étape 15: Réinitialisation de la couche 1" << RESET << "\n";
   if(canevas.reinitialiserCouche(1))
      std::cout << "Réussite : Réinitialisation de la couche 1" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible de réinitialiser la couche 1" << RESET << endl;

   std::cout << VERT << "Étape 16: Activation de la couche 2" << RESET << "\n";
   if(canevas.activerCouche(2))
      std::cout << "Réussite : Activation de la couche 2" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 2" << RESET << endl;

   std::cout << VERT << "Étape 17: Retrait de la couche 2" << RESET << "\n";
   if(canevas.retirerCouche(2))
      std::cout << "Réussite : la couche 2 a bien été retirée" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible de retirer la couche 2" << RESET << endl;

   std::cout << VERT << "Étape 18: Activation de la couche 4" << RESET << "\n";
   if(canevas.activerCouche(4))
      std::cout << "Réussite : Activation de la couche 4" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 4" << RESET << endl;

   std::cout << VERT << "Étape 19: Affichage du canevas" << RESET << "\n";
   canevas.afficher(std::cout);
   std::cout << VERT << "\nÉtape 20: Affichage de l'aire totale du canevas" << RESET;
   std::cout << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 21 à 23
   std::cout << "\n" << CYAN << "====================== Étapes 21 à 23 ======================" << RESET << "\n";
   std::cout << VERT << "Étape 21: Réinitialisation du canevas" << RESET << "\n";
   if(canevas.reinitialiser())
      std::cout << "Réussite : Réinitialisation du canevas" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible de réinitialiser le canevas" << RESET << endl;

   std::cout << VERT << "Étape 22: Affichage du canevas" << RESET << "\n";
   canevas.afficher(std::cout);
   std::cout << VERT << "\nÉtape 23: Affichage de l'aire totale du canevas" << RESET;
   std::cout << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 24 à 27
   std::cout << "\n" << CYAN << "====================== Étapes 24 à 27 ======================" << RESET << "\n";
   
   std::cout << VERT << "Étape 24: Activation de la couche 3 et ajout de formes" << RESET << "\n";
   if(canevas.activerCouche(3))
      std::cout << "Réussite : Activation de la couche 3" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 3" << RESET << endl;

   Carre* carre4 = new Carre(10, {10, 10});

   if(canevas.ajouterForme(carre4))
      std::cout << "Réussite : Ajout d'un carré (x=10, y=10, côté=10)" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter un carré (x=10, y=10, côté=10)" << RESET << endl;

   if(canevas.ajouterForme(nullptr))
      std::cout << "Réussite : Ajout d'une forme nullptr" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'ajouter une forme nullptr" << RESET << endl;

   std::cout << VERT << "Étape 25: Activation de la couche 6" << RESET << "\n";
   if(canevas.activerCouche(6))
      std::cout << "Réussite : Activation de la couche 6" << endl;
   else
      std::cout << ROUGE << "Échec : Impossible d'activer la couche 6" << RESET << endl;

   std::cout << VERT << "Étape 26: Affichage du canevas" << RESET << "\n";
   canevas.afficher(std::cout);
   std::cout << VERT << "\nÉtape 27: Affichage de l'aire totale du canevas" << RESET;
   std::cout << "\nAire totale du canevas : " << canevas.aire() << std::endl;
}

void Tests::tests_application_cas_02()
{
   cout << "TESTS APPLICATION (CAS 02)" << endl;  
    // Il faut ajouter les operations realisant ce scenario de test.
}
