#include "FileIndexer.hpp" 

using namespace std ;

// FileIndexer::FileIndexer(string file)
// {
// 	mFile = file;
// }


// void FileIndexer::IndexFile(){
// 	cout << nFile;
// }

FileIndexer::FileIndexer(char file[])
{
	mFile = file;
}

void FileIndexer::PrintPositionVector(vector<Entry> positions) 
{
    std::vector<Entry>::iterator itvec;
        for(itvec = positions.begin(); itvec != positions.end(); itvec++) {
            Entry pos = *itvec;
            cout << "(" << pos.first << "," << pos.second << ")" ;
        }
        cout << ")" <<endl;
}

void FileIndexer::PrintWordIndex(string word) 
{
    MyMap::iterator it = indexMap.find(word);
     if(it != indexMap.end()) 
     {
        PrintPositionVector((*it).second);
     } else 
     {
        cout << "Das Wort ist nicht im Index vorhanden" ; 
     }

            
}

void FileIndexer::PrintWordsIndexes(string word) 
{

    MyMap::iterator it ;
    MyMap result; 
    for(it = indexMap.begin(); it != indexMap.end(); ++it) 
    {
       /* if(word == (*it)first)
        {
            result.insert(make_pair((*it).first,(*it).first.second)) ;
            PrintResult(result) ;
        } else 
        {
            cout << "Es ist kein Wort mit dem Anfangsbuchstaben vorhanden" ;
        }*/
    }
}

void FileIndexer::PrintResult() {
	PrintResult(indexMap);	
}
	

void FileIndexer::PrintResult(MyMap mmap){
	cout << "Ausgabe:\n";
    MyMap::iterator iter = mmap.begin();
    while(iter != mmap.end())
    {     
    	cout << (*iter).first << "(";
    	PrintPositionVector(((*iter).second));
         ++iter;
    }
}

MyMap FileIndexer::IndexFile(){
	ifstream ifs(mFile) ;
    if (!ifs)
    {
        cout << "Eingabedatei \"" << mFile << "\" konnte nicht geoeffnet werden!" << endl ;
        exit(EXIT_FAILURE) ;
    }
    string line;
    int i = 1;
    Parser myParser;
    while(getline(ifs, line)) {
    	string buf ;
    	stringstream ss(line) ;
    	int j = 1 ;
        vector<string> lineWords = myParser.parse_input_line(line) ;
        vector<string>::iterator lwi;
        for(lwi = lineWords.begin(); lwi != lineWords.end(); ++lwi) {
            vector<Entry> words;
            Entry position (i,j);
            MyMap::iterator it;
            it = indexMap.find(buf);
            if(it != indexMap.end()) {
                words = (*it).second;
                indexMap.erase(it);
            }
            words.push_back(position);
            string word = *lwi ;
            indexMap.insert( make_pair(word,words));
            j++;
        }
    	i++;
    }
    ifs.close() ;
    
   return indexMap;
}