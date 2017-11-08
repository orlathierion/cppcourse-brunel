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
	Network t(10000, 2500); 
	Experiment e; 
	for (int i(0); i< 500 ; ++i ) {
		t.refreshNetwork (i) ; }
	t.produceFigure () ; 
	//t.getExcitatory(1)->PrintRecord () ; 
	cout << "on a fini le pg éain cpp 20 " << endl ; 
	return 0 ; 
} 
