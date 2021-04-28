#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H

#include <string>
#include "WaveHeader.h"

class 8bitWav {
public:
    void readFile(const std::string &fileName);
    void writeFile(const std::string &outFileName);
private:
    unsigned char* buffer = NULL;
    wav_header waveHeader;
	std::string Artist = "0";
	std::string songName = "0";
public:
    virtual ~Wav();

public:
    unsigned char *getBuffer();
    int getBufferSize() const;
	int getbitDepth() const;
	int getnumChannels() const;
	std::string getArtist() const;
	std::string getsongName() const;
};


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
