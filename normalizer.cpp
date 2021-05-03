#include "normalizer.h"


void Normalizer::processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels){
	int maxNum = 0, i = 0;

	if(bitDepth == 8){
		for(i = 0; i < bufferSize-1; i++){
			maxNum = getMax<unsigned char>(buffer[i], buffer[i+1]);
		}
		double multiplier = 256/maxNum;
		for(i = 0; i < bufferSize; i++){
			buffer[i] = multiplier * buffer[i];
		}
	}
	if(bitDepth == 16){
		short* shortBuffer = reinterpret_cast<short*>(buffer);
		for(i = 0; i < bufferSize-1; i++){
			maxNum = getMax<short>(shortBuffer[i], shortBuffer[i+1]);
		}
		double multiplier = 32767/maxNum;
		for(i = 0; i < bufferSize; i++){
			shortBuffer[i] = multiplier * shortBuffer[i];
		}
		buffer = reinterpret_cast<unsigned char*>(shortBuffer);
	}
}
