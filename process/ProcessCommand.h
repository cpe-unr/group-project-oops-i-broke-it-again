#ifndef PROCCESS_COMMAND_H
#define PROCCESS_COMMAND_H

#include "../cli/Command.h"
#include "../cli/CommandHandler.h"
#include <vector>
#include <string>

class ProcessCommand: public Command {
public:
    ProcessCommand(CommandHandler* commandHandler);
    void execute(std::vector<std::string> args) override;
};

#endif
