#ifndef PARSER_HPP
#define PARSER_HPP

#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <string>


using namespace std;

/*!
* Der Parser filtert aus einer gegebenen Zeile mit Hilfe eines 
* regulaeren Ausdrucks die inhaltenden Woerter heraus. 
* @author Swen Hutop
* @author Dennis Kluge
*/
class Parser {
	
public:
	/*!
	 * Der Konstruktor fuer die Objektorientierung
	 */
	Parser();

	/*!
	 * Der Destruktor fuer die Objektorientierung
	 */
	~Parser();
	
	/*!	
	*	Eine uebergebene Zeile wird in einzelne Woerter zerlegt, die in einem 
	*	anschlieﬂend zurueckgegebenen Container vector<string> abgelegt werden. Gueltige 
	*	Woerter sind Zeichenketten, die dem regulaeren Ausdruck 
	*	[a-zA-Z_]([a-zA-Z0-9_])* entsprechen.
	*	@param[in] text Zeile, die in gueltige Woerter zerlegt werden soll
	*	@returns die gueltigen Woerter der Zeile in einem Vektor
	*/
	vector<string> parseInputLine(string const text);
};

#endif