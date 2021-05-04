#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "Command.h"
#include "../wav-store/WavStore.h"
#include "../export/Exporter.h"
#include <vector>
#include <string>

class CommandParser {
    Command* command;
    WavStore* wavStore;
    Exporter* exporter;
    std::vector<std::string> arguments;

    Command* createCommand(std::string input);

public:
    CommandParser(WavStore* wavStore, Exporter* exporter);
    void parse(std::string input);
    Command* getCommand();
    std::vector<std::string> getArgs();
};

#endif