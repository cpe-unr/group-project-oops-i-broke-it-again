/** @file */
#include "WavFinder/WavFinder.h"
#include "cli/CommandParser.h"
#include <string>
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

int main() {
    std::string input = "";
    WavFinder* wavFinder = new WavFinder();

    std::cout << "Welcome to Audioprocessor CLI!\n\n" <<
    "Commands:\n" << 
    "    load [file directory]\n" <<
    "    process [file name] [output file name] [processors...]\n" <<
    "    edit-meta [file name] [meta data type] your new meta data value\n"<<
    std::endl;

    while(input.find("exit")) {
        std::getline(std::cin, input);
        
        CommandParser parser = CommandParser(wavFinder);
        parser.parse(input);
        auto a = parser.getArgs();
        parser.getCommand()->execute(parser.getArgs());
    }
}
