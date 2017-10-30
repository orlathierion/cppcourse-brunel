
#include <iostream>
#include <cmath>
#include "neuron.hpp" 
#include "excitatory.hpp" 
#include "inhibitory.hpp"
#include <string>
#include <fstream>
#include "network.hpp"

using namespace std ; 

void produceFigure (Network* n ) ; 

int main () {
	Network n ; 
	for ( int global_clock (0) ; global_clock<20 ; ++global_clock) {
		n.refreshNetwork(global_clock) ; 
		}
	return 0 ; 
	} 

//ajouter une fonction produce figure qui cree la figure huit 

void produceFigure (Network* n ) {
	for (unsigned i(0) ; i<15 ; ++i) {
		getExcitatory(i)->printSpikes () ; 
		getInhibitory(i)->printSpikes () ; 
		}
	}
