#include <iostream>
#include <cmath>
#include "neuron.hpp" 
#include <string>
#include <fstream>
#include "network.hpp" 

using namespace std ; 

int main () { 
	unsigned int duration ; 
	double ratio ; 
	double weight ; 
	cout << " how long do you want your simulation to be ? (in ms) " << endl ; 
	cin >> duration ;
	duration = duration*10 ; 
	cout << " what is your Vext/Vthr ratio ? " << endl ; 
	cin >> ratio ; 
	cout << " what is the relative inhibitory weight ? " << endl ; 
	cin >> weight ;
	Network n (10000, 2500, ratio , weight ) ;
	for (unsigned int i(0) ; i<duration ; ++i ) {
		n.refreshNetwork () ;}
	n.produceFigure () ;
	return 0 ; 
} 
