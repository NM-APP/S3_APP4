#
# Auteur: C.-A. Brunet
# Date: 13 juin 2024
# Modifie par : ...
# Date : ...
# Description: compilation de graphicus-01. Ce fichier fait partie de 
#	la distribution de Graphicus.
#

graphicus-02: graphicus-02.o tests.o canevas.o vecteur.o couche.o forme.o rectangle.o carre.o cercle.o
	g++ -o graphicus-02 graphicus-02.o tests.o canevas.o vecteur.o couche.o forme.o rectangle.o carre.o cercle.o

graphicus-02.o: graphicus-02.cpp canevas.h couche.h forme.h rectangle.h
	g++ -c graphicus-02.cpp

tests.o: tests.cpp tests.h canevas.h couche.h forme.h rectangle.h
	g++ -c tests.cpp

canevas.o: canevas.cpp canevas.h couche.h forme.h vecteur.h
	g++ -c canevas.cpp

vecteur.o: vecteur.cpp vecteur.h couche.h forme.h
	g++ -c vecteur.cpp

couche.o: couche.cpp couche.h forme.h
	g++ -c couche.cpp

rectangle.o: rectangle.cpp rectangle.h forme.h
	g++ -c rectangle.cpp

carre.o: carre.cpp carre.h forme.h
	g++ -c carre.cpp

cercle.o: cercle.cpp cercle.h forme.h
	g++ -c cercle.cpp

forme.o: forme.cpp forme.h
	g++ -c forme.cpp


clean:
	rm  -f *.o
