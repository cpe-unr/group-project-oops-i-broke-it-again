#ifndef PROGRAMMING_ASSIGNMENT_3KL_WAV_H
#define PROGRAMMING_ASSIGNMENT_3KL_WAV_H

#include <string>
#include "wavheader.h"
/**
* Class designed to read and write .wav files
*/
class Wav {
public:
/**
* Reads in the technical data and metadata of a .wav file
* @param fileName - string of the .wav filename
**/

    void readFile(const std::string &fileName);
/**
* Writes the technical data and metadata to a .wav file
* @param outFileName - Name of the file being output
*/
    void writeFile(const std::string &outFileName);
private:
    unsigned char* buffer = NULL;
    wav_header waveHeader;
	std::string Artist = "0";
	std::string songName = "0";
	std::string filePath;
public:
/**
* Deconstructor for the Wav object
*/
    virtual ~Wav();

public:
/**
* Returns the buffer of .wav sound data
*/
    unsigned char *getBuffer();
/**
* Returns the size of the wav buffer
*/
    int getBufferSize() const;
/**
* Returns the bitDepth of a .wav file
*/
	int getbitDepth() const;
/**
* Returns the number of channels of a .wav file
*/
	int getnumChannels() const;
/**
* Returns the Artist held on a .wav file
*/
	std::string getArtist() const;

/**
* Changes the value of string Artist
* @param x - string to replace Artist value
*/
	void setArtist(std::string x);
/**
* Returns the song name contained in a .wav file
*/
	std::string getSongName() const;
/**
* Changes value of string songName
* @param y - string to replace songName value
*/
	void setSongName(std::string y);

	/**
	* Sets the full file path of source wav file.
	* @param filePath - string path of wav file name.
	*/
	void setFilePath(std::string filePath);

	/**
	* Returns the full file path of source wav file.
	*/
	std::string getFilePath();
};


#endif //PROGRAMMING_ASSIGNMENT_3KL_WAV_H
