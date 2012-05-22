#include "Types.h"
#include "Parser.hpp"

#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <algorithm>




using namespace std ;

class FileIndexer
{

    public:
    	FileIndexer(char file[]);
    	MyMap IndexFile();
    	void PrintResult(MyMap  mmap);
    	void PrintResult();
        void PrintWordIndex(string word);
        void PrintWordsIndexes(string word);
        

    private:
    	fstream stream;
    	string content;
    	char *mFile;
    	MyMap indexMap;
    	FileIndexer() {}
        void PrintPositionVector(vector<Entry> v);

} ;

