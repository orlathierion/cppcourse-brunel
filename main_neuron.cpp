#include <iostream>
#include <cmath>
#include "neuron.hpp" 
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
	produceFigure (&n) ;
	return 0 ; 
	} 

void produceFigure (Network* n ) {
	for (unsigned i(0) ; i<15 ; ++i) {
		n->getExcitatory(i)->PrintSpike () ; 
		n->getInhibitory(i)->PrintSpike () ; 
		}
}
