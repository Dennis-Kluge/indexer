/*! @mainpage Indexer: Das Programm erstellt einen lexikographisch 
 *  sortierten Index einer Eingabedatei und schreibt diese ebenfalls
 *  in eine Datei. Zusätzlich erfolgt die Bedienung über interaktive 
 *  Kommandos um einzelne Wörter und deren Positionen zu finden.
 * 
 *  Das Programm wird wie folg bedient: \n
 *	\n
 *	\c indexer <inputfile> <outputfile> \n
 *	\c <inputfile>  : Die Datei für die der Index erstellt werden soll\n
 *	\c <outputfile> : Der Name Datei die den Index enthält\n
 *  \n
 *	\c Interaktive Kommandos: \n
 *  \c w! <Wort> Gib den Index zum Wort <Wort> aus. \n
 *  \c a! <Wortanfang> Gib die Indizes zu allen Woertern aus, die den Wortanfang <Wortanfang> besitzen. \n
 *  \c q! Beende das Programm. \n
 *
 * @author Swen Hutop
 * @author Dennis Kluge 
 */

#include "Controller.hpp"

using namespace std;

/*!
 * Haupteinstiegspunkt des Indexers
 * @param argc Anzahl der Kommandozeilenparameter
 * @param argv die eigentlichen Kommandozeilenparameter
 */
int main(int argc, char* argv[]) {
	 Controller c;
	 return c.runIndexer(argc, argv);
}
