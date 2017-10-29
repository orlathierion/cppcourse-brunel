#ifndef NEURON
#define NEURON

#include <iostream>
#include <cmath>
#include <vector>
#include <array>

class Excitatory ; 
class Inhibitory ;

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
	int Ce ; 
	int Ci ; 
	
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
	void addConnection (Excitatory* n ) ;
	void addConnection (Inhibitory* n ) ;
	void RefreshPotential (double h) ;
	bool Is_spike () ;  
	vector<vector<double> > getRecord () const ; 
	void PrintRecord () const ; 
	void PrintSpike () const ;
	bool isRefractory () ; 
	double SendSpikes () ; 
	double ReceiveSpike () ;  
	virtual bool IsExcitatory () ;
	int getCe () const ; 
	int getCi () const ; 
	void createConnexion () ;
	int getNumberSpike () const ;  
	};

#endif 
