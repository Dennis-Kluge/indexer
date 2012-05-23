#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "FileIndexer.hpp"
#include "Timer.hpp"
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
	 * Stößt die die Generierung des Indexes an und überwacht die Eingabe
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
    * Objekt zum messen der Zeit.
    */
	Timer timer;

	/*!
	 * Gibt die Benutzung des Programms aus. 
	 */
	void printUsage();

	/*!
	 * Gibt einen Vector mit dem geparsten Befehl und den dazugehörigen Parametern. 
	 */
	vector<string> commandParser();

	/*!
	 * Ruft den FileIndexer zum generieren des Indexes auf. 
	 */
	MyMap generateIndex(string inputFile);


    /*!
    * Schreibt den Index unter dem spezifizierten Dateinamen
    * @param indexMap Der Index
    */
	void printResult(MyMap indexMap);

    /*!
    * Gibt den Index für ein spezifiziertes Wort an wenn 
    * dies einmal vorhanden ist
    * @param word Das gesuchte Wort
    * @param indexMap Der Index
    */
    void printWordIndex(string word, MyMap indexMap);  

    /*!
    * Gibt den Index für ein spezifiziertes Wort an wenn 
    * dies mehrmals vorhanden ist
    * @param word Das gesuchte Wort
    * @param indexMap Der Index
    */
    void printWordsIndexes(string word, MyMap indexMap);    

 	/*!
    * Gibt die Positionen für einen Vector von Entries aus.
    * @param v Ein Vector von Entries
    */
    void printPositionVector(vector<Entry> v);
};

#endif