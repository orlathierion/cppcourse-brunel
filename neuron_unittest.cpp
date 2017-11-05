#include <iostream> 
#include "neuron.hpp" 
#include "gtest/gtest.h"
#include "experiments.hpp" 

using namespace std ; 

/*TEST (NeuronTest, PotentialZEROTest) {
	Experiment E ; 
	Experiment I ; 
	E.setI(0) ; 
	I.setI (0) ; 
	E.setIntervalle (0, 20) ; 
	I.setIntervalle (0, 20) ; 
	//for (unsigned int j (0) ; j<10 ; ++j) {
		int j (1) ; 
		E.setTime (j) ; 
		I.setTime (j) ;
		E.RefreshPotential (j) ; 
		I.RefreshPotential (j) ; 
		cout << " neuron unittest 1 21 " << endl ; 
	//}
	EXPECT_EQ(E.getNumberSpike(), 0) ;
	EXPECT_EQ(I.getNumberSpike(), 0) ; 
	EXPECT_EQ(E.getPotential(), 0.0 ) ; 
	EXPECT_EQ(I.getPotential(), 0.0 ) ;
}*/

TEST(NeuronTest, PotentialONETest) {
	Neuron E (true) ;
	Neuron I (false) ; 
	E.setI(1.00) ; 
	I.setI (1.00) ; 
	E.setIntervalle (0, 20) ; 
	I.setIntervalle (0, 20) ; 
	for (unsigned int j (0) ; j<20 ; ++j) {
		E.setTime (j) ; 
		I.setTime (j) ;
		E.RefreshPotential (j) ; 
		I.RefreshPotential (j) ; 
	}
	EXPECT_EQ(E.getNumberSpike(), 0) ;
	EXPECT_EQ(I.getNumberSpike(), 0) ; 
	EXPECT_DOUBLE_EQ(E.getPotential(), 20.0 ) ; 
	EXPECT_DOUBLE_EQ(I.getPotential(), 20.0 ) ;
}

TEST(NeuronTest, PotentialTWOTest) {
	Experiment E ; 
	Experiment I ;  
	E.setI(1.01) ; 
	I.setI (1.01) ; 
	E.setIntervalle (0,20) ; 
	I.setIntervalle (0,20) ; 
	//for (unsigned int j (0) ; j<10 ; ++j) {
		E.setTime (1) ; 
		I.setTime (1) ;
		E.RefreshPotential (1) ; 
		I.RefreshPotential (1) ; 
	//}
	EXPECT_GT(E.getNumberSpike(), 0) ;
	EXPECT_GT(I.getNumberSpike(), 0) ; 
}

TEST(NeuronTest, SpikeBufferTest) {
	Neuron E (true);
	Neuron I (false); 
	E.addConnection(&I) ; 
	I.addConnection(&E) ; 
	E.setI(1.2) ; 
	E.setIntervalle (0, 20) ; 
	int time (0) ; 
	do {
		E.RefreshPotential (time) ; 
		I.RefreshPotential (time) ; 
		++time ; } while ((E.Is_spike() ) or  not (time < 20 )) ;
		if (E.Is_spike ()) {
			cout << "neuron unittest 75  spike buffer" << endl ;}
 	I.RefreshPotential (time) ; 
	I.RefreshPotential (time) ; 
	EXPECT_NEAR (I.ReceiveSpike (), 0.1, 1.02) ; 
}

int main (int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv); 
	return RUN_ALL_TESTS () ; 
}

