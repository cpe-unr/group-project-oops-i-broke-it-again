#include "Command.h"
#include <string>

/**
 * An interface for a runnable cli command. 
 * @author Garrett Weinert
 * @date 5/4/2021
 */
Command::Command(std::string name): 
name(name) {}