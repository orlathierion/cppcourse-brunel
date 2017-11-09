#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <fstream>
#include <random> 

using namespace std ; 

///
/// \class Neuron 
/// The class Neuron represent a neuron caracterise by its potential, its resistance, 
/// the connexion it makes with other neurons. 
///

class Neuron {
	private : 
	double Potential ;/*!<je commente cette vqriqble */
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
	const bool excitatory ; 
	
	public : 
	Neuron (bool e) ;  
	~Neuron ();  
	/// 
 ///\fn (getPotential () ) 
 ///getPotential return the curent membrane potential
 ///
	double getPotential (unsigned int h) const ;
	/**
 * \fn (getI ()) 
 * getI give us the curent intensity of the external input 
 */
	double getI () const ;
	
/**
 * \fn (getSpikes()) 
 * this function returns a table with all the time at wich a spike occured 
 **/	
	
	vector<double> getSpikes () const; 

/**
 * \fn (getTime () ) 
 * this function give us the time on the cells clock. 
 **/	
	
	int getTime () ;  

/**
 * \fn (getFiringThreshold () ) 
 * this function give us access to the firing threshold 
 **/	
	
	double getFiringThreshold () const ; 
	
/**
 * \fn (getTau ()) 
 * \return {this fonction yill return the vqlue of tau	}
 */
	
	double getTau () const ; 
	
/**
 * \fn (getMembraneResistance ()) 
 * this fonction will return the value of the membrqne resistqnce 
 **/
	
	double getMembraneRestistance () const ; 
	
/**
 * \fn (setI (double Z) ) 
 * this function allow us to change the input coming to the neuron
 * \param <Z> {intensity of the input}
 **/	
	
	void setI (double Z ) ; 
	void setIntervalle (double debut, double fin) ;
	
	/** 
 * \fn (setTime(double t ) ) 
 * it allows us to change the inner clock of the cell 
 * \param <t> {new time}
 **/
	
	void setTime (double t) ;
	
	
	
	void setPotential (double t ) ; 
	
/**
 * \fn (addConnection (Neuron* n ) ) 
 * addConnection create a new connection with a neuron 
 * \param <n> {it is a pointer on the neuron we want to connect to }
 **/	
	
	void addConnection (Neuron* n ) ;
	
/**
 * \fn (RefreshPotential (double h ) ) 
 *  RefreshPotential refresh the membrane potential at time h. 
 * \param <h> {time in the local clock}
 **/	
	
	void RefreshPotential (double h) ;
	
/**
 * \fn (Is_Spike())
 *  Is_Spike permet de savoir si un spike est crée ou non 
 * \return {it will retrun true if a spike is created}
 **/	
	
	bool Is_spike (unsigned int h ) ;  
	
/** 
	 * \fn (getRecord())
	 * this fonction will give all the membrane potential at each steps
	 * \return {it will return a table with the time a the corresponding potential membrane}
	 **/ 	
	
	vector<vector<double> > getRecord () const ; 
	
/**
 * \fn (PrintRecord ()) 
 * this fonction print all the potential for each time steps on the results document
 **/	
	
	void PrintRecord () const ; 
	
/**
 * \fn (PrintSpike ()) 
 * this will fonction will print all the time at wich spikes occured on the results document
 **/	
	
	void PrintSpike () const ;
	
/**
 * \fn (isRefractory ())
 * this fonction allows us to know if the neuron is in a refractory period 
 * \return {it will be true if the membrane is in its refractory periods }
 **/	
	
	bool isRefractory ( ) ; 
	
/**
 * \fn (SendSpikes ()) 
 * it allow us to know if the neuron is doing a spike at the curent time 
 * \return {it will retruns the value of the sended spikes}
 **/	
	
	double SendSpikes (unsigned int h ) ; 
	
/**
 * \fn (ReceiveSpike () ) 
 * this fonction will collect all the spikes that the connected neuron have sended 
 **/ 	
	
	double ReceiveSpike (unsigned int h ) ;  
	bool IsExcitatory () ;
	int getCe () const ; 
	int getCi () const ; 
	
	/**
 * \fn (getNumberSpikes ()) 
 * it returns the number of spikes that has occured 
 **/
	
	double getNumberSpike () const ;  
	void updateRecord () ; 
	Neuron* getConnected (int i ) ; 
	};

#endif 

