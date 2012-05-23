#include "Controller.hpp"
#include "Timer.hpp"

using namespace std;

Controller::Controller() {
}

Controller::~Controller() {
}

int Controller::runIndexer(int argc, char* argv[]) {
	if(argc != 3) {		
		printUsage();
		return EXIT_FAILURE;
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
	while(input)  {		
		string line;
		getline(cin,line);
		istringstream inputStream(line);
		vector<string> command ;
		do {
			string sub;
			inputStream >> sub;
			command.push_back(sub);
		} while (inputStream);
		if(command.size() > 3) {
			cout << "Sie haben zu viele Befehle/Wörter angegeben" << endl;
			printUsage();
		}
		if(command.size() >= 1 && command.size() <= 3) {
			if(command[0] == "w!") {
				timer.start();
				indexer.PrintWordIndex(command[1]);
				cout << "Zeit: " << fixed << setprecision (3) << timer.stop() << endl;
			} else if(command[0] == "a!") {
				timer.start();
				indexer.PrintWordsIndexes(command[1]);
				cout << "Zeit: " << fixed << setprecision (3)  << timer.stop() << endl;
			} else if(command[0] == "q!") {
				return EXIT_SUCCESS;				
			} else {
				cout << "Befehl nicht bekannt!" << endl;
			}
		}		
	}
	return EXIT_SUCCESS;	
}

 void Controller::writeIndexFile(string outputFile, MyMap index){
 	ofstream outputStream(outputFile.data());
 	if(!outputStream) {
 		cerr << "Datei kann nicht geöffnet werden";
 	}

  MyMap::iterator iter = index.begin();
  while(iter != index.end()) {     
  	outputStream << (*iter).first 
   	std::vector<Entry>::iterator itvec;
    for(itvec = (*iter).second.begin(); itvec != (*iter).second.end(); itvec++) {
    	Entry pos = *itvec;
      outputStream << " (" << pos.first << "," << pos.second << ")" ;
    }
    outputStream <<endl;
    ++iter;
  }
 }

 void Controller::printUsage() {
 	cout << "Benutzung des Programmes" << endl;
 	cout << "-----------------------------" << endl;
 	cout << "indexer <inputfile> <outputfile>" << endl;
 	cout << "<inputfile>  : Dateiname der Eingabedatei mit dem zu indizierenden Text" << endl;
 	cout << "<outputfile> : Dateiname der Ausgabedatei fuer den erstellten Index" << endl;
 	cout << "Interaktive Kommandos" << endl;
 	cout << "w! <Wort> Gib den Index zum Wort <Wort> aus." << endl;
 	cout << "a! <Wortanfang> Gib die Indizes zu allen Woertern aus, die den Wortanfang <Wortanfang> besitzen." << endl;
 	cout << "a! <Wortanfang> Gib die Indizes zu allen Woertern aus, die den Wortanfang <Wortanfang> besitzen." << endl;
 	cout << "q! Beende das Programm." << endl;
 }