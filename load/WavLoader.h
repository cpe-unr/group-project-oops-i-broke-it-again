#ifndef WAV_FINDER_H
#define WAV_FINDER_H

#include "../wav-store/WavStore.h"
#include <vector>
#include <string>
#include <dirent.h>

class WavLoader  {
    WavStore* wavStore;
    
    std::string getUsersDirectory();
    std::vector<std::string> getFilesFromDirectory(std::string dirPath);
    bool isInvalidWavFile(dirent* f);

public:
    WavLoader(WavStore* wavStore);
    void load(std::vector<std::string> args);
};

#endif