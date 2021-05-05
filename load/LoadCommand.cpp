#include "LoadCommand.h"
#include "../cli/Command.h"
#include <iostream>
#include <string>

LoadCommand::LoadCommand(WavLoader* wavLoader): Command("load"), wavLoader(wavLoader) {};

void LoadCommand::execute(std::vector<std::string> args) {
    
    if (args.size() == 0) {
        std::cout << "Please provide a file arg." << std::endl;
        return;
    }

    std::string dirPath = args.at(0);
    wavLoader->load(dirPath);
}
