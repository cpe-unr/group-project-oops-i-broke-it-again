#ifndef CSV_EXPORTER_H
#define CSV_EXPORTER_H

#include "Exporter.h"
#include "../wav-store/WavStore.h"
#include "../Wav.h"
#include <string>
#include <vector>
#include <fstream>

class CsvExporter : public Exporter {
    WavStore* wavStore;
    void writeRow(std::ofstream& outFile, std::vector<std::string> data);
    
public:
    CsvExporter(WavStore* wavStore);
    void exportFile(std::string outputFileName) override;
};

#endif