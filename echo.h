#ifndef ECHO_H
#define ECHO_H
#include "processor.h"


class Echo : public IProcessable {
	int delay;

	public:
		Echo(int delay);

		void processBuffer(unsigned char* buffer, int bufferSize, int bitDepth, int numChannels) override;

};
#endif
