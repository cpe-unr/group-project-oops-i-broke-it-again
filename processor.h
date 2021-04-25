#ifndef PROCESSOR_H
#define PROCESSOR_H


#include <cstdint>
#include <cmath>

class IProcessable {
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels) = 0;
};


#endif
