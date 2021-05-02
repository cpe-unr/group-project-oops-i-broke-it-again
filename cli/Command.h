#ifndef COMMAND_H
#define COMMAND_H

#include "CommandHandler.h"
#include <vector>
#include <string>

class Command {
    std::string name;

public:
    CommandHandler* commandHandler;

    Command(std::string name, CommandHandler* commandHandler);
    
    virtual void execute(std::vector<std::string> args) = 0;
    
    virtual ~Command() {};
};

#endif
