#ifndef LEXCOMPERATOR_HPP
#define LEXCOMPERATOR_HPP

#include <string>
#include <iostream>

using namespace std;

/*!
 * Der LexComparator vergleicht zwei Woerter nach lexikographischer 
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
	 * Der Operator () fuehrt hier einen lexikographischen Wortvergleich
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