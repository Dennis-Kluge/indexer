#include <string>

using namespace std;

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
	 * \param[in] a der erste String
	 * \param[in] b der zweite String
	 * \returns ob string a lexikographisch kleiner ist, als string b
	 */
	bool operator() (string, string);
	static bool compare(char, char);
};
