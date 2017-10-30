#include "network.hpp"
#include <iostream> 
#include <random>
#include <vector>

/**
 * \class Network 
 * this class represent the network of inhibitory and excitatory neuron as brunel described it
 * it has 4 attribute: 
 * netI : a vector with all the inhibitory neuron
 * netE : a vector with all the excitatory neuron
 * Ci : the number of inhibitory neurons 
 * Ce : the number of excitatory neurons
 **/
 
Network::Network () : 
TimeStep (0) , 
Ce (10000),
Ci (2500) 
{
	for (unsigned int i (0); i<Ce ; ++i ) {
		Excitatory e(i) ; 
		netE.push_back (&e) ;}
	for ( unsigned int i (0); i<Ci ; ++i ) {
		Inhibitory y(i) ; 
		netI.push_back (&y) ; 
		}
	createConnexion();  }
		
/**
 * \fn (createConnexion ()) 
 * this fonction will create the different connexion for all the neuron
 **/

void Network::createConnexion () {
	for (unsigned int i (0); i<Ce ; ++i ){ 
		for (unsigned int j (0); j<0.1*Ce ; ++j ) {
			random_device rd ; 
			mt19937 gen(rd()) ; 
			uniform_int_distribution<> dis(0, Ce) ; 
			netE[i]->addConnection(getExcitatory (dis(gen))); }
		for (unsigned int j (0); j<0.1*Ci ; ++j ) {
			random_device rd ; 
			mt19937 gen(rd()) ; 
			uniform_int_distribution<> dis(0, Ci) ; 
			netE[i]->addConnection(getInhibitory(dis(gen))); }}
	for (unsigned int i (0); i<Ci ; ++i ){
		for (unsigned int j (0); j<0.1*Ce ; ++j ) {
			random_device rd ; 
			mt19937 gen(rd()) ; 
			uniform_int_distribution<> dis(0, Ce) ; 
			netI[i]->addConnection(getExcitatory(dis(gen))); }
		for (unsigned int j (0); j<0.1*Ci ; ++j ) {
			random_device rd ; 
			mt19937 gen(rd()) ; 
			uniform_int_distribution<> dis(0, Ci) ;
			netI[i]->addConnection(getInhibitory(dis(gen))); }}
	}
	
/**
 * \fn (getInhibitory (unsigned int i ) 
 * \param <i> {the number of the inhibitory neuron we want to access to } 
 * \return {it returns the Ith inhibitory neuron of the network}
 **/
	
Inhibitory* Network::getInhibitory (unsigned int i ) {
	return netI [i] ; 
	}

/**
 * \fn (getExcitatory (unsigned int e) ) 
 * \param <e> {the numero of the excitatory neuron we want to access to } 
 * \return {a pointer on the neuron we want to access to} 
 **/

Excitatory* Network::getExcitatory (unsigned int e) {
	return netE [e] ;
	}

/**
 * \fn (refreshNetwork ()) 
 * this fonction will refresh all the neuron of the network simultaneously
 **/

void Network::refreshNetwork (int h) {
	for (unsigned int i(0); i<Ce ; ++i) {
		netE[i]->RefreshPotential(h) ;
		}
	for (unsigned int j(0); j<Ci; ++j) {
		netI[j]->RefreshPotential(h) ; 
		}
	++time 
	}
