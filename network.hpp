
#ifndef NETWORK
#define NETWORK

#include <iostream>
#include "neuron.hpp" 
#include <random> 
#include <vector>
#include <fstream>
 
 
using namespace std ; 

/**
 * \class Network 
 * this class represents the network of inhibitory and excitatory neuron as brunel described it.
 * it has 6 attributes: 
 * netI : a vector with all the inhibitory neuron
 * netE : a vector with all the excitatory neuron
 * Ci : the number of inhibitory neurons 
 * Ce : the number of excitatory neurons
 * TimeStep : the global clock of the network
 **/

class Network {
	private : 
	vector <Neuron*> netI ; 
	vector <Neuron*> netE ; 
	unsigned int Ce ; 
	unsigned int Ci ; 
	int TimeStep ; 
	double Vthr ; 
	
	public :
	
/**
 * \fn Network (unsigned int e, unsigned int i, double weight, double ratio)
 * \param e : number of excitatory neuron
 * \param i : number of inhibitory neuron
 * \param weight : relative inhibitory
 * \param ratio : ratio Vext/Vthr
 **/
	
	Network (unsigned int e, unsigned int i, double weight, double ratio) ;
	 
	~Network () ; 
	
/**
 * \fn void createConnexion () 
 * \brief This fonction will create the different connexion for all the neuron.
 **/
	void createConnexion () ;
	
/**
 * \fn Neuron* getInhibitory (unsigned int I)  
 * \param i: the number of the inhibitory neuron we want to access to.  
 * \return it returns the Ith inhibitory neuron of the network.
 **/
 
	Neuron* getInhibitory (unsigned int I) ; 
	
/**
 * \fn Neuron* getExcitatory (unsigned int e)  
 * \param e : the numero of the excitatory neuron we want to access to.  
 * \return a pointer on the neuron we want to access to. 
 **/
	Neuron* getExcitatory (unsigned int E ) ; 
	 
/**
 * \fn void refreshNetwork ( ) 
 * \brief This fonction will refresh all the neuron of the network simultaneously
 **/
	void refreshNetwork () ; 
	
/**
 * \fn void produceFigure () 
 * \brief This fonction will print the spiking time of 1% first neuron on the result sheet to allow us to produce figure 8. 
 **/

	
	void produceFigure (); 

	
	};


#endif
