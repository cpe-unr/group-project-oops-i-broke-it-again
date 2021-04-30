#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "processor.h"
/**
* Class to add a noise gate to a .wav file
*/
class NoiseGate : public IProcessable {
	double threshold;

	public:
/**
* Constructor for NoiseGate effect
* @param threshold - percentage threshold for noise gating
*/
		NoiseGate(double threshold);
/**
* Function that echoes each sample per user's input
* @param buffer - buffer containing sound data
* @param bufferSize - size of the buffer of sound data
* @param bitDepth - bit depth of the .wav
* @param numChannels - number of channels of the .wav
*/
		void processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels) override;

};

#endif
