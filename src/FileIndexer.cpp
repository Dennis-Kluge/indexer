#include "FileIndexer.hpp" 

using namespace std ;

FileIndexer::FileIndexer(string file) {
	mFile = file;
}

void FileIndexer::PrintPositionVector(vector<Entry> positions)  {
    vector<Entry>::iterator entry_iterator;
    for(entry_iterator = positions.begin(); entry_iterator != positions.end(); ++entry_iterator) {
        Entry pos = *entry_iterator;
        cout << " (" << pos.first << "," << pos.second << ")" ;
    }
    cout << endl;
}

void FileIndexer::PrintWordIndex(string word) {
    MyMap::iterator iterator = indexMap.find(word);
    if(iterator != indexMap.end()) {
        PrintPositionVector((*iterator).second);
    } else {
        cout << "Das Wort ist nicht im Index vorhanden" ; 
    }            
}

void FileIndexer::PrintWordsIndexes(string word)  {
    MyMap::iterator iterator;
    MyMap result; 
    if(word.size() == 0) {
        PrintResult(indexMap);
    } else {
        for(iterator = indexMap.begin(); iterator != indexMap.end(); ++iterator) {
            string sub = (*iterator).first.substr(0,word.size());
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            transform(sub.begin(), sub.end(), sub.begin(), ::tolower);
           if(word == sub) {
                result.insert(make_pair((*iterator).first,(*iterator).second)) ;   
            } 
        }
        if(result.size() == 0) {
            cout << "Es sind keine Wörter mit diesen Anfangsbuchstaben vorhanden" ;
        } else {
            PrintResult(result) ;    
        }
    }    
}	

void FileIndexer::PrintResult(MyMap mmap) {
    MyMap::iterator iterator = mmap.begin();
    while(iterator != mmap.end()) {     
    	cout << (*iterator).first;
    	PrintPositionVector(((*iterator).second));
         ++iterator;
    }
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

