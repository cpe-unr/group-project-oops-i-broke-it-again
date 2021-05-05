#ifndef EDIT_META_COMMAND_H
#define EDIT_META_COMMAND_H

#include "../cli/Command.h"
#include "../wav-store/WavStore.h"

/**
 * A command class that when executed will mutate the meta data of an wav file.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class EditMetaCommand: public Command {
    WavStore* wavStore;
public:
    EditMetaCommand(WavStore* wavStore);

    /**
     * Exucute will update the specified meta data field of a wav file.
     * @param args - vector<string> of the file, meta data field to edit, and value of meta data.
     */
    void execute(std::vector<std::string> args) override;
};

#endif