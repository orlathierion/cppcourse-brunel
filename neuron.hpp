
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
 *  The class Neuron represents a neuron caracterised by its potential, its resistance, 
 * the connexion it makes with other neurons. 
 */

class Neuron {
	private : 
	int numero ; 
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
 * \fn double getPotential (unsigned int h) const
 * \param h : the time qt wich ywe want the potential
 * \return The curent value of the membrane potential. */
  
	double getPotential (unsigned int h) const ;
/*!
 * \fn double getI () const 
 * \return The curent intensity of the external input.
 */
	double getI () const ;
	
/*!
 * \fn vector <double> getSpikes() const
 * \return A vector with all the time at wich a spike occured. 
 */	
	
	vector<double> getSpikes () const; 

/*!
 * \fn int getTime () 
 * \return This function gives us the time on the cells clock. 
 */	
	
	int getTime () ;  

/*!
 * \fn double getFiringThreshold ()  const
 * \return The firing threshold 
 */	
	
	double getFiringThreshold () const ; 
	
/*!
 * \fn double getTau () const 
 * \return This fonction will returns the value of tau
 */
	
	double getTau () const ; 
	
/*!
 * \fn double getMembraneRestistance () const 
 * \return  the membrqne resistqnce 
 */
	
	double getMembraneRestistance () const ; 
	
/*!
 * \fn void setI (double Z)  
 * \brief This function allow us to change the input coming to the neuron.
 * \param Z : intensity of the imput
 */	
	
	void setI (double Z ) ; 
	
/*!
 * \fn void setIntervalle (double debut, double fin)
 * \brief This fonction will allow us to set the begining and ending time of an external imput.
 * \param debut : the begining of the imput
 * \param fin : the end of the imput
 */ 
	
	void setIntervalle (double debut, double fin) ;
	
	/*! 
 * \fn void setTime(double t )  
 * \brief It allows us to change the inner clock of the cell. 
 * \param t : new time
 */
	
	void setTime (double t) ;
	
/** 
 * \fn void setPotential (double t )
 * \brief This fonction will allow us to change the value of the emebrane potential. 
 * \param t : the new value of the potential
 */
	
	void setPotential (double t ) ; 
	
/*!
 * \fn void addConnection (Neuron* n )  
 * \brief addConnection create a new connection with a neuron. 
 * \param n : it is a pointer on the neuron we want to connect to 
 */	
	
	void addConnection (Neuron* n ) ;
	
/*!
 * \fn void RefreshPotential (double h )  
 *  \brief RefreshPotential refresh the membrane potential at time h. 
 * \param h : time in the local clock
 */	
	
	void RefreshPotential (double h) ;
	
/*!
 * \fn bool Is_spike (unsigned int h )
 *  \brief Is_Spike let us know if there was a spike or not. 
 * \param h : the time qt wich we want to know if there is a spike
 * \return it will retrun true if a spike is created
 */	
	
	bool Is_spike (unsigned int h ) ;  
	
/*!
* \fn bool getRecord()
* \brief this fonction will give all the membrane potential at each steps
* \return It will return a table with the time a the corresponding potential membrane.
*/ 	
	
	vector<vector<double> > getRecord () const ; 
	
/*!
 * \fn int getASpike (unsigned int i) const
 * \param i : the numero of the spike you want to access
 * \return The time at wich this spike occured. 
 */
 
 int getASpike (unsigned int i ) const ; 
	
/*!
 * \fn bool isRefractory ()
 * \brief This fonction allows us to know if the neuron is in a refractory period. 
 * \param i : itcorrespond to the number of the neuron in the network
 *\return It will be true if the membrane is in its refractory periods. 
 */	
	
	bool isRefractory ( ) ; 
	
/*!
 * \fn bool SendSpikes ()
 * \brief It allow us to know if the neuron is doing a spike at the curent time. 
 * \return It will retruns the value of the sended spikes.
 */	
	
	double SendSpikes (unsigned int h ) ; 
	
/**
 * \fn double ReceiveSpike (unsigned int h )  
 * \brief This fonction will give us the sum of the spikes received by the neuron,and take into account the buffer delay. 
 * \param h : the time at which we look if the spikes were send
 **/ 	
	
	double ReceiveSpike (unsigned int h ) ; 
	
/**
 * \fn bool IsExcitatory ()
 * \brief This fonction allows us to know what type of neuron it is. 
 * \return It will be true if the neuron is excitatory.
 */ 
	 
	bool IsExcitatory () ;
	
/*!
 * \fn int getCe () const 
 * \return The value of Ce
 */
 
	int getCe () const ; 
	
/*!
 * \fn int getCi () const 
 * \return The value of Ci
 */
	
	int getCi () const ; 
	
/**
 * \fn  double getNumberSpike () const
 * \return The number of spikes that has occured.
 */
	
	double getNumberSpike () const ; 
	
/**
 * \fn void updateRecord () 
 * \brief This fonction will add the last potential to the record vector. 
 */	
	 
	void updateRecord () ; 
	
/**
 * \fn Neuron* getConnected (int i) 
 * \param i : The number of the neuron we want to access in the connected vector.
 * \return A pointer on the ith neuron in the connected vector.
 */
	
	Neuron* getConnected (int i ) ; 
	
/**
 * \fn int getNumberConnection () const
 * \return The number of connection 
 */
	
	int getNumberConnection () const ; 
	};

#endif 
