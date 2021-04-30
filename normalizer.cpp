#include "normalizer.h"


void Normalizer::processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels){
	int maxNum = 0, i = 0;

	if(bitDepth == 8){
		for(i = 0; i < bufferSize; i++){
			if(buffer[i] > maxNum){
				maxNum = buffer[i];
			}
		}
		double multiplier = 256/maxNum;
		for(i = 0; i < bufferSize; i++){
			buffer[i] = multiplier * buffer[i];
		}
	}
	if(bitDepth == 16){
		short* shortBuffer = reinterpret_cast<short*>(buffer);
		for(i = 0; i < bufferSize; i++){
			if(shortBuffer[i] > maxNum){
				maxNum = shortBuffer[i];
			}
		}
		double multiplier = 32767/maxNum;
		for(i = 0; i < bufferSize; i++){
			shortBuffer[i] = multiplier * shortBuffer[i];
		}
		buffer = reinterpret_cast<unsigned char*>(shortBuffer);
	}
}
