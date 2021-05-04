#include "echo.h"

		Echo::Echo(int delay) : delay(delay){}

		void Echo::processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels){
			if(numChannels == 1){
				if(bitDepth == 8){
					for(int i = 0; i < bufferSize; i++){
						buffer[i+delay] = .3 * buffer[i] +  buffer[i + delay];
						if(buffer[i] > 255){
							buffer[i] = 255;
						}
					}
				}
				if(bitDepth == 16){
					short* shortBuffer = reinterpret_cast<short*>(buffer);
					for(int i = 0; i < bufferSize/2-delay; i++){
						shortBuffer[i+delay] = .3 * shortBuffer[i] +  shortBuffer[i + delay];
						if(shortBuffer[i] > 32767){
							shortBuffer[i] = 32767;
						}
					}
					buffer = reinterpret_cast<unsigned char*>(shortBuffer);
				}
			}
			if(numChannels == 2){
				if(bitDepth == 8){
					for(int i = 0; i < bufferSize; i++){
						buffer[i+delay] = .3 * buffer[i] +  buffer[i + delay];
						if(buffer[i] > 255){
							buffer[i] = 255;
						}
					}
				}
				if(bitDepth == 16){
					short* shortBuffer = reinterpret_cast<short*>(buffer);
					for(int i = 0; i < bufferSize/2-delay; i++){
						shortBuffer[i+delay] = .3 * shortBuffer[i] +  shortBuffer[i + delay];
						if(shortBuffer[i] > 32767){
							shortBuffer[i] = 32767;
						}
					}
					buffer = reinterpret_cast<unsigned char*>(shortBuffer);
				}
			}
}
