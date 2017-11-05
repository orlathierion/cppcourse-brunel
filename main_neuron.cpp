
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
	Neuron n (true) ;
	//Network t(3, 2); 
	Experiment e; 
	n.RefreshPotential (1) ; 
	n.PrintRecord () ;
	//t.refreshNetwork (1) ;  
	return 0 ; 
} 
