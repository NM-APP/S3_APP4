/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 13 juin 2024 (creation)
 * Modifie par : dumn1101 boum3864
 * Date : 25 Juin 2024
 * Description: Implementation des methodes des classes decrites dans
 *    tests.h.  Ce fichier peut etre adapte a vos besoins de tests. 
 *    Ce fichier fait partie de la distribution de Graphicus.
********/

#include <iostream>
#include <fstream>
#include "tests.h"
#include "vecteur.h"
#include "rectangle.h"
#include "carre.h"
#include "cercle.h"
#include "couche.h"

void Tests::tests_unitaires_formes()
{
   Forme* rect = new Rectangle();
   rect->afficher(std::cout);
   delete rect;

   Forme* rect2 = new Rectangle(3, 3, {2, 2});
   rect2->afficher(std::cout);
   delete rect2;

   std::cout << "\n\n";

   Forme* carre = new Carre();
   carre->afficher(std::cout);
   delete carre;

   Forme* carre2 = new Carre(3, {2, 2});
   carre2->afficher(std::cout);
   delete carre2;

   std::cout << "\n\n";

   Forme* cercle = new Cercle();
   cercle->afficher(std::cout);
   delete cercle;

   Forme* cercle2 = new Cercle(3, {2, 2});
   cercle2->afficher(std::cout);
   delete cercle2;

   std::cout << "\n\n";
}

