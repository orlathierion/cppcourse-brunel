#include "experiment.hpp" 

using namespace std ; 

Experiment::Experiment () : 
neuron (true) 
{} 

Experiment::~Experiment () {}
	 
double Experiment::getPotential () const {
	return neuron.getPotential() ; 
	}

double Experiment::getI () const {
	return neuron.getI () ; 
	}
	
vector<double> Experiment::getSpikes () const {
		return neuron.getSpikes () ; }
		
int Experiment::getTime () {
	return neuron.getTime () ; 
		} 
		
double Experiment::getTau () const {
	return neuron.getTau () ; 
	}
	
double Experiment::getMembraneRestistance () const {
	return neuron.getMembraneRestistance () ; 
	}
		  
void Experiment::setI (double Z ) {
	neuron.setI(Z) ; 
	}
	
void Experiment::setIntervalle (double debut, double fin) {
	neuron.setIntervalle (debut, fin) ; 
	}
	
void Experiment::setTime (double t) {
	neuron.setTime (t) ; }
	
void Experiment::setPotential (double t ) {
	setPotential(t) ; 
	}
	
void Experiment::addConnection (Neuron* n ) {
	neuron.addConnection (n) ; 
	}
	
void Experiment::RefreshPotential (double h) {
	if (isRefractory() ) {setPotential(10.0 );  }
	if (not isRefractory ()) {
		if (Is_spike() ) {
			setPotential(10 ); } 
		else {
			setPotential (exp ( -h / getTau() )*getPotential () + getI()*(getMembraneRestistance())*(1-exp(-h/getTau())) ); }
		setPotential(getPotential () + ReceiveSpike ()) ; }
	updateRecord () ; 
	setTime (getTime () + 1 ) ; }

	
bool Experiment::Is_spike () {
		return neuron.Is_spike () ; 
		}  
		
vector<vector<double> > Experiment::getRecord () const {
	return neuron.getRecord () ;
	}
	
void Experiment::PrintRecord () const {
	neuron.PrintRecord () ;
	} 
	
void Experiment::PrintSpike () const {
	neuron.PrintSpike () ; 
	}
	
bool Experiment::isRefractory () {
	return neuron.isRefractory () ; 
	} 
	
double Experiment::SendSpikes () {
	return neuron.SendSpikes () ;
	} 
double Experiment::ReceiveSpike () {
	return neuron.ReceiveSpike () ; 
	}
	
void Experiment::updateRecord () {
	neuron.updateRecord () ; 
	}
	
int Experiment::getNumberSpike () const {
	return neuron.getNumberSpike () ; 
	}
