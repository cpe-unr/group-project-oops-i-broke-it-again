#ifndef EXPORTER_H
#define EXPORTER_H

#include <string>

class Exporter {
public:
    virtual void exportFile(std::string outputFileName) = 0;
};

#endif