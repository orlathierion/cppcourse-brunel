#include <iostream>
#include <cmath>
#include <vector>

using namespace std ; 

#ifndef NEURON
#define NEURON

class Neuron {
	private : 
	int Ci ; 
	int Ce ; 
	double Potential; 
	vector<double> spikes ;
	double tau ; 
	double I ; 
	double debutI ; 
	double finI ; 
	double time ;
	double R ; 
	double G ; 
	vector<vector<double> > Record ;
	
	public : 
	Neuron () ;  
	~Neuron () {}; 
	int getCi () const ; 
	int getCe () const ; 
	double getPotential () const ;
	double getI () const ;
	vector<double> getSpikes () const;   
	void setI (double Z ) ; 
	void setIntervalle (double debut, double fin) ;
	void setTime (double t) ;
	void RefreshPotential (double h) ;
	bool Is_spike () ;  
	vector<vector<double> > getRecord () const ; 
	void PrintRecord () const ; 
	};

#endif 
