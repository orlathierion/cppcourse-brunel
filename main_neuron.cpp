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
	//Neuron n (true) ;
	Network t(3, 2); 
	Experiment e; 
	t.refreshNetwork (1) ; 
	t.refreshNetwork (2) ;  
	//t.produceFigure () ; 
	t.getExcitatory(1)->PrintRecord () ; 
	return 0 ; 
} 
