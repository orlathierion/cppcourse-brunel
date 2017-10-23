#include <iostream> 
#include <gtest> 
#include "neuron.cpp" 

using namespace std ; 

TEST (neuron_test, connexion_neuron) {
	//trouver un moyen de faire le test 1 en mode gtest
	}
	
TEST (neuron_test, testbuffer) {
Neuron n ; 
n.RefreshPotential ()	} 

TEST (neuron_test, testspike){
	Neuron n ; 
	n.setI (0) ; 
	n.setIntervalle (0, 10) ; 
	for (int i (1), i<10, ++i) {
		n.RefreshPotential (i) ; 
		ASSERT_NEAR (n.getPotential (), 0.00) ; } 
	n.setI (1.0 ) ; 
	for (int i (1), i<10, ++i) {
		n.RefreshPotential (i) ; 
		ASSERT_NEAR (n.getPotential (), 20.00) ; } 
	
	}

int main () {
	return RUN_ALL_TESTS () ; 
	}
