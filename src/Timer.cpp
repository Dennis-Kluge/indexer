#include "Timer.hpp"

Timer::Timer(){
	startTime = 0;
}

void Timer::start(){
	startTime = clock();
}

double Timer::stop(){
	return (clock() - startTime) / (double) CLOCKS_PER_SEC;
}
