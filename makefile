audioprocessor: main.cpp App.o Wav.o WavFinder.o Command.o CommandParser.o WavFinderCommand.o ProcessCommand.o EditMetaCommand.o ExportCommand.o CsvExporter.o noisegate.o echo.o normalizer.o
	g++ -std=c++11 main.cpp App.o Wav.o WavFinder.o Command.o CommandParser.o WavFinderCommand.o ProcessCommand.o EditMetaCommand.o ExportCommand.o CsvExporter.o noisegate.o echo.o normalizer.o -o audioprocessor

App.o: app/App.h app/App.cpp
	g++ -c -std=c++11 app/App.cpp

Command.o: cli/Command.cpp cli/Command.h
	g++ -c -std=c++11 cli/Command.cpp

CommandParser.o: cli/CommandParser.cpp cli/CommandParser.h
	g++ -c -std=c++11 cli/CommandParser.cpp

WavFinderCommand.o: cli/Command.h cli/Command.cpp WavFinder/WavFinderCommand.h WavFinder/WavFinderCommand.cpp
	g++ -c -std=c++11 cli/Command.cpp WavFinder/WavFinderCommand.cpp

WavFinder.o: WavFinder/WavFinder.cpp WavFinder/WavFinder.h cli/Command.h WavFinder/WavFinderCommand.h interfaces/FileHandler.h
	g++ -c -std=c++11 WavFinder/WavFinder.cpp

ProcessCommand.o: process/ProcessCommand.h process/ProcessCommand.cpp
	g++ -c -std=c++11 process/ProcessCommand.cpp

EditMetaCommand.o: edit-meta/EditMetaCommand.h edit-meta/EditMetaCommand.cpp
	g++ -c -std=c++11 edit-meta/EditMetaCommand.cpp

ExportCommand.o: export/ExportCommand.h export/ExportCommand.cpp
	g++ -c -std=c++11 export/ExportCommand.cpp

CsvExporter.o: export/CsvExporter.h export/CsvExporter.cpp
	g++ -c -std=c++11 export/CsvExporter.cpp

processor.o: processor.h processor.cpp
	g++ -c -std=c++11 processor.cpp

echo.o: echo.h echo.cpp
	g++ -c -std=c++11 echo.cpp

noisegate.o: noisegate.h noisegate.cpp
	g++ -c -std=c++11 noisegate.cpp

normalizer.o: normalizer.h normalizer.cpp
	g++ -c -std=c++11 normalizer.cpp

Wav.o: Wav.h Wav.cpp
	g++ -c -std=c++11 Wav.cpp

WavLib.a: Wav.o
	ar suvr WavLib.a Wav.o

clean:
	rm *.o audioprocessor
