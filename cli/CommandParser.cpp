#include "CommandParser.h"
#include "../wav-store/WavStore.h"
#include "../load/LoadCommand.h"
#include "../process/ProcessCommand.h"
#include "../edit-meta/EditMetaCommand.h"
#include "../export/CsvExporter.h"
#include "../export/ExportCommand.h"
#include "../export/Exporter.h"
#include "../noisegate.h"
#include "../echo.h"
#include "../normalizer.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

CommandParser::CommandParser(WavStore* wavStore, Exporter* exporter): 
    wavStore(wavStore), 
    exporter(exporter) {}
    
void CommandParser::parse(std::string input) {
    std::vector<std::string> tokenized;

    std::string tmp;
    std::stringstream ss(input);
    while(getline(ss, tmp, ' ')) {
        tokenized.push_back(tmp);
    }

    std::string commandString = tokenized.at(0);
    command = createCommand(commandString);
    
    std::vector<std::string> localArgs(tokenized.begin() + 1, tokenized.end());
    for (auto item: localArgs) {
        this->arguments.push_back(item);
    }
}

Command* CommandParser::getCommand() {
    return command;
}

std::vector<std::string> CommandParser::getArgs() {
    return this->arguments;
}

Command* CommandParser::createCommand(std::string input) {
    if (input == "load") {
        return new LoadCommand(new WavLoader(wavStore));
    } else if (input == "process") {
        std::vector<IProcessable*> proccesses = {new NoiseGate(1), new Normalizer(), new Echo(10000)};
        return new ProcessCommand(proccesses, wavStore);
    } else if (input == "edit-meta") {
        return new EditMetaCommand(wavStore);
    } else if (input == "export") {
        return new ExportCommand(exporter);
    } else {
        return nullptr;
    }
}