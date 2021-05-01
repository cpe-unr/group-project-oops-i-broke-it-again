#ifndef WAV_FINDER_COMMAND_H
#define WAV_FINDER_COMMAND_H

#include "../cli/Command.h"
#include "../cli/CommandHandler.h"
#include <vector>
#include <string>

class WavFinderCommand: public Command {

public:
    WavFinderCommand(CommandHandler* commandHandler);
    
    void execute(std::vector<std::string> args) override;

    // virtual ~WavFinderCommand() {}
};

#endif