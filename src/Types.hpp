#ifndef TYPES_HPP
#define TYPES_HPP

#include <set>
#include <map>
#include <string>
#include <vector>
#include "LexComparator.hpp"

using namespace std;


/*!
* Deklaration der Datenstruktur des Indexers.
* @author Swen Hutop
* @author Dennis Kluge
*/

/*!
* Ein Entry besteht aus einem Pair von ints
*/
typedef pair<int, int> Entry;

/*!
* Der Index besteht aus eine Map deren Key das Wort und als Value 
* ein vector von Entries genutzt wird. 
* Die Sortierung uebernimmt der LexComparator 
*/
typedef map<string, vector<Entry>, LexComparator> MyMap;

#endif


