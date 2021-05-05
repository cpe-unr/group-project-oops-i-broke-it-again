#ifndef CSV_EXPORTER_H
#define CSV_EXPORTER_H

#include "Exporter.h"
#include "../wav-store/WavStore.h"
#include "../Wav.h"
#include <string>
#include <vector>
#include <fstream>

/**
 * Handles exporting all loaded wav files to CSV.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class CsvExporter : public Exporter {
    WavStore* wavStore;

    /**
     * Formats the given data into a row of data for use in a CSV file.
     * @param outFile - ofstream of new CVS file to write to.
     * @param data - vector<string> of all row data.
    */
    void writeRow(std::ofstream& outFile, std::vector<std::string> data);
    
public:
    CsvExporter(WavStore* wavStore);

    /**
     * Exports all wav files to a csv file.
     * @param outputFileName - string of the name of the created CSV file.
    */
    void exportFile(std::string outputFileName) override;
};

#endif