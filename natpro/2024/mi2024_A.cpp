#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int max_zad_gr(int gr, map<int, vector<pair<int, int>>> &grupe, int op, int &n) {

    #ifdef debug
    cout <<  "----------------\n";
    #endif

    int max_op = op;
    
    int mzd = -1;
    int l = grupe[gr].size();

    #ifdef debug
    cout << "duljina grupe: " << l << '\n';
    cout << "oznaka grupe: " << gr << '\n';
    for (auto i: grupe[gr]) {
        cout << i.first << " " << i.second << '\n';
    }
    #endif

    int razmaci[l - 1] = {0};
    int popunjenost[l - 1] = {0};
    int sirine[l];

    int h = 0;

    for (int i = 0; i < l - 1; i++) {

        //cout << grupe[gr][i + 1].first << " " << grupe[gr][i + 1].second << '\n';

        razmaci[i] = grupe[gr][i + 1].first - grupe[gr][i].second - 1;
        popunjenost[i] = razmaci[i];
        sirine[i] = grupe[gr][i].second - grupe[gr][i].first + 1;

        h += razmaci[i];

        op -= razmaci[i];

    }

    sirine[l - 1] = grupe[gr][l - 1].second - grupe[gr][l - 1].first + 1;
    
    op = max_op;
    
    int i_l = 0;
    int i_d = 0;
    int r;
    int d = sirine[0];

    #ifdef debug
    for (int i: sirine) cout << i << " ";
    cout << '\n';
    for (int i: razmaci) cout << i << " ";
    cout << '\n';
    #endif

    if (op > h) {
        h = max_op;
        for (int i: sirine) h += i;
        #ifdef debug
        cout << "op > sum(razmaci) " << n << " " << h << " " << min(n, h) << '\n';
        #endif
        return min(n, h);
    }

    while (i_d < l - 1) {

        while (op > 0 && i_d < l - 1) {

            r = min(op, popunjenost[i_d]);
            popunjenost[i_d] -= r;
            op -= r;
            d += r;

            if (popunjenost[i_d] == 0) {
                i_d++;
                d += sirine[i_d];
            }

        }

        d += op;
        if (d > mzd) mzd = d;
        d -= op;
        
        popunjenost[i_l] = razmaci[i_l];
        op += razmaci[i_l];
        d -= razmaci[i_l];
        d -= sirine[i_l];
        i_l++;

        if (i_d < l - 1 && razmaci[i_d] > max_op) {
            op = max_op;
            i_l++;
            i_d++;
            d = 0;
        }

    }

    #ifdef debug
    cout << '\n';
    #endif

    return mzd;

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int n, m;
    cin >> n;
    cin >> m;

    if (n == 1) {
        cin >> m;
        cout << 0 << '\n';
        return 0;
    }

    map<int, vector<pair<int, int>>> grupe;

    int pr;
    cin >> pr;
    int tr;
    int i0 = 0;
    for (int i = 1; i < n; i++) {
        cin >> tr;
        if (tr != pr) {
            if (grupe.count(pr) == 0) grupe[pr] = {};
            pair<int, int> grupa;
            grupa.first = i0;
            grupa.second = i - 1;
            grupe[pr].push_back(grupa);
            pr = tr;
            i0 = i;
        }
    }

    pair<int, int> grupa;
    grupa.first = i0;
    grupa.second = n - 1;
    grupe[tr].push_back(grupa);

    #ifdef debug
    for (int i = 0; i < 999999; i++) {
        if (grupe.count(i) > 0) cout << i << " " << grupe[i].size() << '\n';
    }
    #endif

    int mzd = -1;

    for (auto i: grupe) {
        int zd = max_zad_gr(i.first, grupe, m, n);
        if (zd > mzd) mzd = zd;
    }

    #ifdef debug
    cout << '\n';
    #endif

    cout << --mzd << '\n';

    return 0;

}