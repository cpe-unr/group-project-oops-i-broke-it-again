#ifndef EDIT_META_COMMAND_H
#define EDIT_META_COMMAND_H

#include "../cli/Command.h"
#include "../WavFinder/WavFinder.h"

class EditMetaCommand: public Command {
    WavFinder* wavFinder;
public:
    EditMetaCommand(WavFinder* wavFinder);
    void execute(std::vector<std::string> args) override;
};

#endif