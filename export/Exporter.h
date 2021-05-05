#ifndef EXPORTER_H
#define EXPORTER_H

#include <string>

/**
 * Interface that can be used with @see ExportCommand.h to export many types of files.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class Exporter {
public:
    virtual void exportFile(std::string outputFileName) = 0;
};

#endif