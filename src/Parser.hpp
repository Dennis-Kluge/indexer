
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

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
		Zerlegen einer übergebenen Zeile aus Eingabedatei
		Eine übergebene Zeile wird in einzelne Wörter zerlegt, die in einem 
		anschließend zurückgegebenen Container vector<string> abgelegt werden. Gültige 
		Wörter sind Zeichenketten, die dem regulären Ausdruck 
		[a-zA-Z|_]([a-zA-Z0-9|-|_])* entsprechen.
		@param[in] text Zeile, die in gültige Wörter zerlegt werden soll
		@returns die gültigen Wörter der Zeile in einem Vektor
		*/
	vector<string> parse_input_line(string const text);
};


