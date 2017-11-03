#include <iostream>
#include <cmath>
#include "neuron.hpp" 
#include <string>
#include <fstream>
#include "network.hpp"
#include "experiment.hpp" 
#include "results.txt" 

using namespace std ; 

int main () { 
	Neuron n (true) ;
	Network t(2, 1);
	Experiment e; 
	for ( int global_clock (0) ; global_clock<20 ; ++global_clock) {
		cout << "crotte " << endl ; 
		t.refreshNetwork(global_clock) ; 
		}
	cout << "oups " << endl ; 
	t.produceFigure() ;
	return 0 ; 
} 
