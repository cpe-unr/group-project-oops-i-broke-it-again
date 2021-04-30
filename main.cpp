/** @file */
#include "WavFinder/WavFinder.h"
#include "WavFinder/WavFinderCommand.h"
#include "cli/Command.h"
#include <string>
#include <sstream>
#include <iostream>

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */
void fn(){

}

std::vector<std::string> parse(std::string command);
Command* getCommand(std::string input);

int main() {
    std::string input = "";
    std::vector<std::string> inputs;

    while(input != "exit") {
        std::string s;
        std::getline(std::cin, s);
        inputs = parse(s);
        std::string scommand = inputs.at(0);
        std::vector<std::string> args(inputs.begin() + 1, inputs.end());
        
        Command* command = getCommand(scommand);
        command->execute(args);
    }
}

Command* getCommand(std::string input) {
    std::cout << "getCommand" << input << std::endl;
    if (input == "load") {
        return new WavFinderCommand(new WavFinder());
    }
}

std::vector<std::string> parse(std::string command) {
    std::vector<std::string> tokenized;

    std::string tmp;
    std::stringstream ss(command);
    while(getline(ss, tmp, ' ')) {
        tokenized.push_back(tmp);
    }

    return tokenized;
}
