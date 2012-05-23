#ifndef FILEINDEXER_HPP
#define FILEINDEXERHPP

#include "Types.h"
#include "Parser.hpp"

#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>

using namespace std ;
/*!
 * Diese Klasse erstellt aus einer Eingabedaetei einen dazugehörigen
 * lexikographisch sortierten Wortindex in der Form:
 * <token> (BLANK ’(’<zeilennummer>’,’<spaltennummer>’)’ )+ .
 *
 * @author Swen Hutop
 * @author Dennis Kluge
 */
class FileIndexer {

    public:
        /*!
        * Konstruktor der Klasse mit dem Namen der zu indizierenden Datei
        * @param file Name der Datei
        */
    	FileIndexer(string file);

        /*!
        * Indiziert die spezifizierte Datei 
        */
    	MyMap IndexFile();

        /*!
        * Schreibt den Index unter dem spezifizierten Dateinamen
        * @param mmap Der Index
        */
    	void PrintResult(MyMap mmap);

        /*!
        * Gibt den Index für ein spezifiziertes Wort an wenn 
        * dies einmal vorhanden ist
        * @param word Das gesuchte Wort
        */
        void PrintWordIndex(string word);  

        /*!
        * Gibt den Index für ein spezifiziertes Wort an wenn 
        * dies mehrmals vorhanden ist
        * @param word Das gesuchte Wort
        */
        void PrintWordsIndexes(string word);      
        
    private:
        /*!
        * File Stream zum einlesen der Datei
        */
    	fstream stream;

        /*!
        * Name der zu schreibenden Datei
        */
    	string mFile;

        /*!
        * Der eigentliche Index
        */
    	MyMap indexMap;

        /*!
        * Gibt die Positionen für einen Vector von Entries aus.
        * @param v Ein Vector von Entries
        */
        void PrintPositionVector(vector<Entry> v);
};

#endif