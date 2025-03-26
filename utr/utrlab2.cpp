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

    map<int, vector<string>> podgrupa_stanja;

    for (string st: vektor_stanja) podgrupa_stanja[prihvatljiva_stanja.count(st)].push_back(st);
    for (auto G: podgrupa_stanja) podjela1.emplace(G.second);

    map<string, int> stanje_grupa;
    set<vector<string>> podjela2;
    map<string, int> upisana_st;

    bool jednake = false;

    while (!jednake) {

        #ifdef debug
        cout << "--------------------\n";
        for (auto G: podjela1) {
            for (string st: G) cout << st << " ";
            cout << "\n\n";
        }
        #endif

        stanje_grupa.clear();
        upisana_st.clear();

        int i = 1;
        for (auto G: podjela1) {
            for (string st: G) stanje_grupa[st] = i;
            i++;
        }

        for (auto G: podjela1) {

            podgrupa_stanja.clear();

            int pgr;

            for (int i = 0; i < G.size(); i++) {

                if (upisana_st.count(G[i])) pgr = upisana_st[G[i]];
                else pgr = upisana_st.size() + 1;

                for (int j = i + 1; j < G.size(); j++) {

                    if (!provjera(G[i], G[j], abeceda, prijelazi, stanje_grupa)) continue;

                    if (!upisana_st.count(G[i])) {
                        podgrupa_stanja[pgr].push_back(G[i]);
                        upisana_st[G[i]] = pgr;
                    }

                    if (!upisana_st.count(G[j])) {
                        podgrupa_stanja[pgr].push_back(G[j]);
                        upisana_st[G[i]] = pgr;
                    }

                }
                
            }

            for (auto G: podgrupa_stanja) podjela2.emplace(G.second);

        }

        jednake = podjela1 == podjela2;

        podjela1 = podjela2;
        podjela2.clear();

    }

    map<string, string> zamjene;
    set<string> ukloniti;

    for (auto G: podjela1) {
        for (int i = 1; i < G.size(); i++) {
            zamjene[G[i]] = G[0];
            ukloniti.emplace(G[i]);
        }
    }
    
    for (auto st_zn: prijelazi) if (stanja.count(st_zn.first.first) == 0) ukloniti.emplace(st_zn.first.first);

    for (string st: stanja) {

        for (string zn: abeceda) {

            pair<string, string> st_zn = pair<string, string>(st, zn);

            if (ukloniti.count(st)) {
                prijelazi.erase(st_zn);
                continue;
            }

            if (zamjene.count(prijelazi[st_zn])) 
                prijelazi[st_zn] = zamjene[prijelazi[st_zn]];

        }

    }

    for (string st: ukloniti) {
        if (stanja.count(st)) stanja.erase(st);
        if (prihvatljiva_stanja.count(st)) prihvatljiva_stanja.erase(st);
    }


    #ifndef debug
    cout << joinstr(stanja, ",") << "\n";
    cout << joinstr(abeceda, ",") << "\n";
    cout << joinstr(prihvatljiva_stanja, ",") << "\n";
    cout << pocetno_st << "\n";

    for (auto i: prijelazi) {
        cout << i.first.first << "," << i.first.second << "->" << i.second << "\n";
    }
    #endif

}