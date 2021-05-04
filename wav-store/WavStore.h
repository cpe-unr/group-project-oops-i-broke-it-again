#ifndef WAV_STORE_H
#define WAV_STORE_H

#include "../Wav.h"
#include <string>
#include <vector>
#include <map>

class WavStore {
    std::map<std::string, Wav*> wavs;

public:
    std::map<std::string, Wav*> getWavs() const;
    
    void addWav(std::string key, Wav* wav);

    Wav* getWavByFileName(std::string key);
};

#endif