#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(void) {

    set<int> dulj;
    unordered_map<int, int> kol;
    int niz[500069];
    int kol_pr = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        dulj.insert(d);
        if (kol.count(d) == 0) kol[d] = 0;
        kol[d]++;
    }

    int d0 = 0;
    for (int d: dulj) {

        kol_pr += d - d0;
        d0 = d;

        for (int i = 0; i < d; i++) niz[i] = 0;
        for (int i = d - 1; i >= 0; i--) {
            cout << niz[i] + 1 << ' ';
        }
        cout << '\n';

        for (int i = 1; i < kol[d]; i++) {

            int j = 0;
            bool nastavi;
            int promjene = 0;

            do {

                niz[j]++;
                niz[j] %= n;
                nastavi = niz[j] == 0;
                j++;
                promjene++;

            } while(nastavi);

            kol_pr += promjene;

            for (int j = d - 1; j >= 0; j--) {
                cout << niz[j] + 1 << ' ';
            }
            cout << '\n';

        }

    }

}