void Tests::tests_unitaires_couche()
{
   Couche couche;

   Forme* carre = new Carre();
   Forme* cercle = new Cercle();
   Forme* rectangle = new Rectangle();
   Forme* carre2 = new Carre();
   Forme* cercle2 = new Cercle();

   couche.changerEtat(Couche::Etat::active);
   couche.ajouterForme(carre);
   couche.ajouterForme(carre2);
   couche.ajouterForme(cercle);
   couche.ajouterForme(cercle2);
   couche.ajouterForme(rectangle);

   couche.afficher(std::cout);
   couche.translater(20, -10);
   couche.afficher(std::cout);

   couche.reinitialiser();

   rectangle->afficher(std::cout);
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
   ofstream myfile;
   myfile.open ("resultats_tests_cas_01.txt");

   myfile << "TESTS APPLICATION (CAS 01)\n\n";

   Canevas canevas;

   // Étape 1 à 2
   myfile << "\n====================== Étape 1 et 2 ======================\n";
   myfile << "Étape 1: Affichage du canevas\n";
   canevas.afficher(myfile);
   myfile << "\nÉtape 2: Affichage de l'aire totale du canevas";
   myfile << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 3 à 5
   myfile << "\n====================== Étapes 3 à 5 ======================\n";
   myfile << "Étape 3: Ajout de 5 couches au canevas\n";
   for(int i = 0; i<5; i++)
   {
      if(canevas.ajouterCouche())
         myfile << "Réussite : Ajout d'une couche vide" << endl;
      else
         myfile << "Échec : Impossible d'ajouter une couche" << endl;
   }
   myfile << "Étape 4: Affichage du canevas\n";
   canevas.afficher(myfile);
   myfile << "\nÉtape 5: Affichage de l'aire totale du canevas";
   myfile << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 6 à 9
   myfile << "\n====================== Étapes 6 à 9 ======================\n";
   myfile << "Étape 6: Activation de la couche 2 et ajout de formes\n";

   Cercle* cercle1 = new Cercle(5, {0, 1});
   Carre* carre1 = new Carre(6, {1, 2});
   Rectangle* rectangle1 = new Rectangle(4, 9, {2, 3});

   if(canevas.activerCouche(2))
      myfile << "Réussite : Activation de la couche 2" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 2" << endl;

   if(canevas.ajouterForme(cercle1))
      myfile << "Réussite : Ajout d'un cercle (x=0, y=1, rayon=5)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un cercle" << endl;

   if(canevas.ajouterForme(carre1))
      myfile << "Réussite : Ajout d'un carré (x=1, y=2, côté=6)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un carré" << endl;

   if(canevas.ajouterForme(rectangle1))
      myfile << "Réussite : Ajout d'un rectangle (x=2, y=3, largeur=4, hauteur=9)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un rectangle" << endl;

   myfile << "Étape 7: Activation de la couche 1 et ajout de forme\n";
   if(canevas.activerCouche(1))
      myfile << "Réussite : Activation de la couche 1" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 1" << endl;

   Rectangle* rectangle2 = new Rectangle(12, 3, {0, 0});

   if(canevas.ajouterForme(rectangle2))
      myfile << "Réussite : Ajout d'un rectangle (x=0, y=0, largeur=12, hauteur=3)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un rectangle" << endl;

   myfile << "Étape 8: Affichage du canevas\n";
   canevas.afficher(myfile);
   myfile << "\nÉtape 9: Affichage de l'aire totale du canevas";
   myfile << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 10 à 13
   myfile << "\n====================== Étapes 10 à 13 ======================\n";
   myfile << "Étape 10: Activation de la couche 0 et ajout de formes\n";

   Cercle* cercle3 = new Cercle(1, {0, 0});
   Carre* carre3 = new Carre(1, {0, 0});
   Rectangle* rectangle3 = new Rectangle(1, 1, {0, 0});

   if(canevas.activerCouche(0))
      myfile << "Réussite : Activation de la couche 0" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 0" << endl;
   if(canevas.ajouterForme(rectangle3))
      myfile << "Réussite : Ajout d'un rectangle (x=0, y=0, largeur=1, hauteur=1)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un rectangle" << endl;

   if(canevas.ajouterForme(carre3))
      myfile << "Réussite : Ajout d'un carré (x=0, y=0, côté=1)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un carré" << endl;

   if(canevas.ajouterForme(cercle3))
      myfile << "Réussite : Ajout d'un cercle (x=0, y=0, rayon=1)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un cercle" << endl;

   myfile << "Étape 11: Activation de la couche 2 et application d'une translation de (x=2, y=1)\n";
   if(canevas.activerCouche(2))
      myfile << "Réussite : Activation de la couche 2" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 2" << endl;

   if(canevas.translater(2, 1))
      myfile << "Réussite : Translation de la couche 2" << endl;
   else
      myfile << "Échec : Impossible de translater la couche 2" << endl;

   myfile << "Étape 12: Affichage du canevas\n";
   canevas.afficher(myfile);
   myfile << "\nÉtape 13: Affichage de l'aire totale du canevas";
   myfile << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 14 à 20
   myfile << "\n====================== Étapes 14 à 20 ======================\n";
   myfile << "Étape 14: Activation de la couche 0 et retrait de la deuxième forme\n";
   if(canevas.activerCouche(0))
      myfile << "Réussite : Activation de la couche 0" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 0" << endl;

   if(canevas.retirerForme(1))
      myfile << "Réussite : la deuxième forme (index 1) a bien été retirée" << endl;
   else
      myfile << "Échec : Impossible de retirer la deuxième forme (index 1)" << endl;

   myfile << "Étape 15: Réinitialisation de la couche 1\n";
   if(canevas.reinitialiserCouche(1))
      myfile << "Réussite : Réinitialisation de la couche 1" << endl;
   else
      myfile << "Échec : Impossible de réinitialiser la couche 1" << endl;

   myfile << "Étape 16: Activation de la couche 2\n";
   if(canevas.activerCouche(2))
      myfile << "Réussite : Activation de la couche 2" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 2" << endl;

   myfile << "Étape 17: Retrait de la couche 2\n";
   if(canevas.retirerCouche(2))
      myfile << "Réussite : la couche 2 a bien été retirée" << endl;
   else
      myfile << "Échec : Impossible de retirer la couche 2" << endl;

   myfile << "Étape 18: Activation de la couche 4\n";
   if(canevas.activerCouche(4))
      myfile << "Réussite : Activation de la couche 4" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 4" << endl;

   myfile << "Étape 19: Affichage du canevas\n";
   canevas.afficher(myfile);
   myfile << "\nÉtape 20: Affichage de l'aire totale du canevas";
   myfile << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 21 à 23
   myfile << "\n====================== Étapes 21 à 23 ======================\n";
   myfile << "Étape 21: Réinitialisation du canevas\n";
   if(canevas.reinitialiser())
      myfile << "Réussite : Réinitialisation du canevas" << endl;
   else
      myfile << "Échec : Impossible de réinitialiser le canevas" << endl;

   myfile << "Étape 22: Affichage du canevas\n";
   canevas.afficher(myfile);
   myfile << "\nÉtape 23: Affichage de l'aire totale du canevas";
   myfile << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   // Étapes 24 à 27
   myfile << "\n====================== Étapes 24 à 27 ======================\n";
   
   myfile << "Étape 24: Activation de la couche 3 et ajout de formes\n";
   if(canevas.activerCouche(3))
      myfile << "Réussite : Activation de la couche 3" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 3" << endl;

   Carre* carre4 = new Carre(10, {10, 10});

   if(canevas.ajouterForme(carre4))
      myfile << "Réussite : Ajout d'un carré (x=10, y=10, côté=10)" << endl;
   else
      myfile << "Échec : Impossible d'ajouter un carré (x=10, y=10, côté=10)" << endl;

   if(canevas.ajouterForme(nullptr))
      myfile << "Réussite : Ajout d'une forme nullptr" << endl;
   else
      myfile << "Échec : Impossible d'ajouter une forme nullptr" << endl;

   myfile << "Étape 25: Activation de la couche 6\n";
   if(canevas.activerCouche(6))
      myfile << "Réussite : Activation de la couche 6" << endl;
   else
      myfile << "Échec : Impossible d'activer la couche 6" << endl;

   myfile << "Étape 26: Affichage du canevas\n";
   canevas.afficher(myfile);
   myfile << "\nÉtape 27: Affichage de l'aire totale du canevas";
   myfile << "\nAire totale du canevas : " << canevas.aire() << std::endl;

   myfile.close();
}

