#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <vector>
#include <string>

class FileHandler {
    virtual std::vector<std::string> getFiles() = 0;
};

#endif