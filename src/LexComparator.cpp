#include "LexComparator.hpp"
#include <algorithm>

using namespace std;

LexComparator::LexComparator() {
}

LexComparator::~LexComparator() {
}

bool LexComparator::operator()( const string &a, const string &b ) const { 
    int result = strcasecmp(&a[0],&b[0]);
    if (result > 0) {
        return false;
    } else if (result < 0) {
        return true;
    } else if (result == 0) {
        if (int(a[0]) < int(b[0]))
            return true;
        else
            return false;
    }
    return false;
}

