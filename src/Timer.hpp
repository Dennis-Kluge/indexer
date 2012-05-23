#ifndef TIMER_HPP
#define TIMER_HPP

#include <time.h>

/*!
* Der Timer berechnet die Ausfuehrzeit zwischen dem 
* Start- und Endzeitpunkt.
* @author Swen Hutop
* @author Dennis Kluge
*/
class Timer {
private:	
	/*!
	* Die Startzeit
	*/	
	long startTime;

public:

	/*!
	* Der Konstruktor
	*/	
	Timer();

	/*!
	* Startet die Messung.
	*/	
	void start();

	/*!
	* Beendet die Messung und gibt das Ergebnis in
	* Sekunden zurueck. 
	* @return Die Ausfuehrzeit in Sekunden
	*/	
	double stop();
};

#endif
