#include "../wav-store/WavStore.h"
#include "../export/Exporter.h"
#include <string>

class App {
    WavStore* wavStore;
    Exporter* exporter;
    
    void setup();
    void printWelcome() const;
    void executeInput(std::string input);

public:
    void run();
};