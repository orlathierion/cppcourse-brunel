#include <iostream> 
#include "excitatory.hpp" 

/**
 * \class excitatory 
 * this class represents the excitatory neurons of the network. 
 */

bool Excitatory::IsExcitatory () {
	return true ; }

Excitatory::Excitatory () : 
Neuron () {}

Excitatory::~Excitatory () {}
