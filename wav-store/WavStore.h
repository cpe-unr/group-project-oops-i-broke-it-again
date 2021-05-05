#ifndef WAV_STORE_H
#define WAV_STORE_H

#include "../Wav.h"
#include <string>
#include <vector>
#include <map>

/**
 * Wav file storage.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class WavStore {
    std::map<std::string, Wav*> wavs;

public:

    /**
     * Returns a map of all loaded wav files with the file name as the key.
     */
    std::map<std::string, Wav*> getWavs() const;
    
    /**
     * Adds a wav file to the store using the corresponding file name as the key.
     * @param key - string of corresponding file name.
     * @param wav - Wav* of wav file to store.
     */
    void addWav(std::string key, Wav* wav);

    /**
     * Returns a Wav* given the corresponding file name.
     * @param key - string of corresponding file name.
     */
    Wav* getWavByFileName(std::string key);
};

#endif