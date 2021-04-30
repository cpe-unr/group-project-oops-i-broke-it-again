#include "WavFinderCommand.h"
#include <iostream>
#include "../cli/Command.h"

WavFinderCommand::WavFinderCommand(CommandHandler* commandHandler): Command("hi", commandHandler) {};

void WavFinderCommand::execute(std::vector<std::string> args) {
    std::cout << "avFinderCommand::execute" << std::endl;

    for(auto a : args) {
        std::cout << "arg: " << a << std::endl;
    }

    // if (args.size() == 0) {
    //     std::cout << "please provide file arg.";
    // }

    commandHandler->handle(args);

}

// WavFinderCommand::~WavFinderCommand() {}