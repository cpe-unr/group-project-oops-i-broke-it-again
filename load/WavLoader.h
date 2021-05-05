#ifndef WAV_FINDER_H
#define WAV_FINDER_H

#include "../wav-store/WavStore.h"
#include <vector>
#include <string>
#include <dirent.h>

/**
 * Loads wav files.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class WavLoader  {
    WavStore* wavStore;
    
    /**
     * Retrieves all wav files found in a given directory path.
     * @param dirPath - string of directory path
     */
    std::vector<std::string> getFilesFromDirectory(std::string dirPath);

    /**
     * Returns whether a given file is an invalid wav file.
     * @param f - dirent instance of file.
     */
    bool isInvalidWavFile(dirent* f);

public:
    WavLoader(WavStore* wavStore);

    /**
     * Loads all the wav files found in a given a directory path into the wav store.
     * @param args - string of directory path
     */
    void load(std::string dirPath);
};

#endif