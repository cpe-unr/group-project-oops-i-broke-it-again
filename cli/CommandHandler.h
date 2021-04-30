#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <vector>
#include <string>

class CommandHandler {
public:
    virtual void handle(std::vector<std::string> args) = 0;
};

#endif