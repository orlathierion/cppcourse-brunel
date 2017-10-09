#include <iostream>
#include <cmath>
#include "neuron.cpp" 
#include <string>

using namespace std ; 

int main () {
	double time (0.0) ; 
	double duration ;
	do{cout << "how long should the simulation be ? in ms " << endl ; 
		cin>> duration ; } while (duration < 0 ) ;
	Neuron n ;
	double Z ; 
	cout << "do you want to add an external imput ? " << endl ; 
	string a ; 
	cin>> a ; 
	if (a=="yes") {
	do {cout << " how much does this imput should be ?  " << endl ; 
	cin >> Z ;} while (Z<0);
	n.setI (Z) ; 
	do {cout << "when should it start ?  " << endl ; 
	cin >> Z ; }while (Z<0 or Z>duration ) ;  
	double r ; 
	do {cout << "when should it end ? " << endl ; 
	cin >> r ; } while (r<Z or r>duration ) ; 
	n.setIntervalle (Z, r) ; }
	while (time < duration ) {
		++time ;
		n.RefreshPotential (time) ; 
		n.setTime (time) ;  }
	n.PrintRecord () ;
	n.PrintSpike () ; 
	return 0 ; }

