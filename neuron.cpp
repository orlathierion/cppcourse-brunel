#include <iostream>
#include <cmath>
#include "neuron.hpp" 


using namespace std ; 

Neuron::Neuron () : 
Ci (1.0) ,
Ce (1.0) ,
Potential (20.0) ,
tau (20.0) , 
I (0) ,
time (0.0),
R(0.05) ,
G(30)  { }

int Neuron::getCe () const {
	return Ce ; 
	 }
	
int Neuron::getCi () const {
	return Ci ; 
	}
	
double Neuron::getPotential () const {
	return Potential ; 
	}	
	
double Neuron::getI () const {
	if (debutI <= time and finI >= time ) {
		return I ; }
	else {return 0;	} 
	}
	
void Neuron::setI (double Z) {
	I = Z ; 
	}
	
vector<double> Neuron::getSpikes () const {
	return spikes ; 
	}
	
void Neuron::setIntervalle (double debut , double fin) {
	debutI = debut ; 
	finI = fin ; 
	}
	
void Neuron::setTime (double t ) {
	time = t ; 
	}

void Neuron::RefreshPotential (double h ) {
	if (Is_spike() ) {
		Potential = 20 ; } 
	else {
		Potential = exp ( h / tau )*getPotential () + getI()*(R)*(1-exp(-h/tau)) ; }
	if (getPotential () < 20 ) {
		Potential = 20 ; }
	vector<double> now ;
	now.push_back (time);
	now.push_back (Potential) ;
	Record.push_back (now) ;};

	
bool Neuron::Is_spike (){
	if (Potential >= G ) {
		spikes.push_back(time) ; 
		return true ;
		}
	else {return false ; }
	}
	
vector<vector<double> > Neuron::getRecord () const {
	return Record ; 
	} 
	
void Neuron::PrintRecord () const {
	for (int i(0); i<getRecord().size (); ++ i ) {
		cout << getRecord()[i] [0]<< "  -> " << getRecord()[i][1] << endl ; }
	}
