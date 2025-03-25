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


int main(void) {

    string redak;

    cin >> redak; // stanja odvojena zarezom

    cin >> redak; // simboli odvojeni zarezom
    vector<string> abeceda = splitstr(redak, ",");

    cin >> redak; // prihvatljiva stanja odvojena zarezom;

    set<string> prihvatljiva_stanja;
    for (auto i: splitstr(redak, ",")) prihvatljiva_stanja.emplace(i);

    cin >> redak; // pocetno stanje
    
    set<string> stanja;
    stanja.emplace(redak);
    
    queue<string> red_stanja;
    red_stanja.emplace(redak);

    map<pair<string, string>, string> prijelazi;

    while (getline(cin, redak)) {

        if (redak == "") continue;

        vector<string> podaci;

        for (string i: splitstr(redak, "->"))
            for(string j: splitstr(i, ","))
                podaci.push_back(j);
        
        prijelazi[pair<string,string>(podaci[0], podaci[1])] = podaci[2];

    }

    
    while (!red_stanja.empty()) {

        string stanje = red_stanja.front();
        red_stanja.pop();

        for (string zn: abeceda) {

            string pr = prijelazi[pair<string, string>(stanje, zn)];

            if (stanja.count(pr) == 0) {
                stanja.emplace(pr);
                red_stanja.emplace(pr);
            }

        }

    }

    vector<string> vektor_stanja;
    for (string i: stanja) vektor_stanja.push_back(i);

    set<pair<string, string>> ekvivalentna_st;

    for (int i = 0; i < vektor_stanja.size(); i++) {

        for (int j = i + 1; i < vektor_stanja.size(); j++) {

            set<pair<string, string>> pregledani_parovi;
            queue<pair<string, string>> parovi;

            string st1 = vektor_stanja[i];
            string st2 = vektor_stanja[j];

            parovi.emplace(pair<string,string>(st1, st2));

            cout << "----------------\n";

            while (!parovi.empty()) {

                cout << parovi.front().first << " " << parovi.front().second << "\n";

                pregledani_parovi.emplace(pair<string, string>(parovi.front().first, parovi.front().second));

                if (prihvatljiva_stanja.count(parovi.front().first) ^ prihvatljiva_stanja.count(parovi.front().second)) break;

                for (string zn: abeceda) {

                    pair<string, string> par_pr;
                    par_pr.first = prijelazi[pair<string, string>(st1, zn)];
                    par_pr.second = prijelazi[pair<string, string>(st2, zn)];

                    if (pregledani_parovi.count(par_pr) == 0) {
                        pregledani_parovi.emplace(par_pr);
                        parovi.emplace(par_pr);
                    }

                }

                parovi.pop();

            }

        }

    }

}