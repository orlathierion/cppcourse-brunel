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
	Network t(3, 2); 
	//Experiment e; 
	t.refreshNetwork (1) ;  
	return 0 ; 
} 
