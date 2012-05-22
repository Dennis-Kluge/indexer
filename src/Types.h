#include <set>
#include <map>
#include <string>
#include <vector>
#include "LexComparator.hpp"

using namespace std;


typedef pair<int, int> Entry;

// Der Vector muss noch sortiert werden
typedef map<string, vector<Entry>, LexComparator> MyMap;


