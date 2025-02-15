#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(void) {

    vector<int> ulazni_niz;
    set<int> dulj;
    unordered_map<int, int> kol;
    unordered_map<int, vector<vector<int>>> nizevi;
    int kol_pr = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        ulazni_niz.push_back(d);
        dulj.insert(d);
        if (kol.count(d) == 0) kol[d] = 0;
        kol[d]++;
    }

    int d0 = 0;
    for (int d: dulj) {

        kol_pr += d - d0;
        d0 = d;

        vector<int> niz;

        for (int i = 0; i < d; i++) niz.push_back(0);
        nizevi[d].push_back(niz);

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

            nizevi[d].push_back(niz);

        }

    }

    cout << kol_pr << '\n';
    
    unordered_map<int, int> ispisani;
    for (int d: dulj) ispisani[d] = 0;

    for (int i: ulazni_niz) {

        vector<int> &izlazni = nizevi[i][ispisani[i]++];

        for (int j = izlazni.size() - 1; j >= 0; j--) {

            cout << izlazni[j] + 1 << ' ';

        }

        cout << '\n';

    }

    return 0;

}