# neuron-project
This programme is a simulation of network of 12500 neurons, according to Brunel simulation.
To run it you will need to use cmake. The programme will ask you to enterthe different parameter of your network, like the ratio of Vext/Vthr, the relative inhibitory weight ans the duration of the simualtion. 
It will produce a results.txt file in your build that will contain the times at wich the spiking occured, then, using jupytier you will be abble to produce figure that will show you when the neuron spikes. 
One similution will take around 3 minutes for 600 ms. Over 600 ms, the program will be killed. 
