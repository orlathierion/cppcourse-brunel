#ifndef NETWORK
#define NETWORK

#include <iostream>
#include "neuron.hpp" 
#include <random> 
#include <vector>
#include <fstream>
#include "results.txt" 
 
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
	Network (unsigned int e, unsigned int i) ; 
	~Network () ; 
	
	/**
 * \fn (createConnexion ()) 
 * this fonction will create the different connexion for all the neuron
 **/
	void createConnexion () ;
	
	/**
 * \fn (getInhibitory (unsigned int i ) 
 * \param <i> {the number of the inhibitory neuron we want to access to } 
 * \return {it returns the Ith inhibitory neuron of the network}
 **/
 
	Neuron* getInhibitory (unsigned int I) ; 
	
/**
 * \fn (getExcitatory (unsigned int e) ) 
 * \param <e> {the numero of the excitatory neuron we want to access to } 
 * \return {a pointer on the neuron we want to access to} 
 **/
	Neuron* getExcitatory (unsigned int E ) ; 
	 
	/**
 * \fn (refreshNetwork ()) 
 * this fonction will refresh all the neuron of the network simultaneously
 **/
	void refreshNetwork (int h) ; 
	
	/**
 * \fn (produceFigure ()) 
 * this fonction will print the spiking time of the 30 first neuron on the result sheet to allow us to produce figure 8 
 **/

	
	void produceFigure (); 

	
	};


#endif
