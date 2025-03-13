#include <iostream>
#include <bits/stdc++.h>


using namespace std;


vector<string> splitstr(string s, string delim) {

    string part = "";
    vector<string> parts;

    for (unsigned int i = 0; i < s.size();) {

        if (s.substr(i, delim.size()) == delim) {
            parts.push_back(part);
            part = "";
            i += delim.size();
        }

        else {
            part += s[i];
            i++;
        }
    }

    if (part != "") parts.push_back(part);

    return parts;

}

void upotpuni(set<string> &trenutna_stanja, map<string, vector<string>> epsilon_prijelazi) {

    queue<string> red_stanja;
    for (string st: trenutna_stanja) red_stanja.emplace(st);

    while (!red_stanja.empty()) {

        string stanje = red_stanja.front();
        red_stanja.pop();

        for (string stanje2: epsilon_prijelazi[stanje]) {
            if (trenutna_stanja.count(stanje2) == 0) {
                trenutna_stanja.emplace(stanje2);
                red_stanja.emplace(stanje2);
            }
        }

    }

}


void ispis(set<string> &trenutna_stanja) {

    if (trenutna_stanja.size() == 0) {
        cout << '#';
        return;
    }

    unsigned int i = 1;

    for (string st: trenutna_stanja) {
        cout << st;
        if (i < trenutna_stanja.size()) cout << ",";
        i++;
    }

}


int main(void) {

    string redak;
    cin >> redak;
    vector<string> nizevi = splitstr(redak, "|");

    cin >> redak;
    vector<string> stanja = splitstr(redak, ",");

    cin >> redak;
    set<string> abeceda;
    for (string i: splitstr(redak, ",")) abeceda.emplace(i);

    cin >> redak;
    set<string> prihvatljiva_stanja;
    for (string i: splitstr(redak, ",")) prihvatljiva_stanja.emplace(i);

    set<string> pocetna_stanja;
    cin >> redak;
    pocetna_stanja.emplace(redak);
    
    map<string, vector<string>> epsilon_prijelazi;
    map<pair<string, string>, vector<string>> prijelazi;

    while (getline(cin, redak)) {

        if (redak == "") continue;

        vector<string> podaci;

        for (string s: splitstr(redak, "->")) {
            for (string p: splitstr(s, ",")) podaci.push_back(p);
        }

        if (podaci[1] == "$") {
            for (unsigned int i = 2; i < podaci.size(); i++) if (podaci[i] != "#") epsilon_prijelazi[podaci[0]].push_back(podaci[i]);
        }

        else {
            pair<string, string> temp = pair<string, string>(podaci[0], podaci[1]);
            for (unsigned int i = 2; i < podaci.size(); i++) if (podaci[i] != "#") prijelazi[temp].push_back(podaci[i]);
        }

    }    
    
    upotpuni(pocetna_stanja, epsilon_prijelazi);

    set<string> trenutna_stanja;

    for (auto niz: nizevi) {

        trenutna_stanja = pocetna_stanja;
        ispis(trenutna_stanja);

        vector<string> znakovi = splitstr(niz, ",");

        for (string znak: splitstr(niz, ",")) {

            cout << '|';

            set<string> sljedeca_stanja;

            for (string st: trenutna_stanja) {

                pair<string, string> prijelaz = pair<string, string>(st, znak);
                if (prijelazi.count(prijelaz) != 0) {
                    for (string slj_st: prijelazi[prijelaz]) sljedeca_stanja.emplace(slj_st);
                }

            }

            trenutna_stanja = sljedeca_stanja;
            upotpuni(trenutna_stanja, epsilon_prijelazi);

            ispis(trenutna_stanja);

        }

        cout << endl;

    }
    
    return 0;

}