#include "WavFinder.h"
#include "../Wav.h"
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdexcept>

void WavFinder::handle(std::vector<std::string> args) {
    dirPath = args.at(0);
    
    files = getFilesFromDirectory();

    // TODO: remove. Used for debugging.
    for (auto f : files) {
        Wav* wavReader = new Wav();
        wavReader->readFile(f);
        wavs.push_back(wavReader);
    }
}

std::vector<std::string> WavFinder::getFiles() {
    return files;
}

std::vector<Wav*> WavFinder::getWavs() {
    return wavs;
}

Wav* WavFinder::getWavFromFileName(std::string fileName) {
    int correspondingIndex = 0;
    auto it = std::find(files.begin(), files.end(), getFullPath(fileName));

    if (it != files.end()) {
        int correspondingIndex = it - files.begin();
    } else {
        throw std::runtime_error("Wav not found.");
    }

    return wavs.at(correspondingIndex);
}

std::string WavFinder::getFullPath(std::string fileName) {
    return dirPath + "/" + fileName;
}

std::vector<std::string> WavFinder::getFilesFromDirectory() {
    std::vector<std::string> files;

    if (auto dir = opendir((dirPath + "/").c_str())) {
        while (auto f = readdir(dir)) {
            if (isInvalidWavFile(f))
                continue; 

            files.push_back(getFullPath(f->d_name));
        }
        closedir(dir);
    } else {
        std::cout << dirPath << " doesn't exist.\n" << std::endl;
    }

    return files;
}

// Skip everything thats not a file, starts with a dot, and isn't a .wav
bool WavFinder::isInvalidWavFile(dirent* f) {
return f->d_name[0] == '.' ||
        strcmp(&f->d_name[strlen(f->d_name) - 4], ".wav") != 0;
}




