#ifndef EDIT_META_COMMAND_H
#define EDIT_META_COMMAND_H

#include "../cli/Command.h"
#include "../wav-store/WavStore.h"

class EditMetaCommand: public Command {
    WavStore* wavStore;
public:
    EditMetaCommand(WavStore* wavStore);
    void execute(std::vector<std::string> args) override;
};

#endif