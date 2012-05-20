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
    	std::vector<string>::iterator itvec;
    	for(itvec = (*iter).second.begin(); itvec != (*iter).second.end(); itvec++) {
    		cout << *itvec << "+";
    	}
    	cout << ")" <<endl;
         ++iter;
    }
}

map<string, vector<string> > FileIndexer::IndexFile(){
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
    		vector<string> words;
    		stringstream row;
    		stringstream column;
    		row << i;
    		column << j;
    		string position = "(" + row.str() + "," + column.str() + ")";
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