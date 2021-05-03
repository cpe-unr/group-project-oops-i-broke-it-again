#include "ExportCommand.h"
#include "Exporter.h"
#include <iostream>

ExportCommand::ExportCommand(Exporter* exporter): 
    exporter(exporter),
    Command("hi", nullptr) {}

void ExportCommand::execute(std::vector<std::string> args) {
    if (args.size() == 0) {
        std::cout << "Incorrect arguments. Please include output file name." << std::endl;
        return;
    }

    std::string outFileName = args.at(0);

    exporter->exportFile(outFileName);
}