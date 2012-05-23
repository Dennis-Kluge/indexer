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
* regulären Ausdrucks die inhaltenden Wörter heraus. 
* @author Swen Hutop
* @author Dennis Kluge
*/
class Parser {
	
public:
	/*!
	 * Der Konstruktor für die Objektorientierung
	 */
	Parser();

	/*!
	 * Der Destruktor für die Objektorientierung
	 */
	~Parser();
	
	/*!	
	*	Eine übergebene Zeile wird in einzelne Wörter zerlegt, die in einem 
	*	anschließend zurückgegebenen Container vector<string> abgelegt werden. Gültige 
	*	Wörter sind Zeichenketten, die dem regulären Ausdruck 
	*	[a-zA-Z_]([a-zA-Z0-9_])* entsprechen.
	*	@param[in] text Zeile, die in gültige Wörter zerlegt werden soll
	*	@returns die gültigen Wörter der Zeile in einem Vektor
	*/
	vector<string> parseInputLine(string const text);
};

#endif