#include "CsvExporter.h"
#include "../WavFinder/WavFinder.h"
#include "../Wav.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

CsvExporter::CsvExporter(WavFinder* wavFinder): wavFinder(wavFinder) {}

void CsvExporter::exportFile(std::string outputFileName) {
    std::vector<Wav*> wavs = wavFinder->getWavs();
    std::vector<std::string> files = wavFinder->getFiles();
    std::ofstream outFile(outputFileName);

    writeRow(outFile, {
        "File Name", "Buffer Size", "Bit Depth", "Num of Channels", "Artist", "Song Name"
    });

    for(int i = 0; i < wavs.size(); i++) {
        Wav* wav = wavs.at(i);
        std::string fileName = files.at(i);
        writeRow(outFile, {
            fileName,
            std::to_string(wav->getBufferSize()),
            std::to_string(wav->getbitDepth()),
            std::to_string(wav->getnumChannels()),
            wav->getArtist(),
            wav->getSongName(),
        });
    }
    
    outFile.close();
}

void CsvExporter::writeRow(std::ofstream& outFile, std::vector<std::string> data) {
    for(std::string cell : data) {
        outFile << cell << ", ";
    }
    outFile << std::endl;
}