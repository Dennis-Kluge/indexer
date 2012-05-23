#ifndef LEXCOMPERATOR_HPP
#define LEXCOMPERATORHPP

#include <string>

using namespace std;

/*!
 * Der LexComparator vergleicht zwei Wörter nach lexikographischer 
 * Sortierung miteinander. 
 *
 * @author Swen Hutop
 * @author Dennis Kluge
 */
class LexComparator {

public:
	/*!
	 * Konstruktor 
	 */
	LexComparator();
	/*!
	 * Destruktor 
	 */
	~LexComparator();

	/*!
	 * Der Operator () führt hier einen lexikographischen Wortvergleich
	 * zweier Strings durch.
	 * @param a der erste String
	 * @param b der zweite String
	 * @return Ob a kleiner ist als b
	 */
	bool operator() (string, string);

	/*!
	 * Die Compare-Funktion zum Wortvergleich
	 * @param a der erste String
	 * @param b der zweite String	 
	 */
	static bool compare(char, char);
};

#endif