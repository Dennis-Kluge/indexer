
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

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
		Zerlegen einer �bergebenen Zeile aus Eingabedatei
		Eine �bergebene Zeile wird in einzelne W�rter zerlegt, die in einem 
		anschlie�end zur�ckgegebenen Container vector<string> abgelegt werden. G�ltige 
		W�rter sind Zeichenketten, die dem regul�ren Ausdruck 
		[a-zA-Z|_]([a-zA-Z0-9|-|_])* entsprechen.
		@param[in] text Zeile, die in g�ltige W�rter zerlegt werden soll
		@returns die g�ltigen W�rter der Zeile in einem Vektor
		*/
	vector<string> parse_input_line(string const text);
};


