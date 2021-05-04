#include "LoadCommand.h"
#include "../cli/Command.h"
#include <iostream>

LoadCommand::LoadCommand(WavLoader* wavLoader): Command("hi", nullptr), wavLoader(wavLoader) {};

void LoadCommand::execute(std::vector<std::string> args) {
    
    if (args.size() == 0) {
        std::cout << "Please provide a file arg." << std::endl;
        return;
    }

    wavLoader->load(args);
}
