#ifndef EXPORT_COMMAND_H
#define EXPORT_COMMAND_H

#include "../cli/Command.h"
#include "Exporter.h"

/**
 * Command that calls the injected exporter when executed.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class ExportCommand : public Command {
    Exporter* exporter;

public:
    ExportCommand(Exporter* exporter);

    /**
     * Parses the given arguments and calls the exporter to export the wav files.
     * @param args - vector<string> of user input command arguments used to name the created CSV file.
     */
    void execute(std::vector<std::string> args) override;
};

#endif