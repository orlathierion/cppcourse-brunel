#include <iostream>
#include "inhibitory.hpp" 
#include <random> 


/**
 * \class Inhibitory
 * this class inherit of Neuron and correspond to the inhibitory neuron, 
 * the constructeur take as parameter an integer that corresponds to its identification number
 **/ 
 
/**
 * \fn (IsExcitatory() ) 
 * this fonction allows us to kow if it is excitatory or not 
 * \return {it returns false  }
 **/  

bool Inhibitory::IsExcitatory () {
	return false; }
	
Inhibitory::Inhibitory () :
Neuron ()
 {}

Inhibitory::~Inhibitory () {} 
