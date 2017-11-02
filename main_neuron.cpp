#include "neuron.hpp" 
#include "network.hpp"
#include "experiment.hpp" 

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
