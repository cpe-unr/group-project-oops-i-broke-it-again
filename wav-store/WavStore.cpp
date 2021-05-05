#include "WavStore.h"
#include "../Wav.h"
#include <string>
#include <map>
#include <stdexcept>
#include <iostream>
    
void WavStore::addWav(std::string key, Wav* wav) {
    wavs.insert(std::pair<std::string, Wav*>(key, wav));
}

std::map<std::string, Wav*> WavStore::getWavs() const {
    return wavs;
}
    
Wav* WavStore::getWavByFileName(std::string fileName) {
    try {
        return wavs.at(fileName);
    } catch(std::out_of_range &e) {
        throw std::runtime_error("File doesn't exist.");
    }
}