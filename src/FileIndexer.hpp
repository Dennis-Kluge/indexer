#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>

#include "Types.h"


using namespace std ;

class FileIndexer
{

    public:
    	FileIndexer(char file[]);
    	MyMap IndexFile();
    	void PrintResult(MyMap  mmap);
    	void PrintResult();

    private:
    	fstream stream;
    	string content;
    	char *mFile;
    	MyMap indexMap;
    	FileIndexer() {}

} ;

