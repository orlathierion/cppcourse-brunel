#include <iostream> 
#include "neuron.hpp"
#include <array>

using namespace std ; 

class Excitatory : public Neuron {
	private : 
	unsigned int IdentificationNumber ; 
	
	public : 
	Excitatory (unsigned int nb) ;
	bool IsExcitatory () override ; 
	unsigned int GetIdentification () const ;
	void createConnexion () ; 
	};
	
bool Excitatory::IsExcitatory () {
	return true ; }

Excitatory::Excitatory (unsigned int nb) : 
Neuron () , 
IdentificationNumber (nb) {}

unsigned int Excitatory::GetIdentification () const {
	return IdentificationNumber ; 
	}
void Excitatory::createConnexion () {}
