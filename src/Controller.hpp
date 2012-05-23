
#include "FileIndexer.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Controller
{

public:
	/*!
	 * Der Konstruktor für die Objektorientierung
	 */
	Controller();

	/*!
	 * Der Destruktor für die Objektorientierung
	 */
	~Controller();
	
	int run_indexer(int argc, char* argv[]);
	void writeIndexFile(string outputFile, MyMap index);
};