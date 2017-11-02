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
		e.refreshNetwork(global_clock) ; 
		}
	e.produceFigure() ;
	return 0 ; 
} 
