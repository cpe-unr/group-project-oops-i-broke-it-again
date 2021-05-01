#include "ProcessCommandHandler.h"
#include "../WavFinder/WavFinder.h"
#include "../processor.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

ProcessCommandHandler::ProcessCommandHandler(
    std::vector<IProcessable*> proccesses,
    WavFinder* wavFinder
):
    proccesses(proccesses), wavFinder(wavFinder) {}

void ProcessCommandHandler::handle(std::vector<std::string> args) {
    std::vector<std::string> files = wavFinder->getFiles();

    if (files.size() == 0) {
        std::cout << "No files loaded. Please use load first." << std::endl;
    }

    Wav* wav;
    std::string fileToProcess = args.at(0);
    std::string outputFileName = args.at(1);
    std::vector<std::string> processArgs(args.begin() + 2, args.end());
    
    try {
        wav = wavFinder->getWavFromFileName(fileToProcess);
    } catch(std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        return;
    }
    
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
            echo->processBuffer(
                wav->getBuffer(),
                wav->getBufferSize(),
                wav->getbitDepth(),
                wav->getnumChannels()
            );
        }
    }

    // check if file exists already. don't want to blindly overwrite.
    bool fileExists = std::ifstream(outputFileName.c_str()).good();
    if (!fileExists) {
        
    } else {
        std::cout << "file already exists." << std::endl;
    }
    
    
}