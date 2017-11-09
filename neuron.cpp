#include "neuron.hpp" 

using namespace std ; 

const int bufferDelay (2) ;



Neuron::Neuron (bool e)  : 
Potential (10.0) ,
tau (20.0) , 
I (1.0) ,
time (0.0),
step (20) ,
MembraneResistance(20.0) ,
firingThreshold(20),
j (0.1 ), 
BufferCurseur (2),  // entraine un delai de 2 	 
excitatory (e)
{	spikes.push_back (-2) ; 
	 for (unsigned int i (0) ; i<Buffer.size() ; ++i ) {
		 Buffer [i] = 0 ; 
	} 
	/*vector<vector<double>> v (1); 
	Record = v ; */
	if (not excitatory) {
		j=-j ; 
		}
	}
		 
Neuron::~Neuron () {}

	
double Neuron::getPotential (unsigned int h ) const {
	/*double p ; 
	if (getRecord().size() > h ) {
		p = getRecord()[h][1] ; } 
	else {p = 0 ; }*/
	return Potential ;
	}	
	

	
double Neuron::getI () const {
	if (debutI <= time and finI >= time ) {
		return I ; }
	else {return 0;	} 
	}
	

	
int Neuron::getTime () {
	return time ; }
	
double Neuron::getTau () const{
	return tau ; 
	}

double Neuron::getMembraneRestistance () const {
	return MembraneResistance ; 
	}
	

	
void Neuron::setI (double Z) {
	I = Z ; 
	}
	

	
vector<double> Neuron::getSpikes () const {
	return spikes ; 
	}
	

	
double Neuron::getFiringThreshold () const	{
	return firingThreshold ; 
	}
	
/**
 * \fn (setIntervalle (double beginning, doube end ) 
 * this function allows us to set the intervalle during which the external imput occured 
 * \param <beginning> {the time at wich the imput begin}
 * \param <end> {the time at wich the imput stops }
 **/
	
void Neuron::setIntervalle (double beginning , double end) {
	debutI = beginning ; 
	finI = end ; 
	}
	

	
void Neuron::setTime (double t ) {
	time = t ; 
	}
	
void Neuron::setPotential (double t) {
	Potential = t ; 
	} 
	

	
void Neuron::addConnection (Neuron* n) {
	connected.push_back (n) ; 
	} 
	


void Neuron::RefreshPotential (double h ) {
	if (isRefractory() ) {Potential = 10.0 ;  }
	if (not isRefractory ()) {
		if (Is_spike(h) ) {
			Potential = 0 ; } 
		else {	
			static random_device rd ; 
			static mt19937 gen(rd()) ;
			static poisson_distribution<> d(2) ; 
			Potential = exp ( -h * step / tau )*getPotential (h-1) + getI()*(MembraneResistance)*(1-exp(-h/tau)) ;
		Potential += ReceiveSpike (h) ;
		Potential += d(gen) ;  }}
	updateRecord () ; 
	time += 1 ;   }
	
/**
 * \fn (isExcitatory())
 * this fonction will return true if the neuron is excitatory 
 **/
 
 bool Neuron::IsExcitatory(){
	 return excitatory ; 
	 }


	
bool Neuron::Is_spike (unsigned int h ){
	double d (getPotential (h)) ; 
	double j (getFiringThreshold ()) ; 
	if ( d >= j) {
		spikes.push_back(time) ; 
		return true ;
		}
	else {return false ; }
	}
	
	
	
vector<vector<double> > Neuron::getRecord () const {
	return Record ; 
	} 
	

	
void Neuron::PrintRecord () const {
	ofstream o ("results.txt", ios::out) ; 
	vector<vector<double> > v ; 
	v = getRecord () ; 
	for (unsigned int i(1); i<getRecord().size () ; ++ i ) {
		o << v[i][0] +1 ;
		o << "  -> " ;
		o << v[i][1]; 
		o << endl ; }
	}



void Neuron::PrintSpike () const {
	ofstream o ("results.txt", ios::out) ; 
	if (o.fail ()) {
		cout << "the result file couldn't be open " << endl ; }
	if (spikes.size() > 1) {
		o << "we observe "<< spikes.size () - 1 << " spikes at : " << endl ; 
		for (unsigned int i (1); i<spikes.size() ; ++i) {
			o << spikes [i]- 2 << " ms " << endl; 
			}}
	else {
		o << "there was no spike." << endl ; 
	}
	o.close () ; }
	

	
bool Neuron::isRefractory () { 
	double h ; 
	if (spikes.size () > 1) {
		h = spikes.back() ;
	if (time-h < 2.0) {
		return true ;} 
	else { 
return false ; }}
	else {
		return false ; }}



double Neuron::SendSpikes (unsigned int h) {
	int r ; 
	if (Is_spike (h )){
	r = j ;}
	else {
		r = 0 ; } 
	return r ;
	  }
		
	
double Neuron::ReceiveSpike (unsigned int h) {
	++BufferCurseur ;
	double SumSpikes (0.0); 
	if (connected.size () > 1 ) {
	for (unsigned int i (1) ; i<connected.size () -1 ; ++i ) { 
		if (Is_spike(h) ) {
			SumSpikes += j ; 
			}
		if (BufferCurseur + bufferDelay < Buffer.size() ) {
			Buffer [BufferCurseur+bufferDelay]= SumSpikes ; }
		if (BufferCurseur + bufferDelay >= Buffer.size ()) {
			Buffer [BufferCurseur + bufferDelay - Buffer.size ()] = SumSpikes ; }
	if (BufferCurseur >= Buffer.size () ) {
		BufferCurseur = 0 ; 
		}}}
	if (connected.size () <= 1) {
		Buffer[BufferCurseur] = 0 ; 
		}
	return Buffer[BufferCurseur] ; 
	 }


double Neuron::getNumberSpike () const {
	return spikes.size () ; 
}


void Neuron::updateRecord () {
	vector <double> n ({time, Potential}) ; 
	Record.push_back (n) ;   
	}

Neuron* Neuron::getConnected (int i) { 
	return connected[i] ; }
