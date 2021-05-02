#include "EditMetaCommand.h"
#include "../cli/Command.h"
#include <iostream>
#include <stdexcept>

EditMetaCommand::EditMetaCommand(WavFinder* wavFinder): 
    wavFinder(wavFinder),
    Command("hi", nullptr) {}

void EditMetaCommand::execute(std::vector<std::string> args) {
    if (args.size() < 3) {
        std::cout << "Command should be used like: editmeta filename song \"my new song name\"";
    }

    std::string fileName = args.at(0);
    std::string metaDataName = args.at(1);
    std::string newMetaData;
    for (auto i = args.begin() + 2; i != args.end(); ++i) {
        newMetaData += *i;
    }

    try {
        Wav* wav = wavFinder->getWavFromFileName(fileName);
        
        if (metaDataName == "song") {
            wav->setSongName(newMetaData);
        } else if (metaDataName == "artist") {
            wav->setArtist(newMetaData);
        } else {
            std::cout << "Invalid metadata option." << std::endl;
        }

        wav->writeFile(wavFinder->getFullPath(fileName));

    } catch(std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}