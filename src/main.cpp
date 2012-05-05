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

using namespace std;

/*!
 * Einstiegspunkt in das Programm.
 * \param[in] argc Anzahl der Kommandozeilenparameter
 * \param[in] argv die eigentlichen Kommandozeilenparameter
 */
int main(int argc, char* argv[]) {
	// Controller c;
	// return c.run_app(argc, argv);
	char filename[] = "text.txt" ;
	FileIndexer indexer(filename);
	indexer.IndexFile();
	indexer.PrintResult();
}
