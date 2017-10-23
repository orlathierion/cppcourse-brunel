#include <iostream> 
#include "neuron.hpp"
#include <array>

using namespace std ; 

class Inhibitory : public Neuron {
	private : 
	unsigned int IdentificationNumber ; 
	
	public : 
	Inhibitory (unsigned int nb) ; 
	bool IsExcitatory () override ; 
	unsigned int GetIdentification () const ; 
	void createConnexion () ;
	} ;
	
bool Inhibitory::IsExcitatory () {
	return false; }

Inhibitory::Inhibitory (unsigned int nb) :
Neuron () ,
IdentificationNumber (nb) {}

unsigned int Inhibitory::GetIdentification () const { 
	return IdentificationNumber ; }

void Inhibitory::createConnexion () {}
