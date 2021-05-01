#ifndef WAV_FINDER_H
#define WAV_FINDER_H

#include "../cli/CommandHandler.h"
#include "../Wav.h"
#include <vector>
#include <string>
#include <dirent.h>

class WavFinder: public CommandHandler  {
    std::vector<std::string> files;
    std::vector<Wav*> wavs;
    std::string getUsersDirectory();
    std::vector<std::string> getFilesFromDirectory(std::string dirPath);
    bool isInvalidWavFile(dirent* f);

public:
    WavFinder() = default;
    void handle(std::vector<std::string> args) override;
    std::vector<std::string> getFiles();
    std::vector<Wav*> getWavs();
    Wav* getWavFromFileName(std::string fileName);
};

#endif