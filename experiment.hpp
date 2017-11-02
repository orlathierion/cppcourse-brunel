#ifndef EXPERIMENT
#define EXPERIMENT

#include <iostream>
#include "network.hpp" 
#include <random> 
#include <vector>
 
using namespace std ; 

class Experiment {
	private : 
	Network n ; 
	
	public :
	Experiment () ; 
	~Experiment () ; 
	void refreshNetwork (int h) ; 
	void produceFigure (); 
	};


#endif
