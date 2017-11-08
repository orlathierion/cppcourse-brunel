#include <iostream> 
#include "neuron.hpp" 
#include "gtest/gtest.h"

using namespace std ; 

/*
 * we stop using those tests since there is an random external iéput that enter in
 * the cqlcution of the potential thqt those test qre bqsed on .
 * /
 */
 TEST (NeuronTest, PotentialZEROTest) {
	Neuron E (true); 
	Neuron I (false); 
	E.setI(0) ; 
	I.setI (0) ; 
	E.setIntervalle (0, 20) ; 
	I.setIntervalle (0, 20) ; 
	for (unsigned int j (0) ; j<50 ; ++j) {
		E.setTime (1) ; 
		I.setTime (1) ;
		E.RefreshPotential (1) ; 
		I.RefreshPotential (1) ; 
	}
	EXPECT_EQ(E.getNumberSpike(), 1) ;
	EXPECT_EQ(I.getNumberSpike(), 1) ; 
	EXPECT_EQ(E.getPotential(), 0.0 ) ; 
	EXPECT_EQ(I.getPotential(), 0.0 ) ;
}

TEST(NeuronTest, PotentialONETest) {
	Neuron E (true) ;
	Neuron I (false) ; 
	E.setI(1.00) ; 
	I.setI (1.00) ; 
	E.setIntervalle (0, 20) ; 
	I.setIntervalle (0, 20) ; 
	for (unsigned int j (0) ; j<50 ; ++j) {
		E.setTime (j) ; 
		I.setTime (j) ;
		E.RefreshPotential (j) ; 
		I.RefreshPotential (j) ; 
	}
	EXPECT_EQ(E.getNumberSpike(), 1) ;
	EXPECT_EQ(I.getNumberSpike(), 1) ; 
	EXPECT_DOUBLE_EQ(E.getPotential(), 20.0 ) ; 
	EXPECT_DOUBLE_EQ(I.getPotential(), 20.0 ) ;
}

TEST(NeuronTest, PotentialTWOTest) {
	Neuron E (true); 
	Neuron I (false);  
	E.setI(1.01) ; 
	I.setI (1.01) ; 
	E.setIntervalle (0,20) ; 
	I.setIntervalle (0,20) ; 
	for (unsigned int j (0) ; j<50 ; ++j) {
		E.setTime (j) ; 
		I.setTime (j) ;
		E.RefreshPotential (j) ; 
		I.RefreshPotential (j) ; 
	}
	cout << " for neuron e " << E.getNumberSpike () << endl ; 
	EXPECT_GT(E.getNumberSpike(), 1) ;
	EXPECT_GT(I.getNumberSpike(), 1) ; 
}

TEST(NeuronTest, SpikeBufferTest) {
	Neuron E (true);
	Neuron I (false); 
	E.addConnection(&I) ; 
	I.addConnection(&E) ; 
	E.setI(4.5) ; 
	E.setIntervalle (0, 20) ; 
	int time (0) ; 
	do {
		E.RefreshPotential (time) ; 
		I.RefreshPotential (time) ; 
		++time ; } while (not(E.Is_spike() ) or (time < 20 )) ;
	double q ;
	q = E.SendSpikes () ;
 	I.RefreshPotential (time) ; 
	I.RefreshPotential (time) ; 
	EXPECT_NEAR (I.ReceiveSpike (), 0.1, q) ; 
}

int main (int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv); 
	return RUN_ALL_TESTS () ; 
}

