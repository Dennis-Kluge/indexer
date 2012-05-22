#ifndef TIMER
#define TIMER

#include <time.h>

class Timer {
    private:	
		long sartTime;

    public:

        Timer();

		void start();

		double stop();
};

#endif
