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
    for (string st: stanja) vektor_stanja.push_back(st);

    map<string, int> podjela1;

    for (string st: stanja) 
        podjela1[st] = prihvatljiva_stanja.count(st);

    map<string, int> podjela2;

    while (1) {

        for (int i = 0; i < vektor_stanja.size(); i++) {

            for (int j = i; j < vektor_stanja.size(); j++) {

                if (podjela1[vektor_stanja[i]] != podjela1[vektor_stanja[j]])
                    continue;

                bool uvrsti = false;

                for (string zn: abeceda) {

                    string pr1 = prijelazi[pair<string, string>(vektor_stanja[i], zn)];
                    string pr2 = prijelazi[pair<string, string>(vektor_stanja[j], zn)];

                    if (podjela1[pr1] == podjela1[pr2]) {
                        uvrsti = true;
                        break;
                    }

                }

                if (uvrsti) {

                    

                }

            }

        }

    }

}