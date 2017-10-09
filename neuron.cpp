#include <iostream>
#include <cmath>
#include "neuron.hpp" 


using namespace std ; 

Neuron::Neuron () : 
Ci (1.0) ,
Ce (1.0) ,
Potential (-70.0) ,
tau (20.0) , 
I (1.0) ,
time (0.0),
MembraneResistance(20.0) ,
firingThreshold(20)  {
	spikes.push_back (-2) ; }

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
	if (isRefractory() ) {Potential = 10.0 ;  }
	if (not isRefractory ()) {
		if (Is_spike() ) {
			Potential = 10 ; } 
		else {
			Potential = exp ( -h / tau )*getPotential () + getI()*(MembraneResistance)*(1-exp(-h/tau)) ; }}
	vector<double> now ;
	now.push_back (time-1);
	now.push_back (Potential) ;
	Record.push_back (now) ;}

	
bool Neuron::Is_spike (){
	if (Potential >= firingThreshold ) {
		spikes.push_back(time) ; 
		return true ;
		}
	else {return false ; }
	}
	
vector<vector<double> > Neuron::getRecord () const {
	return Record ; 
	} 
	
void Neuron::PrintRecord () const {
	for (unsigned int i(0); i<getRecord().size (); ++ i ) {
		cout << getRecord()[i] [0]<< "  -> " << getRecord()[i][1] << endl ; }
	}
	
bool Neuron::isRefractory () { 
	double h ; 
	h = spikes.back() ;
	if (time-h < 2.0) {
		return true ;} 
	else { 
		return false ; } }
