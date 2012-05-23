#include "LexComparator.hpp"
#include <algorithm>

using namespace std;

LexComparator::LexComparator() {
}

LexComparator::~LexComparator() {
}

bool LexComparator::compare(char a, char b) {
	if(tolower(a) == tolower(b)) {
		return a < b; 
	}
	return tolower(a) < tolower(b);
}

bool LexComparator::operator() (string a, string b) {
	return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), compare);
}

