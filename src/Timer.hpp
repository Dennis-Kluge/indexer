#ifndef TIMER
#define TIMER

#include <time.h>

class Timer {
    private:	
		long startTime;

    public:

        Timer();

		void start();

		double stop();
};

#endif
