#ifndef PROCCESS_COMMAND_H
#define PROCCESS_COMMAND_H

#include "../cli/Command.h"
#include "../cli/CommandHandler.h"
#include "../processor.h"
#include "../WavFinder/WavFinder.h"
#include "../Wav.h"
#include <vector>
#include <string>

class ProcessCommand: public Command {
    std::vector<IProcessable*> proccesses;
    WavFinder* wavFinder;

public:
    ProcessCommand(std::vector<IProcessable*> proccesses, WavFinder* wavFinder);
    void execute(std::vector<std::string> args) override;
    void processWav(std::vector<std::string>processArgs, Wav* wav);
    void saveWavToFile(Wav* wav, std::string outputFileName);
};

#endif
