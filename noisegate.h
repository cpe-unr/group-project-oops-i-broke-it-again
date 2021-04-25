#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "processor.h"

class NoiseGate : public IProcessable {
	double threshold;

	public:
		NoiseGate(double threshold);

		void processBuffer(unsigned char* buffer, int bufferSize) override;

};

#endif
