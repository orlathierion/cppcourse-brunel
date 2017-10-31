#include <iostream>
#include <cmath>
#include "neuron.hpp" 
#include <string>
#include <fstream>
#include "network.hpp"

using namespace std ; 

int main (int argc, char* argv[]) {
	Network n ; 
	for ( int global_clock (0) ; global_clock<20 ; ++global_clock) {
		n.refreshNetwork(global_clock) ; 
		}
	n.produceFigure() ;
	return 0 ; 
	} 
