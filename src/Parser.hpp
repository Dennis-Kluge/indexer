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
* regul�ren Ausdrucks die inhaltenden W�rter heraus. 
* @author Swen Hutop
* @author Dennis Kluge
*/
class Parser {
	
public:
	/*!
	 * Der Konstruktor f�r die Objektorientierung
	 */
	Parser();

	/*!
	 * Der Destruktor f�r die Objektorientierung
	 */
	~Parser();
	
	/*!	
	*	Eine �bergebene Zeile wird in einzelne W�rter zerlegt, die in einem 
	*	anschlie�end zur�ckgegebenen Container vector<string> abgelegt werden. G�ltige 
	*	W�rter sind Zeichenketten, die dem regul�ren Ausdruck 
	*	[a-zA-Z_]([a-zA-Z0-9_])* entsprechen.
	*	@param[in] text Zeile, die in g�ltige W�rter zerlegt werden soll
	*	@returns die g�ltigen W�rter der Zeile in einem Vektor
	*/
	vector<string> parseInputLine(string const text);
};

#endif