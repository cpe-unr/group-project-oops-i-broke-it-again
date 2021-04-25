#include "WavFinder.h"
#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

std::vector<std::string> WavFinder::getFiles() {
    std::string dirPath = getUsersDirectory();
    std::vector<std::string> files = getFilesFromDirectory(dirPath);

    // TODO: remove. Used for debugging.
    for (auto f : files) {
        std::cout << "f: " << f << std::endl;
    }

    return files;
}

std::string WavFinder::getUsersDirectory() {
    std::cout << "Enter path dir: " << std::endl;

    std::string dirPath;
    std::cin >> dirPath;

    return dirPath;
}

std::vector<std::string> WavFinder::getFilesFromDirectory(std::string dirPath) {
    std::vector<std::string> files;

    if (auto dir = opendir((dirPath + "/").c_str())) {
        while (auto f = readdir(dir)) {
            if (isInvalidWavFile(f))
                continue; 

            files.push_back(f->d_name);
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




