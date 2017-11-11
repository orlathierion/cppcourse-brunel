# neuron-project
This programme is a simulation of network of 12500 neurons, according to the model descrived by Nicolas Brunel in his 
Dynamics of Sparsely Connected Networks of Excitatory and Inhibitory Spiking Neurons paper in 2000.

To run it you will need to use cmake. The programme will ask you to enter the different parameter of your network, like the ratio of Vext/Vthr, the relative inhibitory weight ans the duration of the simualtion. To generate the documentation, you will need to us doxyfile. All the documentation will be found in the doc file. 

It will produce a Spikes.gdb file in your build that will contain the times at wich the spiking occured, then, using jupytier you will be abble to produce figure that will show you when the neuron spikes. 

One similution will take around 1 minutes for 600 ms, and the 15 minutes to print out the results. Over 600 ms, the program will be killed. 

The results you will get cannot be put in a graphic by jupyter (error : index 0 is out of boundfor axis 0 with size 0)
