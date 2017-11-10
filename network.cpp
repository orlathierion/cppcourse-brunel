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
 
Network::Network (unsigned int e, unsigned int i, double weight, double ratio) :  
Ce (e),
Ci (i),
TimeStep (0) ,
Vthr(0.01)
{	
	for (unsigned int i (0); i<=Ce ; ++i ) { 
		Neuron* e(new Neuron(true, Vthr*ratio, weight, 1000)) ; 
		netE.push_back(e) ;}
	for ( unsigned int i (0); i<=Ci ; ++i ) {
		Neuron* y(new Neuron(false, Vthr*ratio, weight, 1000)) ; 
		netI.push_back(y) ; 
		}
		cout << "all neuron are created netyorp cpp 26 " << endl ; 
	createConnexion(); 
	cout << "all neurons are connected network cpp 28 " << endl ;  }
	
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
	for (unsigned int i (0); i<Ce - 1; ++i ){ 
		for (unsigned int j (0); j<0.1*Ce - 1 ; ++j ) {
			netE[i]->addConnection(getExcitatory(disE(gen))); }
		for (unsigned int j (0); j<0.1*Ci - 1 ; ++j ) {
			netE[i]->addConnection(getInhibitory(disE(gen))); }}
	for (unsigned int i (0); i<Ci - 1 ; ++i ){
		for (unsigned int j (0); j<0.1*Ce - 1; ++j ) {
			netI[i]->addConnection(getExcitatory(disI(gen))); }
		for (unsigned int j (0); j<0.1*Ci- 1 ; ++j ) {
			netI[i]->addConnection(getInhibitory(disI(gen))); }}
	}
	

	
Neuron* Network::getInhibitory (unsigned int i ) {
	return netI[i] ; 
	}


Neuron* Network::getExcitatory (unsigned int e) {
	return netE[e] ;
	}


void Network::refreshNetwork (int h) {
	
	for (unsigned int j(0); j<Ci - 1; ++j) {
		netI[j]->RefreshPotential(h) ; 
		}
	for (unsigned int i(0); i<Ce -1 ; ++i) {
		getExcitatory(i)->RefreshPotential(h) ;
		  }
		  
	
	++TimeStep;
}

void Network::produceFigure () {
	ofstream o ("Spikes.gdb", ios::out ) ;
	for (unsigned int i(0) ; i< 3; ++i) {
		o<< "numero : " << 1 << "  "  ; 
		this->getExcitatory(1)->PrintSpike () ;}
	for (unsigned int i(0) ; i<3 ; ++i) {
		o<< "numero : " << i+Ce*0.1 << "  "  ;
		this->getInhibitory(i)->PrintSpike () ; 
		}
	getInhibitory(1)->PrintRecord () ;
	o.close () ; 
}
