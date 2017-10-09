#include <iostream>
#include <cmath>
#include "neuron.cpp" 
#include <string>

using namespace std ; 

int main () {
	int time (0) ; 
	double duration ;
	do{cout << "how long should the simulation be ? in ms " << endl ; //for now we chose a step to be 1 ms 
		cin>> duration ; } while (duration < 0 ) ;
	Neuron n ;
	Neuron m ; 
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
	n.setIntervalle (Z, r) ;  }
	n.addConnection (&m) ; 
	m.addConnection (&n) ; 
	while (time < duration ) {
		++time ;
		n.RefreshPotential (time) ; 
		m.RefreshPotential (time) ;  }
	cout << "For the first neuron : " << endl ; 
	n.PrintRecord () ;
	n.PrintSpike () ; 
	cout << "For the second neuron : " << endl ; 
	m.PrintRecord () ; 
	m.PrintSpike () ; 
return 0 ; }
