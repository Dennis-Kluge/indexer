#include "Parser.hpp"
#include <iostream>
#include <sstream>

using namespace std;

Parser::Parser() {
}

Parser::~Parser() {
}

vector<string> Parser::parseInputLine(string const text) {
	vector<string> words;
	size_t first = 0;
	bool found = false;
	for(size_t i = 0; i<=text.length(); ++i) {
		char c = text[i];
		if(
			( c >= 'A' && c <= 'Z' ) ||
			( c >= 'a' && c <= 'z' ) ||
			( c == '_' ) ||
			(( c >= '0' && c <= '9' ) && (i > first))
			) {
			found = true;
		} else {
			if(found) {
				words.push_back(text.substr(first, i-first));
				found = false;
			}
			first = i + 1;
		}
	}
	return words;
}
