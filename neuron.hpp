#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <fstream>
#include <random> 

using namespace std ; 

class Neuron {
	private : 
	double Potential; 
	vector<double> spikes ;
	double tau ; 
	double I ; 
	double debutI ; 
	double finI ; 
	int time ;
	double step  ; // integration time step 
	double MembraneResistance ; 
	double firingThreshold ; 
	vector<vector<double> > Record ;
	double j ; //le potentiel envoyer par un spike 
	vector<Neuron*> connected ; 
	unsigned int BufferCurseur ; 
	array<double,4> Buffer ; 
	bool excitatory ; 
	
	public : 
	Neuron (bool e) ;  
	~Neuron () {};  
	double getPotential () const ;
	double getI () const ;
	vector<double> getSpikes () const; 
	int getTime () ;  
	double getFiringThreshold () const ; 
	double getTau () const ; 
	double getMembraneRestistance () const ; 
	void setI (double Z ) ; 
	void setIntervalle (double debut, double fin) ;
	void setTime (double t) ;
	void setPotential (double t ) ; 
	void addConnection (Neuron* n ) ;
	void RefreshPotential (double h) ;
	bool Is_spike () ;  
	vector<vector<double> > getRecord () const ; 
	void PrintRecord () const ; 
	void PrintSpike () const ;
	bool isRefractory () ; 
	double SendSpikes () ; 
	double ReceiveSpike () ;  
	bool IsExcitatory () ;
	int getCe () const ; 
	int getCi () const ; 
	double getNumberSpike () const ;  
	void updateRecord () ; 
	Neuron* getConnected (int i ) ; 
	};

#endif 