void Tests::tests_application_cas_02() {
    std::ofstream myfile("resultats_tests_cas_02.txt");
    myfile << "TESTS APPLICATION (CAS 02)\n\n";

    Canevas canevas;

    // Étape 1
    myfile << "\n====================== Étape 1 ======================\n";
    myfile << "Étape 1: Ajout de 3 couches au canevas\n";
    for(int i = 0; i < 3; i++) {
        if(canevas.ajouterCouche())
            myfile << "Réussite : Ajout d'une couche vide" << std::endl;
        else
            myfile << "Échec : Impossible d'ajouter une couche" << std::endl;
    }

    // Étape 2
    myfile << "\n====================== Étape 2 ======================\n";
    myfile << "Étape 2: Tentative d'ajout de formes à une couche inactive (couche 4)\n";

    Cercle* cercle = new Cercle(10, {5, 5});
    Carre* carre = new Carre(4, {2, 2});

    if(canevas.activerCouche(4))
        myfile << "Échec : Activation de la couche 4 (couche non ajoutée)" << std::endl;
    else
        myfile << "Réussite : Impossible d'activer la couche 4 (couche non ajoutée)" << std::endl;

    if(canevas.ajouterForme(cercle))
        myfile << "Échec : Ajout d'un cercle à une couche inactive (couche 4)" << std::endl;
    else
        myfile << "Réussite : Impossible d'ajouter un cercle à une couche inactive (couche 4)" << std::endl;

    if(canevas.ajouterForme(carre))
        myfile << "Échec : Ajout d'un carré à une couche inactive (couche 4)" << std::endl;
    else
        myfile << "Réussite : Impossible d'ajouter un carré à une couche inactive (couche 4)" << std::endl;

    // Étape 3
    myfile << "\n====================== Étape 3 ======================\n";
    myfile << "Étape 3: Activation de la couche 1 et ajout de formes\n";

    if(canevas.activerCouche(1))
        myfile << "Réussite : Activation de la couche 1" << std::endl;
    else
        myfile << "Échec : Impossible d'activer la couche 1" << std::endl;

    if(canevas.ajouterForme(cercle))
        myfile << "Réussite : Ajout d'un cercle (x=5, y=5, rayon=10)" << std::endl;
    else
        myfile << "Échec : Impossible d'ajouter un cercle" << std::endl;

    if(canevas.ajouterForme(carre))
        myfile << "Réussite : Ajout d'un carré (x=2, y=2, côté=4)" << std::endl;
    else
        myfile << "Échec : Impossible d'ajouter un carré" << std::endl;

    // Étape 4
    myfile << "\n====================== Étape 4 ======================\n";
    myfile << "Étape 4: Tentative d'ajout de forme nullptr\n";
   
    if(canevas.ajouterForme(nullptr))
        myfile << "Échec : Ajout d'une forme nullptr" << std::endl;
    else
        myfile << "Réussite : Impossible d'ajouter une forme nullptr" << std::endl;

    // Étape 5
    myfile << "\n====================== Étape 5 ======================\n";
    myfile << "Étape 5: Affichage du canevas\n";
    canevas.afficher(myfile);

    // Étape 6
    myfile << "\n====================== Étape 6 ======================\n";
    myfile << "Étape 6: Affichage de l'aire totale du canevas\n";
    myfile << "Aire totale du canevas : " << canevas.aire() << std::endl;

    // Étape 7
    myfile << "\n====================== Étape 7 ======================\n";
    myfile << "Étape 7: Activation de la couche 1 et retrait de la première forme\n";
    if(canevas.activerCouche(1))
        myfile << "Réussite : Activation de la couche 1" << std::endl;
    else
        myfile << "Échec : Impossible d'activer la couche 1" << std::endl;

    if(canevas.retirerForme(0))
        myfile << "Réussite : la première forme (index 0) a bien été retirée" << std::endl;
    else
        myfile << "Échec : Impossible de retirer la première forme (index 0)" << std::endl;

    // Étape 8
    myfile << "\n====================== Étape 8 ======================\n";
    myfile << "Étape 8: Tentative de retrait d'une forme à partir d'une couche vide (index 1)\n";

    if(canevas.retirerForme(1))
        myfile << "Échec : Retrait d'une forme dans une couche vide (index 1)" << std::endl;
    else
        myfile << "Réussite : Impossible de retirer une forme dans une couche vide (index 1)" << std::endl;

    // Étape 9
    myfile << "\n====================== Étape 9 ======================\n";
    myfile << "Étape 9: Affichage du canevas\n";
    canevas.afficher(myfile);

    // Étape 10
    myfile << "\n====================== Étape 10 ======================\n";
    myfile << "Étape 10: Affichage de l'aire totale du canevas\n";
    myfile << "Aire totale du canevas : " << canevas.aire() << std::endl;

    // Étape 11
    myfile << "\n====================== Étape 11 ======================\n";
    myfile << "Étape 11: Réinitialisation du canevas\n";
    if(canevas.reinitialiser())
        myfile << "Réussite : Réinitialisation du canevas" << std::endl;
    else
        myfile << "Échec : Impossible de réinitialiser le canevas" << std::endl;

    // Étape 12
    myfile << "\n====================== Étape 12 ======================\n";
    myfile << "Étape 12: Affichage du canevas\n";
    canevas.afficher(myfile);

    // Étape 13
    myfile << "\n====================== Étape 13 ======================\n";
    myfile << "Étape 13: Affichage de l'aire totale du canevas\n";
    myfile << "Aire totale du canevas : " << canevas.aire() << std::endl;

    myfile.close();
}