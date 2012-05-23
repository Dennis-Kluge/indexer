#include "FileIndexer.hpp" 

using namespace std ;

FileIndexer::FileIndexer(string file) {
	mFile = file;
}



MyMap FileIndexer::IndexFile() {
	ifstream inputStream(mFile.data()) ;
    if (!inputStream) {
        cout << "Eingabedatei \"" << mFile << "\" konnte nicht geoeffnet werden!" << endl ;
        exit(EXIT_FAILURE);
    }
    string line;
    int i = 1;
    Parser myParser;
    MyMap indexMap;
    while(getline(inputStream, line)) {    	
    	int j = 1 ;
        vector<string> lineWords = myParser.parseInputLine(line) ;
        vector<string>::iterator lineWordsIterator;
        bool replace;
        for(lineWordsIterator = lineWords.begin(); lineWordsIterator != lineWords.end(); ++lineWordsIterator) {
            vector<Entry> words;
            Entry position (i,j);
            string word = *lineWordsIterator ;
            words = indexMap[word];        
            words.push_back(position);
            indexMap[word] = words;
            j++;
        }
    	i++;
    }
    inputStream.close() ;   
   return indexMap;
}

