#include "../interfaces/FileHandler.h"
#include <vector>
#include <string>
#include <dirent.h>

class WavFinder: public FileHandler  {
    std::string getUsersDirectory();
    std::vector<std::string> getFilesFromDirectory(std::string dirPath);
    bool isInvalidWavFile(dirent* f);

public:
    std::vector<std::string> getFiles();
};