#include "CsvExporter.h"
#include "../wav-store/WavStore.h"
#include "../Wav.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

CsvExporter::CsvExporter(WavStore* wavStore): wavStore(wavStore) {}

void CsvExporter::exportFile(std::string outputFileName) {
    std::ofstream outFile(outputFileName);

    writeRow(outFile, {
        "File Name", "Buffer Size", "Bit Depth", "Num of Channels", "Artist", "Song Name"
    });

    for (auto wavMap : wavStore->getWavs()) {
        Wav* wav = wavMap.second;
        writeRow(outFile, {
            wav->getFilePath(),
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