#ifndef NEURON
#define NEURON

#include <iostream>
#include <cmath>
#include <vector>
#include <array>

using namespace std ; 


class Neuron {
	private : 
	double Potential; 
	vector<double> spikes ;
	double tau ; 
	double I ; /**
				*I correspond a l'intensité de l'input, on peut choisir le dédut et la fin 
				**/
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
	
	public : 
	Neuron () ;  
	~Neuron () {};  
	double getPotential () const ;
	double getI () const ;
	vector<double> getSpikes () const; 
	int getTime () ;  
	double getFiringThreshold () const ; 
	void setI (double Z ) ; 
	void setIntervalle (double debut, double fin) ;
	void setTime (double t) ;
	void addConnection (Neuron* n ) ; 
	void RefreshPotential (double h) ;
	bool Is_spike () ;  
	vector<vector<double> > getRecord () const ; 
	void PrintRecord () const ; 
	void PrintSpike () const ;
	bool isRefractory () ; 
	double SendSpikes () ; 
	double ReceiveSpike () ;  
	virtual bool IsExcitatory () ;
	};

#endif 
