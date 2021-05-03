#include "ProcessCommand.h"
#include "../processor.h"
#include "../WavFinder/WavFinder.h"
#include "../cli/Command.h"
#include "../Wav.h"
#include <iostream>
#include <stdexcept>
#include <fstream>

ProcessCommand::ProcessCommand(std::vector<IProcessable*> proccesses, WavFinder* wavFinder): 
    Command("hi", nullptr), 
    proccesses(proccesses), 
    wavFinder(wavFinder) {};

void ProcessCommand::execute(std::vector<std::string> args) {

    if (args.size() < 2) {
        std::cout << "Command should be used like: process filename process1 process2";
    }

    std::vector<std::string> files = wavFinder->getFiles();

    if (files.size() == 0) {
        std::cout << "No files loaded. Please use load first." << std::endl;
    }

    std::string fileToProcess = args.at(0);
    std::string outputFileName = args.at(1);
    std::vector<std::string> processArgs(args.begin() + 2, args.end());
    
    try {
        Wav* wav = wavFinder->getWavFromFileName(fileToProcess);
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
        std::cout << "file already exists." << std::endl;
    }
}