#include "experiment.hpp" 

using namespace std ; 

Experiment::Experiment () :
n(10000, 2500) 
{}

Experiment::~Experiment() {} 

void Experiment::refreshNetwork (int h) {
	n.refreshNetwork (h) ; 
	}

void Experiment::produceFigure () {
	n.produceFigure (); 
}
