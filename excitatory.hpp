ifndef EXCITATORY
#define EXCITATORY 

#include <iostream> 
#include "neuron.hpp"
#include <array>

using namespace std ; 

class Excitatory : public Neuron {
	private : 
	
	public : 
	Excitatory () ;
	bool IsExcitatory () override ; 
	~Excitatory () ; 
	};
	
#endif 
