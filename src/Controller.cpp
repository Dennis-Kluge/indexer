#include "Controller.hpp"
#include "Timer.hpp"


using namespace std;

Controller::Controller() {
}

Controller::~Controller() {
}


int Controller::run_indexer(int argc, char* argv[])
{
	if(argc != 3){
		cout << "Es wurden nicht genug Argumente angegeben" << endl;
		return EXIT_FAILURE ;
	}
	string filename(argv[1]);
	FileIndexer indexer(filename);
	MyMap index;
	Timer timer;
	timer.start();
	index = indexer.IndexFile();
	cout << "Zeit: " << fixed << setprecision (3) << timer.stop() << endl;
	writeIndexFile(argv[2], index);
	string c;
	string word;
	bool input = true;
	while(input) 
	{
		//cout << "Befehl eingeben: " ; 
		string line;
		getline(cin,line);
		istringstream iss(line);
		vector<string> com ;
		do
		{
			string sub;
			iss >> sub;
			com.push_back(sub);
		} while (iss);
		if(com.size() > 3) {
			cout << "Sie haben zu viele Befehle/Wörter angegeben" << endl;
		}
		if(com.size() >= 1 && com.size() <= 3) {
			if(com[0] == "w!") {
				timer.start();
				indexer.PrintWordIndex(com[1]);
				cout << "Zeit: " << fixed << setprecision (3) << timer.stop() << endl;
			} else if(com[0] == "a!") {
				timer.start();
				indexer.PrintWordsIndexes(com[1]);
				cout << "Zeit: " << fixed << setprecision (3)  << timer.stop() << endl;
			} else if(com[0] == "q!") {
				return EXIT_SUCCESS ;				
			} else {
				cout << "Befehl nicht bekannt!" << endl;
			}
		}
		
	}
}

 void Controller::writeIndexFile(string outputFile, MyMap index){
 	ofstream aus(outputFile.data());
 	if(!aus)
 	{
 		cerr << "Datei kann nicht geöffnet werden";
 	}

  	MyMap::iterator iter = index.begin();
    while(iter != index.end())
    {     
    	aus << (*iter).first << "(";
    	 std::vector<Entry>::iterator itvec;
        for(itvec = (*iter).second.begin(); itvec != (*iter).second.end(); itvec++) {
            Entry pos = *itvec;
            aus << "(" << pos.first << "," << pos.second << ")" ;
        }
        aus << ")" <<endl;
         ++iter;
    }

 }