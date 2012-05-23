#ifndef FILEINDEXER_HPP
#define FILEINDEXER_HPP

#include "Types.hpp"
#include "Parser.hpp"

#include <cstdlib>
#include <string>
#include <map>
#include <iostream>
#include <fstream>

using namespace std ;
/*!
 * Diese Klasse erstellt aus einer Eingabedaetei einen dazugehoerigen
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
        * Indiziert die spezifizierte Datei und 
        * gibt den generierten Index zurueck.
        * @return Der generierte Index
        */
    	MyMap indexFile();
  
        
    private:

        /*!
        * Name der zu indexierenden Datei
        */
    	string mFile;

       
};

#endif