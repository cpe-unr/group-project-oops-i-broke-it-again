#ifndef PROCESS_COMMAND_HANDLER_H
#define PROCESS_COMMAND_HANDLER_H

#include "../cli/CommandHandler.h"
#include "../processor.h"
#include "../WavFinder/WavFinder.h"
#include <vector>
#include <string>

class ProcessCommandHandler: public CommandHandler {
    std::vector<IProcessable*> proccesses;
    WavFinder* wavFinder;

public:
    ProcessCommandHandler(std::vector<IProcessable*> proccesses, WavFinder* wavFinder);
    void handle(std::vector<std::string> args) override;
};

#endif