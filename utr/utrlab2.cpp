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

    set<vector<string>> podjela1;

    vector<vector<string>> grupa_stanja;
    grupa_stanja.push_back(vector<string>());
    grupa_stanja.push_back(vector<string>());

    for (string st: vektor_stanja) grupa_stanja[prihvatljiva_stanja.count(st)].push_back(st);
    for (auto G: grupa_stanja) podjela1.emplace(G);

    map<string, int> stanje_grupa;
    set<vector<string>> podjela2;
    set<string> upisana_st;

    while (1) {

        cout << "--------------------\n";
        for (auto G: podjela1) {
            for (string st: G) cout << st << ", ";
            cout << "\n";
        }

        stanje_grupa.clear();
        podjela2.clear();
        upisana_st.clear();

        int i = 0;
        for (auto G: podjela1) {
            for (string st: G) stanje_grupa[st] = i;
            i++;
        }

        

    }

}