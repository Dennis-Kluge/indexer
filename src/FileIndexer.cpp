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

void FileIndexer::PrintResult() {
	PrintResult(indexMap);	
}
	

void FileIndexer::PrintResult(MyMap mmap){
	cout << "Ausgabe:\n";
    MyMap::iterator iter = mmap.begin();
    while(iter != mmap.end())
    {     
    	cout << (*iter).first << "(";
    	std::vector<Entry>::iterator itvec;
    	for(itvec = (*iter).second.begin(); itvec != (*iter).second.end(); itvec++) {
            Entry pos = *itvec;
    		cout << "(" << pos.first << "," << pos.second << ")" << "+";
    	}
    	cout << ")" <<endl;
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
    while(getline(ifs, line)) {
    	string buf;
    	stringstream ss(line);
    	int j = 1;
    	while(ss >> buf) {
    		vector<Entry> words;
            Entry position (i,j);
    		MyMap::iterator it;
    		it = indexMap.find(buf);
    		if(it != indexMap.end()) {
    			words = (*it).second;
    			indexMap.erase(it);
    		}
    		words.push_back(position);
    		indexMap.insert( make_pair(buf,words));
    		j++;
    	}
    	i++;
    }
    ifs.close() ;
    
   return indexMap;
}