#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include "Wav.h"


void Wav::readFile(const std::string &fileName) {
    int i = 0;
    std::string metadataTemp;
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&waveHeader, sizeof(wav_header));
        buffer = new unsigned char[waveHeader.data_bytes];
        file.read((char*)buffer, waveHeader.data_bytes);
		while(!file.eof()){
	 	   std::getline(file, metadataTemp);
                   listChunk.emplace_back(metadataTemp);
		   i++;
			if(metadataTemp.compare(0, 4, "INAM") == 0){
				std::getline(file, metadataTemp);
				listChunk.emplace_back(metadataTemp);
				i++;
				std::getline(file, metadataTemp);
				listChunk.emplace_back(metadataTemp);
				aIndex = i;
				songName = metadataTemp;
				i++;

			}
			if(metadataTemp.compare(0, 4, "IART") == 0){
				std::getline(file, metadataTemp);
				listChunk.emplace_back(metadataTemp);
				i++;
				std::getline(file, metadataTemp);
				listChunk.emplace_back(metadataTemp);
				snIndex = i;
				Artist = metadataTemp;
				i++;
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
    outFile.write(reinterpret_cast<char*>(&listChunk[0]), listChunk.size() * sizeof(listChunk[0]));
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
    return listChunk[aIndex];
}

void Wav::setArtist(std::string x) {
	listChunk[aIndex] = x;
	listChunk[aIndex - 1] = x.length();
	
}

std::string Wav::getSongName() const {
    return listChunk[snIndex];
}

void Wav::setSongName(std::string y) {
	listChunk[snIndex] = y;
	listChunk[snIndex - 1] = y.length();
}

void Wav::setFilePath(std::string filePath) {
    Wav::filePath = filePath;
}

std::string Wav::getFilePath() {
    return filePath;
}

