audioprocessor: main.cpp WavFinder.o
	g++ -std=c++11 main.cpp WavFinder.o -o audioprocessor

WavFinder.o: WavFinder/WavFinder.cpp WavFinder/WavFinder.h interfaces/FileHandler.h
	g++ -c -std=c++11 WavFinder/WavFinder.cpp

clean:
	rm *.o audioprocessor
