#ifndef INHIBITORY
#define INHIBITORY

#include <iostream> 
#include "neuron.hpp"
#include <array>

using namespace std ; 

class Inhibitory : public Neuron {
	private : 
	
	public : 
	Inhibitory () ; 
	bool IsExcitatory () override ;
	~Inhibitory () ; 
	} ;
	

#endif 
