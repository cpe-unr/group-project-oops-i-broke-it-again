#include "ProcessCommand.h"
#include <iostream>
#include "../cli/Command.h"

ProcessCommand::ProcessCommand(CommandHandler* commandHandler): Command("hi", commandHandler) {};

void ProcessCommand::execute(std::vector<std::string> args) {

    if (args.size() < 2) {
        std::cout << "Command should be used like: process filename process1 process2";
    }

    commandHandler->handle(args);
}
