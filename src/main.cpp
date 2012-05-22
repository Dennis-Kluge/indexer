/*! \mainpage Indexer: Erstellung und Benutzung eines assoziativen Indexes fuer Programmtexte
 *	Die Anwendung Indexer erstellt einen Index f¸r gegebene Programmtexte und kann diese 
 *	Indexdateien wieder einlesen. Des weiteren sind die Ausgabe des gesamten Index sowie 
 *	Anfragen an diesen mˆglich.
 *	Das Programm kann mit den folgenden Kommandozeilenparametern gestartet werden:\n
 *	\n
 *	\c <program> <inputfile> <outputfile> \n
 *	\c <program> : Programmname\n
 *	\c <inputfile> : Programmname\n
 *	\c -p Ausgabe der Indexliste am Terminal\n
 *	\c   -i Erstellen des Indexes\n
 *	\c   -q=<wort> : Ausgeben des vollständigen Indexes zum Wort wort am Terminal\n
 *	\c   -s=<wortanfang> : Ausgeben des vollständigen Indexes zu allen Wˆrtern mit dem Wortanfang wortanfang am Terminal\n
 *	\c   -t=<dateiname> : Ausgeben der Indizes zu allen Wˆrtern, die in der Datei dateiname vorkommen, am Terminal\n
 *	\c <outputfile> : Dateiname der Ausgabedatei mit der Indexliste\n
 *	\c <inputfile>* : Liste von Eingabedateien mit zu indizierendem Text\n
 *	
 *	\section Aufrufdiagramm
 *	 \image html callgraph.jpg "Indexer Aufrufdiagramm"
 *	 \image latex callgraph.eps "Indexer Aufrufdiagramm"
 *
 * \author Dennis Kluge
 * \author Swen Hutop
 * 
 */

/*!
 * \file main.cpp
 */

//#include "controller.h"
#include "FileIndexer.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*!
 * Einstiegspunkt in das Programm.
 * \param[in] argc Anzahl der Kommandozeilenparameter
 * \param[in] argv die eigentlichen Kommandozeilenparameter
 */
int main(int argc, char* argv[]) {
	// Controller c;
	// return c.run_app(argc, argv);
	char filename[] = "Testdaten/Test3.c" ;
	FileIndexer indexer(filename);
	indexer.IndexFile();
	indexer.PrintResult();
	string c;
	string word;
	bool input = true;
	while(input) 
	{
		cout << "Befehl eingeben: " ; 
		string line;
		getline(cin,line);
		istringstream iss(line);
		vector<string> com ;
		do
		{
			string sub;
			iss >> sub;
			com.push_back(sub);
		} while (iss);
		if(com.size() > 3) {
			cout << "Sie haben zu viele Befehle/Wörter angegeben" << endl;
		}
		if(com.size() >= 1 && com.size() <= 3) {
			if(com[0] == "w!") {
				indexer.PrintWordIndex(com[1]);
			} else if(com[0] == "a!") {
				indexer.PrintWordsIndexes(com[1]);
			} else if(com[0] == "q!") {
				return EXIT_SUCCESS ;				
			} else {
				cout << "Befehl nicht bekannt!" << endl;
			}
		}
		
	}

	return EXIT_SUCCESS ;
}
