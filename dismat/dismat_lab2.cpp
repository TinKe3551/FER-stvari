#include <iostream>
#include <queue>
#include <set>



using namespace std;


int mat_sus[15][15];
set<int> incidentni[15];
set<int> posjeceni;
deque<int> put;


void trazi(int &pocetni, int v, int l, int &k, bool &postoji) {

    #ifdef debug
    cout << v << ' ';
    #endif

    if (postoji) return;

    if (l == k && incidentni[v].count(pocetni) > 0) {
        #ifdef debug
        cout << " evo ciklusa trazene duljine";
        #endif
        postoji = true;
        return;
    }

    else if (l == k) {
        return;
    }

    posjeceni.insert(v);
    put.emplace_back(v);

    for (int i: incidentni[v]) {

        if (posjeceni.count(i) > 0) continue;

        trazi(pocetni, i, l + 1, k, postoji);

        #ifdef debug
        cout << "\n";
        for (int i: put) cout << i << ' ';
        #endif
    }

    posjeceni.erase(v);
    put.pop_back();

}


int main(void) {

    #ifdef debug
    freopen("output", "w", stdout);
    #endif

    string dat;
    cout << "Unesite ime datoteke: ";
    cin >> dat;

    freopen(dat.c_str(), "r", stdin);

    int n;
    cin >> n;

    int k;
    cin >> k;

    if (k > n) {
        cout << 0 << '\n';
        return 0;
    }

    // matrica susjedstva

    for (int i = 0; i < n; i++) {

        string redak;
        cin >> redak;

        for (int j = 0; j < n; j++) {

            if (redak[j] == '1') mat_sus[i][j] = 1;
            else mat_sus[i][j] = 0;

        }

    }


    #ifdef debug

    cout << "matrica susjedstva:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cout << mat_sus[i][j] << ' ';

        }

        cout << '\n';

    }

    #endif

    // incidentni vrhovi

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (mat_sus[i][j] == 1) incidentni[i].emplace(j);

        }

    }


    #ifdef debug

    cout << "incidentni vrhovi:\n";

    for (int i = 0; i < n; i++) {

        cout << i << ": ";

        for (int j: incidentni[i]) {

            cout << j << ' ';

        }

        cout << '\n';

    }

    #endif



    bool postoji = false;

    #ifdef debug
    cout << "----------------\n";
    #endif

    // trazenje ciklusa

    for (int i = 0; i < n; i++) {

        trazi(i, i, 1, k, postoji);

        #ifdef debug
        cout << '\n';
        #endif
    }

    #ifdef debug
    cout << "----------------\n";
    #endif

    // konacni rezultat
    cout << postoji << '\n';

}