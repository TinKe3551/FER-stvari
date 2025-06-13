#include <bits/stdc++.h>


using namespace std;


map<char, vector<string>> produkcije = {
    {'S', {"aAB", "bBA"}},
    {'A', {"bC", "a"}},
    {'B', {"ccSbc", ""}},
    {'C', {"AA"}}
};

string rekreacija = "S";
string zadani;
bool moguce_parsirati = false;
bool nastavi = true;


void parser() {

    #ifdef debug
    cout << "----------------\n" << rekreacija << "\n";
    #endif

    if (!nastavi) return;

    for (int i = 0; i < rekreacija.size(); i++) {

        if (i > zadani.size()) {
            nastavi = false;
            return;
        }

        else if (produkcije.count(rekreacija[i])) {

            #ifdef debug
            cout << "ispisan završni znak " << rekreacija[i] << "\n";
            #endif

            #ifndef debug
            cout << rekreacija[i];
            #endif

            string prije = rekreacija.substr(0, i);
            string poslije = rekreacija.substr(i + 1);
            char nezavrsni = rekreacija[i];

            for (string pr: produkcije[nezavrsni]) {

                rekreacija = prije + pr + poslije;
                parser();
                rekreacija = prije + nezavrsni + poslije;

            }

            return;

        }

        else if (zadani[i] != rekreacija[i]) return;

        else if (i == zadani.size() - 1 && i == rekreacija.size() - 1) {
            moguce_parsirati = true;
            nastavi = false;
            return;
        }

    }

}


int main(void) {

    cin >> zadani;

    char r[zadani.size()];

    parser();

    if (moguce_parsirati) cout << "\nDA\n";
    else cout << "\nNE\n";

    return 0;
}
