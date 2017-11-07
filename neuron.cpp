#include "neuron.hpp" 

using namespace std ; 

const int bufferDelay (2) ;

/**
 * \class Neuron 
 * The class Neuron represent a neuron caracterise by its potential, its resistance, 
 * the connexion it makes with other neurons. 
 **/

Neuron::Neuron (bool e)  : 
Potential (0.0) ,
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
	vector<vector<double>> v (1); 
	Record = v ; 
	}
		 
/** 
 *\fn (getPotential () ) 
 * getPotential return the curent membrane potential
 **/
	
double Neuron::getPotential () const {
	return Potential ; 
	}	
	
/**
 * \fn (getI ()) 
 * getI give us the curent intensity of the external input 
 **/
	
double Neuron::getI () const {
	if (debutI <= time and finI >= time ) {
		return I ; }
	else {return 0;	} 
	}
	
/**
 * \fn (getTime () ) 
 * this function give us the time on the cells clock. 
 **/
	
int Neuron::getTime () {
	return time ; }
	
double Neuron::getTau () const{
	return tau ; 
	}

double Neuron::getMembraneRestistance () const {
	return MembraneResistance ; 
	}
	
/**
 * \fn (setI (double Z) ) 
 * this function allow us to change the input coming to the neuron
 * \param <Z> {intensity of the input}
 **/
	
void Neuron::setI (double Z) {
	I = Z ; 
	}
	
/**
 * \fn (getSpikes()) 
 * this function returns a table with all the time at wich a spike occured 
 **/
	
vector<double> Neuron::getSpikes () const {
	return spikes ; 
	}
	
/**
 * \fn (getFiringThreshold () ) 
 * this function give us access to the firing threshold 
 **/
	
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
	
/** 
 * \fn (setTime(double t ) ) 
 * it allows us to change the inner clock of the cell 
 * \param <t> {new time}
 **/
	
void Neuron::setTime (double t ) {
	time = t ; 
	}
	
void Neuron::setPotential (double t) {
	Potential = t ; 
	} 
	
/**
 * \fn (addConnection (Excitatory* n ) ) 
 * addConnection create a new connection with a neuron 
 * \param <n> {it is a pointer on the neuron we want to connect to }
 **/
	
void Neuron::addConnection (Neuron* n) {
	connected.push_back (n) ; 
	} 
	
/**
 * \fn (RefreshPotential (double h ) ) 
 *  RefreshPotential refresh the membrane potential at time h. 
 * \param <h> {time in the local clock}
 **/

void Neuron::RefreshPotential (double h ) {
	if (isRefractory() ) {Potential = 10.0 ;  }
	if (not isRefractory ()) {
		if (Is_spike() ) {
			Potential = 0 ; } 
		else {	
			random_device rd ; 
			mt19937 gen(rd()) ;
			poisson_distribution<> d(2) ; 
			Potential = exp ( -h * step / tau )*getPotential () + getI()*(MembraneResistance)*(1-exp(-h/tau)) ;
		Potential += ReceiveSpike () ;
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

/**
 * \fn (Is_Spike())
 *  Is_Spike permet de savoir si un spike est crée ou non 
 * \return {it will retrun true if a spike is created}
 **/
	
bool Neuron::Is_spike (){
	if (Potential >= firingThreshold ) {
		spikes.push_back(time) ; 
		return true ;
		}
	else {return false ; }
	}
	
	/** 
	 * \fn (getRecord())
	 * this fonction will give all the membrane potential at each steps
	 * \return {it will return a table with the time a the corresponding potential membrane}
	 **/ 
	
vector<vector<double> > Neuron::getRecord () const {
	return Record ; 
	} 
	
/**
 * \fn (PrintRecord ()) 
 * this fonction print all the potential for each time steps on the results document
 **/
	
void Neuron::PrintRecord () const {
	ofstream o ("results.txt") ;
	//if (o.fail () ) {cout << " caca neuron print spike " << endl ; }
	//if (not o.fail ()) { cout << " cq s4ouvre "<< endl ; }
	vector<vector<double> > v ; 
	v = getRecord () ; 
	for (unsigned int i(1); i<getRecord().size () ; ++ i ) {
		cout << v[i][0] +1 ;
		cout << "  -> " ;
		cout << v[i][1]; 
		cout << endl ; }
	}

/**
 * \fn (PrintSpike ()) 
 * this will fonction will print all the time at wich spikes occured on the results document
 **/

void Neuron::PrintSpike () const {
	//cout << " print spikes neuron cpp 206 " << endl ; 
	ofstream o ("results.txt", ios::out) ;
	//if (o.fail ()) {cout << "o.fail neuron cpp 207 " << endl ; }
	//if (not o.fail ()) {cout << "o est ouvert neuron cpp 210 " << endl ; }
	if (spikes.size() > 1) {
		//cout << " if de print spikes neuron cpp 209 " << endl ; 
		cout << "we observe "<< spikes.size () - 1 << " spikes at : " << endl ; 
		for (unsigned int i (1); i<spikes.size() ; ++i) {
			cout << spikes [i]- 2 << " ms " << endl; 
			}}
	else {
		//cout << "else de print spike neuron cpp 215 " << endl ; 
		cout << "there was no spike." << endl ; 
	}
	o.close () ; }
	
/**
 * \fn (isRefractory ())
 * this fonction allows us to know if the neuron is in a refractory period 
 * \return {it will be true if the membrane is in its refractory periods }
 **/
	
bool Neuron::isRefractory () { 
	double h ; 
	h = spikes.back() ;
	if (time-h < 2.0) {
		return true ;} 
	else { 
return false ; } }

/**
 * \fn (SendSpikes ()) 
 * it allow us to know if the neuron is doing a spike at the curent time 
 * \return {it will retruns the value of the sended spikes}
 **/

double Neuron::SendSpikes () {
	 int r ; 
	if (excitatory) { 
	if (Is_spike ()){
	r = j ;}
	else {
		r = 0 ; }} 
		if (Is_spike ()){
	r = -j ;}
	else {
		r = 0  ; }
	return r ; }
		
/**
 * \fn (ReceiveSpike () ) 
 * this fonction will collect all the spikes that the connected neuron have sended 
 **/ 
	
double Neuron::ReceiveSpike () {
	++BufferCurseur ;
	double SumSpikes (0.0); 
	for (unsigned int i (1) ; i<spikes.size (); ++i ) { 
		SumSpikes += getConnected(i)->SendSpikes() ; 
		if (BufferCurseur + bufferDelay < Buffer.size() ) {
			Buffer [BufferCurseur+bufferDelay]= SumSpikes ; }
		if (BufferCurseur + bufferDelay >= Buffer.size ()) {
			Buffer [BufferCurseur + bufferDelay - Buffer.size ()] = SumSpikes ; }
		}
	if (BufferCurseur >= Buffer.size () ) {
		BufferCurseur = 0 ; 
		}
	return Buffer[BufferCurseur] ; 
	 }

/**
 * \fn (getNumberSpikes ()) 
 * it returns the number of spikes that has occured 
 **/

double Neuron::getNumberSpike () const {
	return spikes.size () ; 
}

void Neuron::updateRecord () {
	Record.push_back({time-1, getPotential()}) ;
	}

Neuron* Neuron::getConnected (int i) { 
	return connected[i] ; 
	}
