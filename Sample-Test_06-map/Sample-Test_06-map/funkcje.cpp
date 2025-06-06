#include "funkcje.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

string zamien(const string& s, const string& co, const string& naco) {
	string wynik;
	size_t i = 0;
	while (i < s.size()) {  //ile znaków w ³añcuchu
        if (s.substr(i, co.size()) == co) {
            wynik += naco;
            i += co.size();
        }
        else {
            wynik += tolower(s[i++]);
        }
    }
	return wynik;
}