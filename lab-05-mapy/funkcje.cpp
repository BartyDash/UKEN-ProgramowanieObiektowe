#include <fstream>
#include <set>
#include <string>
#include <vector>

#include "funkcje.h"
#include <algorithm>

using namespace std;

set<string> wczytaj_slowa(istream &strumien)
{
    set<string> wynik;
    string slowo;
	while (strumien >> slowo)
	{
		wynik.insert(slowo);
	}
    return wynik;
}

vector<pair<string, string>> podziel_slowo(const string &slowo)
{
    vector<pair<string, string>> wynik;
    for (size_t i = 1; i < slowo.size(); ++i)
	{
		string start = slowo.substr(0, i);
		string end = slowo.substr(i);
		wynik.emplace_back(start, end);
	}
    return wynik;
}

void dodaj_1_jesli_poczatek_i_koniec_to_slowa(
    const string &poczatek,
    const string &koniec,
    const set<string> &zbior_slow,
    map<string, int> *licznik_slow)
{
	if (zbior_slow.find(poczatek) != zbior_slow.end() &&
		(zbior_slow.find(koniec) != zbior_slow.end()))
	{
		(*licznik_slow)[poczatek]++;
		(*licznik_slow)[koniec]++;
	}
}

vector<PunktySlowa> stworz_wektor(const map<string, int> &licznik_slow)
{
    vector<PunktySlowa> wynik;
	for (const auto& para : licznik_slow)
	{
		wynik.push_back(PunktySlowa{ para.first, para.second });
	}
    return wynik;
}

void posortuj_wg_punktow_malejaco(vector<PunktySlowa> *punkty_slow)
{
	sort(punkty_slow->begin(), punkty_slow->end(),
		[](const PunktySlowa& a, const PunktySlowa& b) {
			return a.punkty > b.punkty;
		});
}

void wypisz_slowa_i_punkty(const vector<PunktySlowa> &punkty_slow, ostream &strumien)
{
	for (const auto &ps : punkty_slow)
	{
		strumien << ps.slowo << " " << ps.punkty << endl;
	}
}