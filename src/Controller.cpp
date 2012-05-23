#include "Controller.hpp"
#include "Timer.hpp"

using namespace std;

Controller::Controller() {
}

Controller::~Controller() {
}


vector<string> Controller::commandParser() {
	string line;
	getline(cin,line);
	istringstream inputStream(line);
	vector<string> command ;
	do {
		string sub;
		inputStream >> sub;
		command.push_back(sub);
	} while (inputStream);
	return command;
}

MyMap Controller::generateIndex(string inputFile) {
	FileIndexer indexer(inputFile);
	MyMap index;
	timer.start();
	index = indexer.indexFile();
	cout << "Zeit: " << fixed << setprecision (3) << timer.stop() << endl;
	return index;
}

int Controller::runIndexer(int argc, char* argv[]) {
	if(argc != 3) {		
		printUsage();
		return EXIT_FAILURE;
	}
	MyMap index = generateIndex(argv[1]);
	writeIndexFile(argv[2], index);
	bool input = true;
	while(input)  {		
		vector<string> command = commandParser();
		if(command.size() > 3) {
			cout << "Sie haben zu viele Befehle/Wörter angegeben" << endl;
			printUsage();
		}
		if(command.size() >= 1 && command.size() <= 3) {
			if(command[0] == "w!") {
				printWordIndex(command[1], index);
			} else if(command[0] == "a!") {
				printWordsIndexes(command[1], index);
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
		outputStream << (*iter).first;
		vector<Entry>::iterator itvec;
		for(itvec = (*iter).second.begin(); itvec != (*iter).second.end(); itvec++) {
	    	Entry pos = *itvec;
	      	outputStream << " (" << pos.first << "," << pos.second << ")" ;
	    }
	    outputStream <<endl;
	    ++iter;
	}
 }

void Controller::printPositionVector(vector<Entry> positions)  {
    vector<Entry>::iterator entry_iterator;
    for(entry_iterator = positions.begin(); entry_iterator != positions.end(); ++entry_iterator) {
        Entry pos = *entry_iterator;
        cout << " (" << pos.first << "," << pos.second << ")" ;
    }
    cout << endl;
}

void Controller::printWordIndex(string word, MyMap indexMap) {
	timer.start();
    MyMap::iterator iterator = indexMap.find(word);
    if(iterator != indexMap.end()) {
        printPositionVector((*iterator).second);
    } else {
        cout << "Das Wort ist nicht im Index vorhanden" ; 
    }        
    cout << "Zeit: " << fixed << setprecision (3) << timer.stop() << endl;    
}

void Controller::printWordsIndexes(string word, MyMap indexMap)  {
	timer.start();
    MyMap::iterator iterator;
    MyMap result; 
    if(word.size() == 0) {
        printResult(indexMap);
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
            printResult(result) ;    
        }
    }    
    cout << "Zeit: " << fixed << setprecision (3) << timer.stop() << endl;  
}	

void Controller::printResult(MyMap indexMap) {
    MyMap::iterator iterator = indexMap.begin();
    while(iterator != indexMap.end()) {     
    	cout << (*iterator).first;
    	printPositionVector(((*iterator).second));
         ++iterator;
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