
#include "noisegate.h"

#include <iostream>

		NoiseGate::NoiseGate(double threshold) : threshold(threshold){}

		void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels) {
			if(numChannels == 1){
				if(bitDepth == 8){
					for(int i = 0; i < bufferSize; i++){
						if(buffer[i] <= 128+threshold/100*128 && buffer[i] >= 128-threshold/100*128){
							buffer[i] = 128;
						}
					}
				}
				if(bitDepth == 16){
					short* shortBuffer = reinterpret_cast<short*>(buffer);
					for(int i = 0; i < bufferSize; i++){
						if(shortBuffer[i] <= 0+threshold/100*32762 && shortBuffer[i] >= 0-threshold/100*32762){
							shortBuffer[i] = 0;
						}
					}
					buffer = reinterpret_cast<unsigned char*>(shortBuffer);
			}
			if(numChannels == 2){
			}
