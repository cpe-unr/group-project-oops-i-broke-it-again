#include "ProcessCommand.h"
#include "../processor.h"
#include "../cli/Command.h"
#include "../wav-store/WavStore.h"
#include "../Wav.h"
#include <iostream>
#include <stdexcept>
#include <fstream>

ProcessCommand::ProcessCommand(std::vector<IProcessable*> proccesses, WavStore* wavStore): 
    Command("process"), 
    proccesses(proccesses), 
    wavStore(wavStore) {};

void ProcessCommand::execute(std::vector<std::string> args) {

    if (args.size() < 2) {
        std::cout << "Invalid use of process command." << std::endl;
        return;
    }

    if (wavStore->getWavs().size() == 0) {
        std::cout << "No wav files loaded. Please use load command first." << std::endl;
        return;
    }

    std::string fileToProcess = args.at(0);
    std::string outputFileName = args.at(1);
    std::vector<std::string> processArgs(args.begin() + 2, args.end());
    
    try {
        Wav* wav = wavStore->getWavByFileName(fileToProcess);
        processWav(processArgs, wav);
        saveWavToFile(wav, outputFileName);
    } catch(std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}

void ProcessCommand::processWav(std::vector<std::string>processArgs, Wav* wav) {
    IProcessable* noiseGate = proccesses.at(0);
    IProcessable* normalizer = proccesses.at(1);
    IProcessable* echo = proccesses.at(2);

    for (auto processArg : processArgs) {
        if (processArg == "noisegate") {
            noiseGate->processBuffer(
                wav->getBuffer(),
                wav->getBufferSize(),
                wav->getbitDepth(),
                wav->getnumChannels()
            );
        } else if (processArg == "normalizer") {
            normalizer->processBuffer(
                wav->getBuffer(),
                wav->getBufferSize(),
                wav->getbitDepth(),
                wav->getnumChannels()
            );
        } else if (processArg == "echo") {
            std::cout << "hi: " << wav->getBufferSize() << std::endl;
            echo->processBuffer(
                wav->getBuffer(),
                wav->getBufferSize(),
                wav->getbitDepth(),
                wav->getnumChannels()
            );
        }
    }
}

void ProcessCommand::saveWavToFile(Wav* wav, std::string outputFileName) {
    // check if file exists already. don't want to blindly overwrite.
    bool fileExists = std::ifstream(outputFileName.c_str()).good();
    if (!fileExists) {
        wav->writeFile(outputFileName);
    } else {
        std::cout << "File already exists." << std::endl;
    }
}