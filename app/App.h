#include "../WavFinder/WavFinder.h"
#include "../export/Exporter.h"
#include <string>

class App {
    WavFinder* wavFinder;
    Exporter* exporter;
    
    void setup();
    void printWelcome() const;
    void executeInput(std::string input);

public:
    void run();
};