#ifndef CSV_EXPORTER_H
#define CSV_EXPORTER_H

#include "Exporter.h"
#include "../WavFinder/WavFinder.h"
#include "../Wav.h"
#include <string>
#include <vector>
#include <fstream>

class CsvExporter : public Exporter {
    WavFinder* wavFinder;
    void writeRow(std::ofstream& outFile, std::vector<std::string> data);
    
public:
    CsvExporter(WavFinder* wavFinder);
    void exportFile(std::string outputFileName) override;
};

#endif