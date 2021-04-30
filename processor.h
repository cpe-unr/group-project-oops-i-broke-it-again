#ifndef PROCESSOR_H
#define PROCESSOR_H


#include <cstdint>
#include <cmath>
/**
* Interface for adding various effects to .wav files
*/
class IProcessable {
public:
/**
* Virtual function to be overridden by subclasses to add effects to .wav
*/
    virtual void processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels) = 0;
};


#endif
