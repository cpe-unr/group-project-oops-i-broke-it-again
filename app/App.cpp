#include "App.h"
#include "../wav-store/WavStore.h"
#include "../export/CsvExporter.h"
#include "../export/Exporter.h"
#include "../cli/CommandParser.h"
#include "../cli/Command.h"
#include <vector>
#include <string>
#include <iostream>

void App::run() {
    setup();
    printWelcome();

    std::string input = "";
    while(true) {
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        
        executeInput(input);
    }
}

void App::setup() {
    wavStore = new WavStore();
    exporter = new CsvExporter(wavStore);
}

void App::printWelcome() const {
    std::cout << "Welcome to Audioprocessor CLI!\n\n" <<
    "Commands:\n" << 
    "    load [file directory]\n" <<
    "    process [file name] [output file name] [processors...]\n" <<
    "    edit-meta [file name] [meta data type] your new meta data value\n" <<
    "    export [output file name]\n" <<
    "    exit\n" <<
    std::endl;
}

void App::executeInput(std::string input) {
    // TODO: Look into why we need a new parser for every input. Breaks export. File never created.
    CommandParser parser(wavStore, exporter);
    
    parser.parse(input);
    Command* command = parser.getCommand();

    if (command != nullptr) {
        command->execute(parser.getArgs());
    } else {
        std::cout << "Invalid command." << std::endl;
    }
}