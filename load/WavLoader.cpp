#include "WavLoader.h"
#include "../Wav.h"
#include "../wav-store/WavStore.h"
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdexcept>

WavLoader::WavLoader(WavStore* wavStore): wavStore(wavStore) {}

void WavLoader::load(std::string dirPath) {
    for (std::string fileName : getFilesFromDirectory(dirPath)) {
        std::string fullPath = dirPath + "/" + fileName;

        Wav* wav = new Wav();
        wav->readFile(fullPath);
        wav->setFilePath(fullPath);
        
        wavStore->addWav(fileName, wav);
        std::cout << "added " << fileName << std::endl;
    }
}

std::vector<std::string> WavLoader::getFilesFromDirectory(std::string dirPath) {
    std::vector<std::string> files;

    if (auto dir = opendir((dirPath + "/").c_str())) {
        while (auto f = readdir(dir)) {
            if (isInvalidWavFile(f)) {
                continue;
            }

            files.push_back(f->d_name);
        }
        closedir(dir);
    } else {
        std::cout << dirPath << " doesn't exist.\n" << std::endl;
    }

    return files;
}

// Skip everything thats not a file, starts with a dot, and isn't a .wav
bool WavLoader::isInvalidWavFile(dirent* f) {
return f->d_name[0] == '.' ||
        strcmp(&f->d_name[strlen(f->d_name) - 4], ".wav") != 0;
}




