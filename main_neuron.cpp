
#include <iostream>
#include <cmath>
#include "neuron.hpp" 
#include <string>
#include <fstream>

using namespace std ; 

bool TestConnectionDeuxNeurones () ; 
void testMembranePot1 () ; 
void testMembranePot2 () ; 


int main () {ofstream o ("results.txt") ; 
	if (TestConnectionDeuxNeurones () ) {o << "test1 ok " << endl; 
		} 
	else o << " test 1 fail" << endl ;  
	testMembranePot1 () ;
	testMembranePot2 () ; 
return 0 ; }

bool TestConnectionDeuxNeurones () {
	int time (0) ; 
	double duration (20);
	Neuron n ;
	Neuron m ; 
	double Z (1.5) ; 
	n.setI (Z) ; 
	Z = 1 ;  
	double r (20); 
	n.setIntervalle (Z, r) ;  
	n.addConnection (&m) ; 
	m.addConnection (&n) ; 
	while (time < duration ) {
		++time ;
		n.RefreshPotential (time) ; 
		m.RefreshPotential (time) ;  }
	/*cout << "For the first neuron : " << endl ; 
	n.PrintRecord () ;
	n.PrintSpike () ; 
	cout << "For the second neuron : " << endl ; 
	m.PrintRecord () ; 
	m.PrintSpike () ;*/
	vector<vector<double> > Rec (m.getRecord ()) ; 
	for (unsigned int i (0) ; i<Rec.size() ; ++i ) {
		if (Rec [i] [1] !=0 ) return true ; 
		}
	return false ;
	}
	
void testMembranePot1 () {
	int time (0) ; 
	double duration (20);
	Neuron n ;
	Neuron m ; 
	double Z (1.00) ; 
	n.setI (Z) ; 
	Z = 1 ;  
	double r (20); 
	n.setIntervalle (Z, r) ;  
	n.addConnection (&m) ; 
	m.addConnection (&n) ; 
	while (time < duration ) {
		++time ;
		n.RefreshPotential (time) ; 
		m.RefreshPotential (time) ;  }
		double j (n.getRecord() [1] [0]) ; 
		double k ; 
		int countMistake (0) ;
		n.PrintRecord () ; 
	for (unsigned int i (1) ; i<n.getRecord().size() ; ++i ) {
		k = m.getRecord() [1] [i];
		if (j<k and k<n.getFiringThreshold () ) {cout << " OK " << endl ; }
		if (k<j ) {cout << "      Tow Low " << endl ;
			++ countMistake ;  }
		if (k>=n.getFiringThreshold () ) {cout << "      A spike " << endl ; 
			++countMistake ; }
		j = k ; 
		}
	if (countMistake == 0 ) {cout << "test 1 OK " << endl ; } 
	else {cout << " test 1 failed " << endl ; }
	}
	
void testMembranePot2 () {
	int time (0) ; 
	double duration (20);
	Neuron n ;
	Neuron m ; 
	double Z (1.01) ; 
	n.setI (Z) ; 
	Z = 1 ;  
	double r (20); 
	n.setIntervalle (Z, r) ;  
	n.addConnection (&m) ; 
	m.addConnection (&n) ; 
	while (time < duration ) {
		++time ;
		n.RefreshPotential (time) ; 
		m.RefreshPotential (time) ;  }
		//double j (n.getRecord() [0] [1]) ; 
		double k ; 
		int countMistake (0) ; 
		//n.PrintRecord	() ; 
	for (unsigned int i (0) ; i<n.getRecord().size() ; ++i ) {
		k = m.getRecord() [1] [i];
		if (/*j<k and*/ k<n.getFiringThreshold () ) {cout << " OK " << endl ; }
		//if (k<j ) {cout << "      Tow Low " << endl ;  }
		if (k>n.getFiringThreshold () ) {cout << "      A spike " << endl ; 
			++countMistake ; }
		//j = k ; 
		}
	if (countMistake > 1 ) {cout << "test 2 OK " << endl ; } 
	else {cout << " test 2 failed " << endl ; }
	}
	
