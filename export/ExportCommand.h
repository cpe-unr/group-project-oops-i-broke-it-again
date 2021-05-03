#ifndef EXPORT_COMMAND_H
#define EXPORT_COMMAND_H

#include "../cli/Command.h"
#include "Exporter.h"

class ExportCommand : public Command {
    Exporter* exporter;

public:
    ExportCommand(Exporter* exporter);
    void execute(std::vector<std::string> args) override;
};

#endif