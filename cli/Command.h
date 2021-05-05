#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

/**
 * An interface to be with a class to make them "executable".
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class Command {
    std::string name;

public:
    Command(std::string name);
    
    virtual void execute(std::vector<std::string> args) = 0;
    
    virtual ~Command() {};
};

#endif
