#include "Command.h"
#include "CommandHandler.h"
#include <string>

Command::Command(std::string name, CommandHandler* commandHandler): 
name(name), 
commandHandler(commandHandler) {}