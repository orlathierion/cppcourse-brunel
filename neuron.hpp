#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <fstream>
#include <random> 

using namespace std ; 


/**\class Neuron 
 *  The class Neuron represent a neuron caracterise by its potential, its resistance, 
 * the connexion it makes with other neurons. 
 */

class Neuron {
	private : 
	double Potential ;
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
	double j ; /*le potentiel envoyer par un spike */
	vector<Neuron*> connected ; 
	unsigned int BufferCurseur ; 
	array<double,4> Buffer ; 
	const bool excitatory ;
	double Vext ;
	int Ce ;  
	
	public : 
	
	/**
	 * \fn Neuron (bool e, double v, double g, int c)
	 * \param e : if you want to create qn excitatory neuronm e should be true, otherwise, it should be false 
	 * \param v : the value of Vext
	 * \param g : the relqtive weight of inhibitory neuron 
	 * \param c : the number of excitatory neuron 
	 */
	
	Neuron (bool e, double v, double g, int c) ;  
	~Neuron ();  

 /*!
  * \fn double getPotential () const
  * \return curent value of the membrqne potential */
  
	double getPotential (unsigned int h) const ;
/*!
 * \fn double getI () const 
 * \return the curent intensity of the external input 
 */
	double getI () const ;
	
/*!
 * \fn vector <double> getSpikes() const
 * \return a vector with all the time at wich a spike occured 
 */	
	
	vector<double> getSpikes () const; 

/*!
 * \fn int getTime () 
 * \return this function give us the time on the cells clock. 
 */	
	
	int getTime () ;  

/*!
 * \fn double getFiringThreshold ()  const
 * \return the firing threshold 
 */	
	
	double getFiringThreshold () const ; 
	
/*!
 * \fn double getTau () const 
 * \return {this fonction yill return the vqlue of tau	}
 */
	
	double getTau () const ; 
	
/*!
 * \fn double getMembraneRestistance () const 
 * \return  the membrqne resistqnce 
 */
	
	double getMembraneRestistance () const ; 
	
/*!
 * \fn void setI (double Z)  
 * \brief this function allow us to change the input coming to the neuron
 * \param Z : intensity of the input
 */	
	
	void setI (double Z ) ; 
	
/*!
 * \fn void setIntervalle (double debut, double fin)
 * \brief this fonction will allow us to set the begining and ending time of an external imput
 * \param debut {the begining of the imput}
 * \param fin {the end of the imput}
 */ 
	
	void setIntervalle (double debut, double fin) ;
	
	/*! 
 * \fn void setTime(double t )  
 * \brief it allows us to change the inner clock of the cell 
 * \param <t> {new time}
 */
	
	void setTime (double t) ;
	
/** 
 * \fn void setPotential (double t )
 * \brief this fonction will allow us to change the value of the emebrane potential. 
 * \param t : the new value of the potential
 */
	
	void setPotential (double t ) ; 
	
/*!
 * \fn void addConnection (Neuron* n )  
 * \brief addConnection create a new connection with a neuron 
 * \param <n> {it is a pointer on the neuron we want to connect to }
 */	
	
	void addConnection (Neuron* n ) ;
	
/*!
 * \fn void RefreshPotential (double h )  
 *  \brief RefreshPotential refresh the membrane potential at time h. 
 * \param <h> {time in the local clock}
 */	
	
	void RefreshPotential (double h) ;
	
/*!
 * \fn bool Is_spike (unsigned int h )
 *  \brief Is_Spike permet de savoir si un spike est crée ou non 
 * \return it will retrun true if a spike is created
 */	
	
	bool Is_spike (unsigned int h ) ;  
	
/*!
	 * \fn bool getRecord()
	 * \brief this fonction will give all the membrane potential at each steps
	 * \return {it will return a table with the time a the corresponding potential membrane}
	 */ 	
	
	vector<vector<double> > getRecord () const ; 
	
/*!
 * \fn void PrintSpike () 
 * \brief this will fonction will print all the time at wich spikes occured on the results document
 */	
	
	void PrintSpike () const ;
	
/*!
 * \fn bool isRefractory ()
 * \brief this fonction allows us to know if the neuron is in a refractory period 
 * \return {it will be true if the membrane is in its refractory periods }
 */	
	
	bool isRefractory ( ) ; 
	
/*!
 * \fn bool SendSpikes ()
 * \brief it allow us to know if the neuron is doing a spike at the curent time 
 * \return {it will retruns the value of the sended spikes}
 */	
	
	double SendSpikes (unsigned int h ) ; 
	
/**
 * \fn double ReceiveSpike (unsigned int h )  
 * \brief this fonction will collect all the spikes that the connected neuron have sended 
 * \param <h> the time at which we look if the spikes were send
 **/ 	
	
	double ReceiveSpike (unsigned int h ) ; 
	
/**
 * \fn bool IsExcitatory ()
 * \brief this fonction allows us to know what type of neuron it is 
 * \return it will be true if the neuron is excitatory
 */ 
	 
	bool IsExcitatory () ;
	
/*!
 * \fn int getCe () const 
 * \return the value of Ce
 */
 
	int getCe () const ; 
	
/*!
 * \fn int getCi () const 
 * \return the value of Ci
 */
	
	int getCi () const ; 
	
/**
 * \fn  double getNumberSpike () const
 * \return the number of spikes that has occured 
 */
	
	double getNumberSpike () const ; 
	
/**
 * \fn void updateRecord () 
 * \brief this fonction will add the last potential to the record vector 
 */	
	 
	void updateRecord () ; 
	
/**
 * \fn Neuron* getConnected (int i) 
 * \param i : the nuéber of the neuron we want to qccess in the connected vector
 * \return a pointer on the ith neuron in the connected vector
 */
	
	Neuron* getConnected (int i ) ; 
	
/**
 * \fn int getNumberConnection () const
 * \return the number of connection 
 */
	
	int getNumberConnection () const ; 
	};

#endif 

