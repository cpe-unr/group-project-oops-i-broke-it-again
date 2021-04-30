#ifndef NORMALIZER_H
#define NORMALIZER_H
#include "processor.h"
/**
* Class to add a normalizer effect to .wav files
*/
class Normalizer : public IProcessable {

	public:
/**
* Function that normalizes each sample dependent on sound data
* @param buffer - buffer containing sound data
* @param bufferSize - size of the buffer of sound data
* @param bitDepth - bit depth of the .wav
* @param numChannels - number of channels of the .wav
*/
		void processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels) override;
};

#endif

