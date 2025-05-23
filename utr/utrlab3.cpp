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


string joinstr(vector<string> &c, string delim) {

    if (c.size() == 0) return "";

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


bool obavi_prijelaz(vector<string> &trojka, deque<string> &stog, map<string,string> &prijelazi) {

    return true;

}


int main(void) {

    string redak;

    // ulazni nizovi    
    vector<vector<string>> ulazni_nizevi;
    cin >> redak;

    for (string i: splitstr(redak, "|")) {
        ulazni_nizevi.push_back(splitstr(i, ","));
        ulazni_nizevi.back().push_back("$");
    }

    // skup stanja
    set<string> stanja;
    cin >> redak;

    for (string i: splitstr(redak, "|")) {
        stanja.emplace(i);
    }

    // ulazni znakovi
    cin >> redak;
    
    // znakovi stoga
    cin >> redak;

    // skup prihvatljivih stanja
    set<string> prihvatljiva_stanja;
    cin >> redak;

    for (string i: splitstr(redak, "|")) {
        prihvatljiva_stanja.emplace(i);
    }

    // početno stanje
    string poc_st;
    cin >> poc_st;

    // početni znak stoga
    string poc_zn_st;
    cin >> poc_zn_st;

    // prijelazi
    map<string, string> prijelazi;

    while (getline(cin, redak)) {

        if (redak == "") continue;

        vector<string> prijelaz = splitstr(redak, "->");
        prijelazi[prijelaz[0]] = prijelazi[prijelaz[1]];

    }

    // obrada ulaznih nizeva

    vector<string> trojka;
    deque<string> stog;

    for (vector<string> ulazni_niz: ulazni_nizevi) {

        trojka.clear();
        int i = 0;
        trojka.push_back(poc_st);
        trojka.push_back(ulazni_niz[i]);
        trojka.push_back("");

        stog.clear();
        stog.emplace_back(poc_zn_st);

        while (obavi_prijelaz(trojka, stog, prijelazi)) {
            i = min((unsigned long)i + 1, ulazni_niz.size() - 1);
            trojka[0] = ulazni_niz[i];
        }

    }

    return 0;

}