#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "FileIndexer.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;
/*!
 * Die Controller-Klasse dient als Einstiegspunkt zur Generierung des Indexes 
 * und Verarbeitung der Kommandozeilenparameter.
 * \author Swen Hutop
 * \author Dennis Kluge
 */
class Controller {

public:
	/*!
	 * Standardkonstruktor
	 */
	Controller();

	/*!
	 * Destruktor der Klasse
	 */
	~Controller();
	
	/*!
	 * Destruktor der Klasse
	 * \param[in] argc Die Anzahl der Kommandozeilenparameter
	 * \param[in] argv Die Kommandozeilenoptionen
	 */
	int runIndexer(int argc, char* argv[]);

	/*!
	 * Schreibt den Index in das Output File
	 * \param[in] outputFile Name der Ausgabedatei
	 * \param[in] index Der erstellte Wortindex
	 */
	void writeIndexFile(string outputFile, MyMap index);

private:
	/*!
	 * Gibt die Benutzung des Programms aus. 
	 */
	void printUsage();
};

#endif