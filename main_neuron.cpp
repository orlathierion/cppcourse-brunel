#include <iostream>
#include <cmath>
#include "neuron.hpp" 
#include <string>
#include <fstream>
#include "network.hpp"
#include "experiments.hpp" 
#include "results.txt" 

using namespace std ; 

int main () { 
	Network n (10000, 2500) ;
	for (unsigned int i(0) ; i<100 ; ++i ) {
		n.refreshNetwork (i) ;}
	n.produceFigure () ;
	return 0 ; 
} 
