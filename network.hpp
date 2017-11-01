#ifndef NETWORK
#define NETWORK

#include <iostream>
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
	vector <Neuron*> netI ; 
	vector <Neuron*> netE ; 
	unsigned int Ce ; 
	unsigned int Ci ; 
	int TimeStep ; 
	
	public :
	Network () ; 
	void createConnexion () ;
	Neuron* getInhibitory (unsigned int I) ; 
	Neuron* getExcitatory (unsigned int E ) ;  
	void refreshNetwork (int h) ; 
	void produceFigure (); 
	 
	
	};


#endif

