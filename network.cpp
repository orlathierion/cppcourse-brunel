#include "network.hpp"

 
Network::Netwo#include "network.hpp"

 
Network::Network (unsigned int e, unsigned int i, double weight, double ratio) :  
Ce (e),
Ci (i),
TimeStep (0) ,
Vthr(0.01)
{	
	for (unsigned int i (0); i<=Ce ; ++i ) { 
		Neuron* e(new Neuron(true, Vthr*ratio, weight, 1000)) ; 
		netE.push_back(e) ;}
	for ( unsigned int i (0); i<=Ci ; ++i ) {
		Neuron* y(new Neuron(false, Vthr*ratio, weight, 1000)) ; 
		netI.push_back(y) ; }
	createConnexion();  }
	
Network::~Network () {
	for (unsigned int i (0); i<Ce ; ++i ) { 
		delete netE[i] ; }
	for ( unsigned int i (0); i<Ci ; ++i ) {
		delete netI[i] ; }}
		
void Network::createConnexion () {
	static random_device rd ; 
	static mt19937 gen (rd()) ; 
	static uniform_int_distribution<> disE(0, Ce) ; 
	static uniform_int_distribution<> disI(0, Ci) ; 
	for (unsigned int i (0); i<Ce - 1; ++i ){ 
		for (unsigned int j (0); j<0.1*Ce - 1 ; ++j ) {
			netE[i]->addConnection(getExcitatory(disE(gen))); }
		for (unsigned int j (0); j<0.1*Ci - 1 ; ++j ) {
			netE[i]->addConnection(getInhibitory(disE(gen))); }}
	for (unsigned int i (0); i<Ci - 1 ; ++i ){
		for (unsigned int j (0); j<0.1*Ce - 1; ++j ) {
			netI[i]->addConnection(getExcitatory(disI(gen))); }
		for (unsigned int j (0); j<0.1*Ci- 1 ; ++j ) {
			netI[i]->addConnection(getInhibitory(disI(gen))); }}
	}
		
Neuron* Network::getInhibitory (unsigned int i ) {
	return netI[i] ; }

Neuron* Network::getExcitatory (unsigned int e) {
	return netE[e] ;}

void Network::refreshNetwork () {
	for (unsigned int j(0); j<Ci - 1; ++j) {
		getInhibitory(j)->RefreshPotential(TimeStep) ; }
	for (unsigned int i(0); i<Ce -1 ; ++i) {
		getExcitatory(i)->RefreshPotential(TimeStep) ;}		  
	++TimeStep; }

void Network::produceFigure () {
	double per ; 
	do {cout << "hwhat percentage of the network do you want to see ? " << endl ; 
	cin >> per  ; } while (not (per>0) and not(per<100)) ;  
	per = per/100 ; 
	ofstream o ("spikes.gdf", ios::out ) ;
	for (unsigned int i(1) ; i< Ce*per ; ++i) {
		if (getExcitatory(i)->getNumberSpike () > 1) {
			for (unsigned int j (0); j<getExcitatory(i)->getNumberSpike () ; ++j) {
				o << i << "n" << getExcitatory(i)->getASpike(j) << "s" << endl  ; }}
			cout << "printing  : " << (i/(Ce*per+Ci*per))*100 << " % " << endl ; }
	for (unsigned int i(1) ; i<Ci*per ; ++i) {
		if (getInhibitory(i)->getNumberSpike()> 1) {
			for (unsigned int j (0); j<getInhibitory(i)->getNumberSpike () ; ++j) {
				o << i+ Ce*per << "\n" << getInhibitory(i)->getASpike(j) << "\s" <<  endl  ; }} 
		cout << "printing  : " << ((i+Ce*per)/(Ce*per+Ci*per))*100 << " % " << endl ;}
		cout << "finishing ... " << endl ; 
o.close () ; }
rk (unsigned int e, unsigned int i, double weight, double ratio) :  
Ce (e),
Ci (i),
TimeStep (0) ,
Vthr(0.01)
{	
	for (unsigned int i (0); i<=Ce ; ++i ) { 
		Neuron* e(new Neuron(true, Vthr*ratio, weight, 1000)) ; 
		netE.push_back(e) ;}
	for ( unsigned int i (0); i<=Ci ; ++i ) {
		Neuron* y(new Neuron(false, Vthr*ratio, weight, 1000)) ; 
		netI.push_back(y) ; }
	createConnexion();  }
	
Network::~Network () {
	for (unsigned int i (0); i<Ce ; ++i ) { 
		delete netE[i] ; }
	for ( unsigned int i (0); i<Ci ; ++i ) {
		delete netI[i] ; }}
		
void Network::createConnexion () {
	static random_device rd ; 
	static mt19937 gen (rd()) ; 
	static uniform_int_distribution<> disE(0, Ce) ; 
	static uniform_int_distribution<> disI(0, Ci) ; 
	for (unsigned int i (0); i<Ce - 1; ++i ){ 
		for (unsigned int j (0); j<0.1*Ce - 1 ; ++j ) {
			netE[i]->addConnection(getExcitatory(disE(gen))); }
		for (unsigned int j (0); j<0.1*Ci - 1 ; ++j ) {
			netE[i]->addConnection(getInhibitory(disE(gen))); }}
	for (unsigned int i (0); i<Ci - 1 ; ++i ){
		for (unsigned int j (0); j<0.1*Ce - 1; ++j ) {
			netI[i]->addConnection(getExcitatory(disI(gen))); }
		for (unsigned int j (0); j<0.1*Ci- 1 ; ++j ) {
			netI[i]->addConnection(getInhibitory(disI(gen))); }}
	}
		
Neuron* Network::getInhibitory (unsigned int i ) {
	return netI[i] ; }

Neuron* Network::getExcitatory (unsigned int e) {
	return netE[e] ;}

void Network::refreshNetwork () {
	for (unsigned int j(0); j<Ci - 1; ++j) {
		getInhibitory(j)->RefreshPotential(TimeStep) ; }
	for (unsigned int i(0); i<Ce -1 ; ++i) {
		getExcitatory(i)->RefreshPotential(TimeStep) ;}		  
	++TimeStep; }

void Network::produceFigure () {
	ofstream o ("spikes.gdf", ios::out ) ;
	for (unsigned int i(1) ; i< Ce*0.1 ; ++i) {
		if (getExcitatory(i)->getNumberSpike () > 1) {
			for (unsigned int j (1); j<getExcitatory(i)->getNumberSpike () ; ++j) {
				o << getExcitatory(i)->getASpike(j) << " sec ; " << i << " neuron " << endl  ; }}
			cout << "printing  : " << (i/(Ce*0.1+Ci*0.1))*100 << " % " << endl ; }
	for (unsigned int i(1) ; i<Ci*0.1 ; ++i) {
		if (getInhibitory(i)->getNumberSpike()> 1) {
			for (unsigned int j (1); j<getInhibitory(i)->getNumberSpike () ; ++j) {
				o << getInhibitory(i)->getASpike(j) << " sec ; " << i << " neuron " << endl  ; }} 
		cout << "printing  : " << ((i+Ce*0.1)/(Ce*0.1+Ci*0.1))*100 << " % " << endl ;}
		cout << "finishing ... " << endl ; 
o.close () ; }
