#ifndef ECHO_H
#define ECHO_H
#include "processor.h"

/**
* Class to add an echo effect to a .wav file
*/
class Echo : public IProcessable {
	int delay;

	public:
/**
* Constructor for the Echo effect
* @param delay - the delay of each sample as an int
*/
		Echo(int delay);
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
