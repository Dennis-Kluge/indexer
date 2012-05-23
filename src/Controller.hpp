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
 * @author Swen Hutop
 * @author Dennis Kluge
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
	 * Stoeßt die Generierung des Indexes an und ueberwacht die Eingabe
	 * @param argc Die Anzahl der Kommandozeilenparameter
	 * @param argv Die Kommandozeilenoptionen
	 */
	int runIndexer(int argc, char* argv[]);

	/*!
	 * Schreibt den Index in das Output File
	 * @param outputFile Name der Ausgabedatei
	 * @param index Der erstellte Wortindex
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
	 * Gibt einen Vector mit dem geparsten Befehl und den dazugehoerigen Parametern. 
	 * @return Vercotr mit Befehl und Parametern 
	 */
	vector<string> commandParser();

	/*!
	 * Ruft den FileIndexer zum generieren des Indexes auf. 
	 * @return Der genrierte Index
	 */
	MyMap generateIndex(string inputFile);


    /*!
    * Schreibt den Index unter dem spezifizierten Dateinamen
    * @param indexMap Der Index
    */
	void printResult(MyMap indexMap);

    /*!
    * Gibt den Index fuer ein spezifiziertes Wort an wenn 
    * dies einmal vorhanden ist
    * @param word Das gesuchte Wort
    * @param indexMap Der Index
    */
    void printWordIndex(string word, MyMap indexMap);  

    /*!
    * Gibt den Index fuer ein spezifiziertes Wort an wenn 
    * dies mehrmals vorhanden ist
    * @param word Das gesuchte Wort
    * @param indexMap Der Index
    */
    void printWordsIndexes(string word, MyMap indexMap);    

 	/*!
    * Gibt die Positionen fuer einen Vector von Entries aus.
    * @param v Ein Vector von Entries
    */
    void printPositionVector(vector<Entry> v);
};

#endif