#include "FileIndexer.hpp" 

using namespace std ;

// FileIndexer::FileIndexer(string file)
// {
// 	mFile = file;
// }


// void FileIndexer::IndexFile(){
// 	cout << nFile;
// }

FileIndexer::FileIndexer(string file)
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
        string sub = (*it).first.substr(0,word.size());
       if(word == sub)
        {
            result.insert(make_pair((*it).first,(*it).second)) ;   
        } 
    }
    if(result.size() == 0)
    {
        cout << "Es sind keine Wörter mit diesen Anfangsbuchstaben vorhanden" ;
    } else 
    {
        PrintResult(result) ;    
    }
    
}

void FileIndexer::PrintResult() {
	PrintResult(indexMap);	
}
	

void FileIndexer::PrintResult(MyMap mmap){
    MyMap::iterator iter = mmap.begin();
    while(iter != mmap.end())
    {     
    	cout << (*iter).first << "(";
    	PrintPositionVector(((*iter).second));
         ++iter;
    }
}

MyMap FileIndexer::IndexFile(){
	ifstream ifs(mFile.data()) ;
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