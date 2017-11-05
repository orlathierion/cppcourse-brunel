#ifndef EXPERIMENT
#define EXPERIMENT

#include <iostream>
#include "neuron.hpp" 
#include <random> 
#include <vector>
 
using namespace std ; 

class Experiment {
	private : 
	Neuron neuron ; 

	public : 
	Experiment () ;  
	~Experiment  (); 
	int getCi () const ; 
	int getCe () const ; 
	double getPotential () const ;
	double getI () const ;
	vector<double> getSpikes () const; 
	int getTime () ; 
	double getTau () const ; ;  
	double getMembraneRestistance () const ;  
	void setI (double Z ) ; 
	void setIntervalle (double debut, double fin) ;
	void setTime (double t) ;
	void setPotential (double t) ; 
	void addConnection (Neuron* n ) ; 
	void RefreshPotential (double h) ;
	bool Is_spike () ;  
	vector<vector<double> > getRecord () const ; 
	void PrintRecord () const ; 
	void PrintSpike () const ;
	bool isRefractory () ; 
	double SendSpikes () ; 
	double ReceiveSpike () ; 
	void updateRecord () ;  
	int getNumberSpike () const ; 
};



#endif
