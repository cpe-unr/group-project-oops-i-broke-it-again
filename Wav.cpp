#include <string>
#include <fstream>
#include <iostream>
#include "Wav.h"



void Wav::readFile(const std::string &fileName) {
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
	if(waveHeader.bit_depth == 8 && waveHeader.num_channels == 1){
        	buffer = new unsigned char[waveHeader.data_bytes];
        	file.read((char*)buffer, waveHeader.data_bytes);	
	}
	if(waveHeader.bit_depth == 16 && waveHeader.num_channels == 1){
	}
	if(waveHeader.bit_depth == 24 && waveHeader.num_channels == 1){
	}
	if(waveHeader.bit_depth == 32 && waveHeader.num_channels == 1){
	}
	if(waveHeader.bit_depth == 8 && waveHeader.num_channels == 2){
	}
	if(waveHeader.bit_depth == 16 && waveHeader.num_channels == 2){
	}
	if(waveHeader.bit_depth == 24 && waveHeader.num_channels == 2){
	}
	if(waveHeader.bit_depth == 32 && waveHeader.num_channels == 2){
	}

        file.close();
    }
}


unsigned char *Wav::getBuffer(){
    return buffer;
}

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&waveHeader,sizeof(wav_header));
    outFile.write((char*)buffer, waveHeader.data_bytes);
    outFile.close();
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

int Wav::getBufferSize() const {
    return waveHeader.data_bytes;
}
