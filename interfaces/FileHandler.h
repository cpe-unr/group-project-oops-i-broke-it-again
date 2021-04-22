#include <vector>
#include <string>

class FileHandler {
    virtual std::vector<std::string> getFiles() = 0;
};