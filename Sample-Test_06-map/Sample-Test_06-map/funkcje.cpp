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

string zamienNaKanoniczne(const string& nazwisko) {
	string knazwisko = nazwisko;
    knazwisko = zamien(knazwisko, "o", "u");
    knazwisko = zamien(knazwisko, "rz", "z");
    knazwisko = zamien(knazwisko, "ch", "h");
	return knazwisko;
}

void test() {
    map<string, vector<string>> mapa;
    for (const std::string& nazwisko : { "JASKoLSKI", "JASKULSKI", "DROHOMSKI", "drochomski" }) {
        std::string klucz = zamienNaKanoniczne(nazwisko);  // np. zamien("jaskólski", "ó", "o")
        mapa[klucz].push_back(nazwisko);
    }
    for (const auto& [klucz, nazwiska] : mapa) {
        printf("%s: ", klucz.c_str());
        for (const auto& nazwisko : nazwiska) {
            printf("%s ", nazwisko.c_str());
        }
        printf("\n");
    }
}