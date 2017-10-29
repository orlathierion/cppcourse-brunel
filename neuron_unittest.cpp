#include <iostream> 
#include <gtest> 
#include "neuron.hpp" 

using namespace std ; 

TEST (NeuronTest, PotentialZEROTest) {
	Excitatory* E ;
	Inhibitory* I ; 
	E->setI(0) ; 
	I->setI (0) ; 
	E->setIntervalle (0; 20) ; 
	I->setIntervalle (0;20) ; 
	for (unsigned int j (0) ; j<20 ; ++j) {
		E->setTime (j) ; 
		I->setTime (j) ;
		E->refreshPotential () ; 
		I->refreshPotential () ; 
	}
	EXPECTED_EQ(E->getNumberSpikes(), 0) ;
	EXPECTED_EQ(I->getNumberSpikes(), 0) ; 
	EXTECTED_EQ(E->getPotential(), 0.0 ) ; 
	EXPECTED_EQ(I->getPotential(), 0.0 ) ;
}

TEST(NeuronTest, PotentialONETest) {
	Excitatory* E ;
	Inhibitory* I ; 
	E->setI(1.00) ; 
	I->setI (1.00) ; 
	E->setIntervalle (0; 20) ; 
	I->setIntervalle (0;20) ; 
	for (unsigned int j (0) ; j<20 ; ++j) {
		E->setTime (j) ; 
		I->setTime (j) ;
		E->refreshPotential () ; 
		I->refreshPotential () ; 
	}
	EXPECTED_EQ(E->getNumberSpikes(), 0) ;
	EXPECTED_EQ(I->getNumberSpikes(), 0) ; 
	EXTECTED_DOUBLE_EQ(E->getPotential(), 20.0 ) ; 
	EXPECTED_DOUBLE_EQ(I->getPotential(), 20.0 ) ;
}

TEST(NeuronTest, PotentialTWOTest) {
	Excitatory* E ;
	Inhibitory* I ; 
	E->setI(1.01) ; 
	I->setI (1.01) ; 
	E->setIntervalle (0; 20) ; 
	I->setIntervalle (0;20) ; 
	for (unsigned int j (0) ; j<20 ; ++j) {
		E->setTime (j) ; 
		I->setTime (j) ;
		E->refreshPotential () ; 
		I->refreshPotential () ; 
	}
	EXPECTED_GT(E->getNumberSpikes(), 0) ;
	EXPECTED_GT(I->getNumberSpikes(), 0) ; 
}

TEST(NeuronTest, SpikeBufferTest) {
	Excitatory* E ;
	Inhibitory* I ; 
	E->addConnexion (I) ; 
	I->addConnexion (E) ; 
	E->setI(1.02) ; 
	E->setIntervalle (0; 20) ; 
	int time (0) ; 
	do {
		E->refreshPotential () ; 
		I->refreshPotential () ; 
		++time 
	}while (not E->Is_Spike () )
	I->refreshPotential () ; 
	I->refreshPotential () ; 
	EXPECTED_NEAR (I->ReceiveSpike (), 0.1, 1.02) ; 
}

int main () {
	return RUN_ALL_TESTS () ; 
	return 0 ; 
	}
