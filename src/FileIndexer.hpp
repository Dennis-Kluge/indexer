#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>


using namespace std ;

class FileIndexer
{

    public:
    	FileIndexer(char file[]);
    	map<string, vector<string> > IndexFile();
    	void PrintResult(map<string, vector<string> >  mmap);
    	void PrintResult();

    private:
    	fstream stream;
    	string content;
    	char *mFile;
    	typedef map<string, vector<string> > MyMap;
    	MyMap indexMap;
    	FileIndexer() {}

} ;

