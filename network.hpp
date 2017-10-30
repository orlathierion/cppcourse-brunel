#ifndef NETWORK
#define NETWORK

#include <iostream>
#include "inhibitory.hpp"
#include "excitatory.hpp" 
#include "neuron.hpp" 
#include <random> 
#include <vector>

using namespace std ; 

/**
 * \class Network 
 * this class represent the network of inhibitory and excitatory neuron as brunel described it
 * it has 4 attribute: 
 * netI : a vector with all the inhibitory neuron
 * netE : a vector with all the excitatory neuron
 * Ci : the number of inhibitory neurons 
 * Ce : the number of excitatory neurons
 **/

class Network {
	private : 
	vector <Inhibitory*> netI ; 
	vector <Excitatory*> netE ; 
	unsigned int Ce ; 
	unsigned int Ci ; 
	int TimeStep ; 
	
	public :
	Network () ; 
	void createConnexion () ;
	Inhibitory* getInhibitory (unsigned int I) ; 
	Excitatory* getExcitatory (unsigned int E ) ;  
	void refreshNetwork (int h) ; 
	 
	
	};


#endif 
