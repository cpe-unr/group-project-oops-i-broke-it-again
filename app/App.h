#include "../wav-store/WavStore.h"
#include "../export/Exporter.h"
#include <string>

/**
 * The container class for running the auidoprocessor app.
 * @author Garrett Weinert
 * @date 5/4/2021
 */
class App {
    WavStore* wavStore;
    Exporter* exporter;
    
    void setup();
    void printWelcome() const;
    void executeInput(std::string input);

public:

    /**
     *  Runs the the auidoprocessor app.
     */
    void run();
};