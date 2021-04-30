audioprocessor: main.cpp WavFinder.o Command.o WavFinderCommand.o
	g++ -std=c++11 main.cpp WavFinder.o Command.o WavFinderCommand.o -o audioprocessor

Command.o: cli/Command.cpp cli/Command.h
	g++ -c -std=c++11 cli/Command.cpp

WavFinderCommand.o: cli/Command.h cli/Command.cpp WavFinder/WavFinderCommand.h WavFinder/WavFinderCommand.cpp
	g++ -c -std=c++11 cli/Command.cpp WavFinder/WavFinderCommand.cpp

WavFinder.o: WavFinder/WavFinder.cpp WavFinder/WavFinder.h cli/Command.h WavFinder/WavFinderCommand.h interfaces/FileHandler.h
	g++ -c -std=c++11 WavFinder/WavFinder.cpp

processor.o: processor.h processor.cpp
	g++ -c -std=c++11 processor.cpp

echo.o: echo.h echo.cpp
	g++ -c -std=c++11 echo.cpp

noisegate.o: noisegate.h noisegate.cpp
	g++ -c -std=c++11 noisegate.cpp

normalize.o: normalize.h normalize.cpp
	g++ -c -std=c++11 normalize.cpp

Wav.o: Wav.h Wav.cpp
	g++ -c -std=c++11 Wav.cpp

WavLib.a: Wav.o
	ar suvr WavLib.a Wav.o

clean:
	rm *.o audioprocessor
