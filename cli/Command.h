#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

class Command {
    std::string name;

public:
    Command(std::string name);
    
    virtual void execute(std::vector<std::string> args) = 0;
    
    virtual ~Command() {};
};

#endif
