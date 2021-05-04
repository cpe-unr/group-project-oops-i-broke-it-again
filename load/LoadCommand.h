#ifndef WAV_FINDER_COMMAND_H
#define WAV_FINDER_COMMAND_H

#include "../cli/Command.h"
#include "WavLoader.h"
#include <vector>
#include <string>

class LoadCommand: public Command {
    WavLoader* wavLoader;

public:
    LoadCommand(WavLoader* wavLoader);
    
    void execute(std::vector<std::string> args) override;
};

#endif