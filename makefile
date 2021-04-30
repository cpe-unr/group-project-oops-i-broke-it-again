audioprocessor: main.cpp WavFinder.o
	g++ -std=c++11 main.cpp WavFinder.o -o audioprocessor

WavFinder.o: WavFinder/WavFinder.cpp WavFinder/WavFinder.h interfaces/FileHandler.h
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
