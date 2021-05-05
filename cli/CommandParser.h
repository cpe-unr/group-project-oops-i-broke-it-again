#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "Command.h"
#include "../wav-store/WavStore.h"
#include "../export/Exporter.h"
#include <vector>
#include <string>

/**
 * Handles parsing the user input to create the corresponding cli command.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class CommandParser {
    Command* command;
    WavStore* wavStore;
    Exporter* exporter;
    std::vector<std::string> arguments;

    /**
     * Creates the corresponding command from user input.
     * @param input - string of the command portion of the user input.
     */
    Command* createCommand(std::string input);

public:
    CommandParser(WavStore* wavStore, Exporter* exporter);

    /**
     * Parse the user input and sets the arguments and builds the command.
     * @param input - string of user input.
     */
    void parse(std::string input);

     /**
     * Returns the command parsed by `parse`.
     */
    Command* getCommand();

    /**
     * Returns the command arguments parsed by `parse`.
     */
    std::vector<std::string> getArgs();
};

#endif