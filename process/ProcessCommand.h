#ifndef PROCCESS_COMMAND_H
#define PROCCESS_COMMAND_H

#include "../cli/Command.h"
#include "../processor.h"
#include "../wav-store/WavStore.h"
#include "../Wav.h"
#include <vector>
#include <string>

/**
 * Command to facilitate processing of wav files.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class ProcessCommand: public Command {
    std::vector<IProcessable*> proccesses;
    WavStore* wavStore;

    /**
     * Applies all given processes to a wav file.
     * @param processArgs - vector<string> of processes.
     * @param wav - Wav instance to process.
     */
    void processWav(std::vector<std::string>processArgs, Wav* wav);

    /**
     * Saves the wav instance to a new file.
     * @param wav - Wav instance that should be output as a file.
     * @param outputFileName - string of name of new wav file.
     */
    void saveWavToFile(Wav* wav, std::string outputFileName);

public:
    ProcessCommand(std::vector<IProcessable*> proccesses, WavStore* wavStore);

    /**
     * Parses the user input command arguments to correctly process the given wav file.
     * @param args - vector<string> of wav file to process, output file name, and processes.
     */
    void execute(std::vector<std::string> args) override;
};

#endif
