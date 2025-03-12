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


int main(void) {

    int brojstanja = 0;
    
    string text;
    cin >> text;

    string sep;
    cin >> sep;

    for (auto i: splitstr(text, sep)) {
        cout << i << '\n';
    }

    cout << endl;
    
    return 0;

}