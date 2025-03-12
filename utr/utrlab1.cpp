#include <iostream>
#include <bits/stdc++.h>


using namespace std;


vector<string> splitstr(string s, string delim) {

    string part = "";
    vector<string> parts;

    for (int i = 0; i <= s.size() - delim.size();) {
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

    string zadnje_st = *(trenutna_stanja.crbegin());

    for (string st: trenutna_stanja) {
        cout << st;
        if (st != zadnje_st) cout << ",";
        else cout << "|";
    }

}


int main(void) {

    string redak;
    cin >> redak;
    vector<string> nizevi = splitstr(redak, "|");

    cout << "b\n";

    cin >> redak;
    vector<string> stanja = splitstr(redak, ",");

    cout << "b\n";

    cin >> redak;
    set<string> abeceda;
    for (string i: splitstr(redak, ",")) abeceda.emplace(i);

    cin >> redak;
    set<string> prihvatljiva_stanja;
    for (string i: splitstr(redak, ",")) prihvatljiva_stanja.emplace(i);

    set<string> pocetna_stanja;
    cin >> redak;
    pocetna_stanja.emplace(redak);

    for (string i: pocetna_stanja) cout << i << ' ';
    cout << endl;
    
    map<string, vector<string>> epsilon_prijelazi;
    map<pair<string, string>, vector<string>> prijelazi;
    
    cout << "c\n";
    getline(cin, redak);

    while (getline(cin, redak)) {
        cout << redak << endl;

        vector<string> podaci;

        for (string s: splitstr(redak, "->")) {
            for (string p: splitstr(s, ",")) podaci.push_back(p);
        }

        cout << "a\n";

        if (podaci[1] == "$") {
            for (int i = 2; i < podaci.size(); i++) if (podaci[i] != "#") epsilon_prijelazi[podaci[0]].push_back(podaci[i]);
        }

        else {
            pair<string, string> temp = pair<string, string>(podaci[0], podaci[1]);
            for (int i = 2; i < podaci.size(); i++) if (podaci[i] != "#") prijelazi[temp].push_back(podaci[i]);
        }

        cout << "b\n";

    }    
    
    upotpuni(pocetna_stanja, epsilon_prijelazi);

    set<string> trenutna_stanja;

    for (auto niz: nizevi) {

        trenutna_stanja = pocetna_stanja;
        ispis(trenutna_stanja);

        for (string znak: splitstr(niz, ",")) {

            ispis(trenutna_stanja);

        }

        cout << endl;

    }
    
    return 0;

}