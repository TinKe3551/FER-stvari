#include <iostream>
#include <bits/stdc++.h>
#include <string>


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


string joinstr(vector<string> &c, string delim) {

    string r = "";

    for (int i = 0; i < c.size() - 1; i++)
        r += c[i] + delim;

    r += c[c.size() - 1];

    return r;

}


string joinstr(set<string> &c, string delim) {

    vector<string> c2;
    for (string s: c) c2.push_back(s);

    return joinstr(c2, delim);

}


int provjera (string st1, string st2, vector<string> &abeceda, map<pair<string, string>, string> &prijelazi, map<string, int> &stanje_grupa) {

    

    for (string zn: abeceda) {

        string pr1 = prijelazi[pair<string, string>(st1, zn)];
        string pr2 = prijelazi[pair<string, string>(st2, zn)];

        if (stanje_grupa[pr1] != stanje_grupa[pr2]) return 0;

    }

    return 1;

}


string otisak(string &st, map<string, map<string, string>> &prijelazi, map<string, string> &ekvivalentna) {

    vector<string> ot_v;

    for (auto zn: prijelazi[st]) ot_v.push_back(ekvivalentna[zn.second]);
    
    string ot_str = joinstr(ot_v, ",");

    #ifdef debug
    cout << "> " << st << " " << ot_str << "\n";
    #endif

    return ot_str;

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

    string pocetno_st = redak;
    
    set<string> stanja;
    stanja.emplace(redak);
    
    queue<string> red_stanja;
    red_stanja.emplace(redak);

    map<string, map<string, string>> prijelazi;

    while (getline(cin, redak)) {

        if (redak == "") continue;

        vector<string> podaci;

        for (string i: splitstr(redak, "->"))
            for(string j: splitstr(i, ","))
                podaci.push_back(j);
        
        prijelazi[podaci[0]][podaci[1]] = podaci[2];

    }

    
    while (!red_stanja.empty()) {

        string stanje = red_stanja.front();
        red_stanja.pop();

        for (string zn: abeceda) {

            string pr = prijelazi[stanje][zn];

            if (stanja.count(pr) == 0) {
                stanja.emplace(pr);
                red_stanja.emplace(pr);
            }

        }

    }


    set<string> ukloniti;
    for (auto st: prijelazi) 
        if (stanja.count(st.first) == 0) 
            ukloniti.emplace(st.first);
        cout << "a";
    cout << "\n";
    for (string st: ukloniti) prijelazi.erase(st);

    #ifdef debug
    for (auto st: prijelazi) {

        for (auto pr: st.second) {

            cout << st.first << "," << pr.first << "->" << pr.second << "\n";

        }

    }
    #endif

    vector<string> vektor_stanja;
    for (string i: stanja) vektor_stanja.push_back(i);

    set<vector<string>> podjela1;

    map<string, vector<string>> podgrupe;

    for (string st: vektor_stanja) podgrupe[to_string(prihvatljiva_stanja.count(st))].push_back(st);
    for (auto G: podgrupe) podjela1.emplace(G.second);
    
    set<vector<string>> podjela2;
    map<string, string> ekvivalentna;

    bool jednake = false;

    while (!jednake) {

        #ifdef debug

        cout << "----------------\n";
        for (auto G: podjela1) {
            for (string st: G) cout << st << " ";
            cout << "\n";
        }

        #endif

        ekvivalentna.clear();

        for (auto G:podjela1) {
            for (auto st: G) ekvivalentna[st] = ekvivalentna[G[0]];
        }

        for (auto G: podjela1) {

            podgrupe.clear();

            for (string st: G) {

                podgrupe[otisak(st, prijelazi, ekvivalentna)].push_back(st);

            }

            for (auto PG: podgrupe)
                podjela2.emplace(PG.second);

        }

        jednake = podjela1==podjela2;

        podjela1 = podjela2;
        podjela2.clear();

    }



}