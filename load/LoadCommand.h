#ifndef WAV_FINDER_COMMAND_H
#define WAV_FINDER_COMMAND_H

#include "../cli/Command.h"
#include "WavLoader.h"
#include <vector>
#include <string>

/**
 * Command used to facilitate loading of wav files.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class LoadCommand: public Command {
    WavLoader* wavLoader;

public:
    LoadCommand(WavLoader* wavLoader);
    
     /**
     * Parses the given arguments and calls the loader to load wav files
     * @param args - vector<string> of user input command arguments used to load wav files.
     */
    void execute(std::vector<std::string> args) override;
};

#endif