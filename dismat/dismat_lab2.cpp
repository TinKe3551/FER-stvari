#include <iostream>
#include <vector>
#include <set>


using namespace std;


int mat_sus[15][15];
vector<int> incidentni[15];
set<int> posjeceni;


void trazi(int v, int l, int &k) {

    if (l == k) return;

    posjeceni.insert(v);

    for (int i: incidentni[v]) {
        trazi(i, l + 1, k);
    }

    posjeceni.erase(v);

}


int main(void) {

    string dat;
    cout << "Unesite ime datoteke: ";
    cin >> dat;

    freopen(dat.c_str(), "r", stdin);

    int n;
    cin >> n;

    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {

        int redak;
        cin >> redak;

        for (int j = n - 1; j >= 0; j--) {

            mat_sus[n][j] = redak % 10;
            redak /= 10;

        }

    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (mat_sus[i][j] == 1) incidentni[n].push_back(j);

        }

    }

    

}