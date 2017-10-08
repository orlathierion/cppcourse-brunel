#include <iostream>
#include <cmath>
#include "neuron.cpp" 

using namespace std ; 

int main () {
	double time (0.0) ; 
	double duration ;
	do{cout << "quelle durée doit avoir la simulation ? ( en ms) " << endl ; 
		cin>> duration ; } while (duration < 0 ) ;
	Neuron n ;
	double Z ; 
	do {cout << " A quel intensité voulez vous metttre I ? " << endl ; 
	cin >> Z ;} while (Z<0);
	n.setI (Z) ; 
	do {cout << "quand doit commencer cet entre " << endl ; 
	cin >> Z ; }while (Z<0 or Z>duration ) ;  
	double r ; 
	do {cout << "quand est ce que ca doit finir " << endl ; 
	cin >> r ; } while (r<Z or r>duration ) ; 
	n.setIntervalle (Z, r) ; 
	while (time < duration ) {
		++time ;
		n.RefreshPotential (time) ; 
		n.setTime (time) ;  }
	n.PrintRecord () ;
	return 0 ; }
