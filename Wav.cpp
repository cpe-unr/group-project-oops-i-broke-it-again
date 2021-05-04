#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Wav.h"


void Wav::readFile(const std::string &fileName) {
    std::string metadataTemp;
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);
		while(!file.eof()){
	 	   std::getline(file, metadataTemp);
			if(metadataTemp.compare(0, 4, "INAM") == 0){
				std::getline(file, metadataTemp);
				std::getline(file, metadataTemp);
				songName = metadataTemp;
			}
			if(metadataTemp.compare(0, 4, "IART") == 0){
				std::getline(file, metadataTemp);
				std::getline(file, metadataTemp);
				Artist = metadataTemp;
			}
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
    outFile << "INAM" << std::endl << songName.length() << std::endl << songName << std::endl;
    outFile << "IART" << std::endl << Artist.length() << std::endl << Artist << std::endl;
    outFile.close();
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

int Wav::getBufferSize() const {
    return waveHeader.data_bytes;
}

int Wav::getbitDepth() const {
    return waveHeader.bit_depth;
}

int Wav::getnumChannels() const {
    return waveHeader.num_channels;
}

std::string Wav::getArtist() const {
    return Artist;
}

void Wav::setArtist(std::string x) {
	Artist = x;
}

std::string Wav::getSongName() const {
    return songName;
}

void Wav::setSongName(std::string y) {
	songName = y;
}

void Wav::setFilePath(std::string filePath) {
    Wav::filePath = filePath;
}

std::string Wav::getFilePath() {
    return filePath;
}

