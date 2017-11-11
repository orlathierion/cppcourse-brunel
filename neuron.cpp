#include "neuron.hpp" 

using namespace std ; 

const int bufferDelay (2) ;



Neuron::Neuron (bool e, double v, double g, int c)  : 
Potential (10.0) ,
tau (20.0) , 
I (1.0) ,
time (0.0),
step (20) ,
MembraneResistance(20.0) ,
firingThreshold(20),
j (0.1 ), 
BufferCurseur (2),  
excitatory (e),
Vext (v),
Ce (c)
{	spikes.push_back (-2) ; 
	 for (unsigned int i (0) ; i<Buffer.size() ; ++i ) {
		 Buffer [i] = 0 ; } 
	if (not excitatory) {
		j=-g*j ; }}
		 
Neuron::~Neuron () {}

	
double Neuron::getPotential (unsigned int h ) const {
	return Potential ;
	}	
	
double Neuron::getI () const {
	if (debutI <= time and finI >= time ) {
		return I ; }
	else {return 0;	} }
	
int Neuron::getTime () {
	return time ; }
	
double Neuron::getTau () const{
	return tau ; }

double Neuron::getMembraneRestistance () const {
	return MembraneResistance ; }
	
void Neuron::setI (double Z) {
	I = Z ; }
	
vector<double> Neuron::getSpikes () const {
	return spikes ; }
	
double Neuron::getFiringThreshold () const	{
	return firingThreshold ; }
	
void Neuron::setIntervalle (double beginning , double end) {
	debutI = beginning ; 
	finI = end ; }
	
void Neuron::setTime (double t ) {
	time = t ; }
	
void Neuron::setPotential (double t) {
	Potential = t ; 	} 
	
void Neuron::addConnection (Neuron* n) {
	connected.push_back (n) ; } 
	
void Neuron::RefreshPotential (double h ) {
	if (isRefractory() ) {Potential = 10.0 ;  }
	if (not isRefractory ()) {
		if (Is_spike(h) ) {
			Potential = 0 ; 
			} 
		else {	
			static random_device rd ; 
			static mt19937 gen(rd()) ;
			static poisson_distribution<> d(Ce*Vext) ; 
			Potential = exp ( -h * step / tau )*getPotential (h-1) + getI()*(MembraneResistance)*(1-exp(-h/tau)) + ReceiveSpike (h) + d(gen) ;  }}
	updateRecord () ; 
	setTime (h+1) ;   }
	
 bool Neuron::IsExcitatory(){
	 return excitatory ;  }

bool Neuron::Is_spike (unsigned int h ){
	if (getPotential (h) >= getFiringThreshold ()) {
		spikes.push_back(time) ; 
		return true ;}
	else {return false ; }}
		
vector<vector<double> > Neuron::getRecord () const {
	return Record ; } 
	
int Neuron::getASpike (unsigned int i) const {
	return spikes[i] ; 
	}
	
bool Neuron::isRefractory () {  
	if (spikes.size () > 1) {
	if (time- spikes.back() < 2.0) {
		return true ;} 
	else { 
return false ; }}
	else {
		return false ; }}

double Neuron::SendSpikes (unsigned int h) {
	if (Is_spike (h )){
	return j ;}
	else {
		return 0 ; }  }
	
double Neuron::ReceiveSpike (unsigned int h) {
	++BufferCurseur ;
	double SumSpikes (0.0); 
	BufferCurseur = BufferCurseur % Buffer.size() ; 
	if (connected.size () >= 1 ) {
	for (unsigned int i (1) ; i<getNumberConnection() -1 ; ++i ) { 
		if (Is_spike(h) ) {
			SumSpikes += j ; }
	Buffer [(BufferCurseur+ bufferDelay ) % Buffer.size()] = SumSpikes ; }}
	if (connected.size () < 1) {
		Buffer[BufferCurseur] = 0 ; }
	return Buffer[BufferCurseur] ;  }


double Neuron::getNumberSpike () const {
	return spikes.size () ; 
}


void Neuron::updateRecord () {
	Record.push_back ({time, Potential}) ;   
	}

Neuron* Neuron::getConnected (int i) { 
	return connected[i] ; }
	
int Neuron::getNumberConnection () const {
return connected.size () ; }
