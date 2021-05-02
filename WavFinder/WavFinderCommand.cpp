#include "WavFinderCommand.h"
#include <iostream>
#include "../cli/Command.h"

WavFinderCommand::WavFinderCommand(CommandHandler* commandHandler): Command("hi", commandHandler) {};

void WavFinderCommand::execute(std::vector<std::string> args) {
    
    if (args.size() == 0) {
        std::cout << "please provide file arg.";
        return;
    }

    commandHandler->handle(args);
}
