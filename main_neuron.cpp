
#include <iostream>
#include <cmath>
#include "neuron.hpp" 
#include <string>
#include <fstream>
#include "network.hpp"
#include "Spikes.gdb" 

using namespace std ; 

int main () { 
	unsigned int duration ; 
	double ratio ; 
	double weight ; 
	cout << " how long do you want your simulation to be ? (in ms) " << endl ; 
	cin >> duration ; 
	duration = duration*10 ; // we multiply by ten to have the right amount of time steps 
	cout << " what is your Vext/Vthr ratio ? " << endl ; 
	cin >> ratio ; 
	cout << " what is the relative inhibitory weight ? " << endl ; 
	cin >> weight ;
	Network n (10000, 2500, ratio , weight ) ;
	for (unsigned int i(0) ; i<duration ; ++i ) {
		n.refreshNetwork (i) ;}
	n.produceFigure () ;
	return 0 ; 
} 
