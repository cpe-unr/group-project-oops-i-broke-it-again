#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "Command.h"
#include "../WavFinder/WavFinder.h"
#include <vector>
#include <string>

class CommandParser {
    Command* command;
    WavFinder* wavFinder;
    std::vector<std::string> arguments;

    Command* createCommand(std::string input);

public:
    CommandParser(WavFinder* wavFinder);
    void parse(std::string input);
    Command* getCommand();
    std::vector<std::string> getArgs();
};

#endif