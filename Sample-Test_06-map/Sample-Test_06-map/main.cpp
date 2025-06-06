#include "funkcje.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

string zamienNaKanoniczne(const string& nazwisko) {
    string knazwisko = nazwisko;
    knazwisko = zamien(knazwisko, "o", "u");
    knazwisko = zamien(knazwisko, "rz", "z");
    knazwisko = zamien(knazwisko, "ch", "h");
    return knazwisko;
}


int main() {

	ifstream plik("..\\..\\lab-06-mapy\\nazwiska_mêskie-osoby_¿yj¹ce.csv");
	if (!plik) {
		cerr << "Nie mo¿na otworzyæ pliku!" << endl;
		return 1;
	}
	string linia;
	getline(plik, linia);   //nag³ówek pomijamy

    map<string, vector<string>> mapa;

    while (getline(plik, linia)) {
		size_t comma = linia.find(',');
        string nazwisko = linia.substr(0, comma);
        string klucz = zamienNaKanoniczne(nazwisko);
		mapa[klucz].push_back(nazwisko);
    }

    vector<vector<string>> grupy;
    for (auto& [_, grupa] : mapa) {
        if (grupa.size() > 1) {
            grupy.push_back(grupa);
        }
    }

    //sortowanko
    sort(grupy.begin(), grupy.end(), [](const vector<string>& a, const vector<string>& b) {
        return a.size() > b.size();
    });

    for (const auto& grupa : grupy) {
        for (const auto& nazwisko : grupa) {
			cout << nazwisko << " ";
        }
		cout << endl;
    }

    int licznik = 0;
    for (const auto& grupa : grupy) {
        licznik++;
        if (licznik > 10) break;
        for (const auto& nazwisko : grupa) {
            cout << nazwisko << " ";
        }
        cout << endl;
    }

	return 0;
}