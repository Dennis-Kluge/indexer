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
#include <stdio.h>
#include <ctype.h>




using namespace std ;

class FileIndexer
{

    public:
    	FileIndexer(string file);
    	MyMap IndexFile();
    	void PrintResult(MyMap  mmap);
    	void PrintResult();
        void PrintWordIndex(string word);
        void PrintWordsIndexes(string word);
        

    private:
    	fstream stream;
    	string content;
    	string mFile;
    	MyMap indexMap;
    	FileIndexer() {}
        void PrintPositionVector(vector<Entry> v);
} ;

