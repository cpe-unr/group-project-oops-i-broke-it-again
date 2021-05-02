#include "CommandParser.h"
#include "../WavFinder/WavFinderCommand.h"
#include "../process/ProcessCommand.h"
#include "../process/ProcessCommandHandler.h"
#include "../edit-meta/EditMetaCommand.h"
#include "../noisegate.h"
#include "../echo.h"
#include "../normalizer.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

CommandParser::CommandParser(WavFinder* wavFinder): wavFinder(wavFinder) {}
    
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
        return new WavFinderCommand(wavFinder);
    } else if (input == "process") {
        std::vector<IProcessable*> proccesses = {new NoiseGate(1), new Normalizer(), new Echo(5000)};
        return new ProcessCommand(new ProcessCommandHandler(proccesses, wavFinder));
    } else if (input == "edit-meta") {
        return new EditMetaCommand(wavFinder);
    }
}