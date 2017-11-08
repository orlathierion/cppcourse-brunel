#include "network.hpp"

/**
 * \class Network 
 * this class represent the network of inhibitory and excitatory neuron as brunel described it
 * it has 4 attribute: 
 * netI : a vector with all the inhibitory neuron
 * netE : a vector with all the excitatory neuron
 * Ci : the number of inhibitory neurons 
 * Ce : the number of excitatory neurons
 **/
 
Network::Network (unsigned int e, unsigned int i) :  
Ce (e),
Ci (i),
TimeStep (0) 
{
	for (unsigned int i (0); i<Ce ; ++i ) { 
		Neuron* e(new Neuron(true)) ; 
		netE.push_back(e) ;}
	for ( unsigned int i (0); i<Ci ; ++i ) {
		Neuron* y (new Neuron(false)) ; 
		netI.push_back(y) ; 
		}
	createConnexion();  }
	
Network::~Network () {
	for (unsigned int i (0); i<Ce ; ++i ) { 
		delete netE[i] ; 
		}
	for ( unsigned int i (0); i<Ci ; ++i ) {
		delete netI[i] ; 
		}
	}
		

void Network::createConnexion () {
	static random_device rd ; 
	static mt19937 gen (rd()) ; 
	static uniform_int_distribution<> disE(0, Ce) ; 
	static uniform_int_distribution<> disI(0, Ci) ; 
	for (unsigned int i (0); i<Ce ; ++i ){ 
		for (unsigned int j (0); j<0.1*Ce ; ++j ) {
			netE[i]->addConnection(getExcitatory(disE(gen))); }
		for (unsigned int j (0); j<0.1*Ci ; ++j ) {
			netE[i]->addConnection(getInhibitory(disE(gen))); }}
	for (unsigned int i (0); i<Ci ; ++i ){
		for (unsigned int j (0); j<0.1*Ce ; ++j ) {
			netI[i]->addConnection(getExcitatory(disI(gen))); }
		for (unsigned int j (0); j<0.1*Ci ; ++j ) {
			netI[i]->addConnection(getInhibitory(disI(gen))); }}
	}
	

	
Neuron* Network::getInhibitory (unsigned int i ) {
	return netI[i] ; 
	}


Neuron* Network::getExcitatory (unsigned int e) {
	return netE[e] ;
	}


void Network::refreshNetwork (int h) {
	for (unsigned int i(0); i<Ce ; ++i) {
		getExcitatory(i)->RefreshPotential(h) ;
		  }
	for (unsigned int j(0); j<Ci ; ++j) {
		netI[j]->RefreshPotential(h) ; 
		}
	++TimeStep;
}

void Network::produceFigure () {
	for (unsigned int i(0) ; i<20 ; ++i) {
		this->getExcitatory(i)->PrintSpike () ;
		this->getInhibitory(i)->PrintSpike () ; 
		}
}
