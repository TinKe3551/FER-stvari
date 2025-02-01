#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(void) {

    set<int> x_razine;
    map<int, set<int>> y_po_x_razinama;

    set<int> y_koordinate;
    map<pair<int, int>, int> lijevo;
    map<pair<int, int>, int> dolje_t;

    map<int, set<pair<int, int>>> duzine;
    map<pair<int, pair<int, int>>, int> dolje_d;

    long long P = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        int x[2];
        int y[2];
        cin >> x[0];
        cin >> y[0];
        cin >> x[1];
        cin >> y[1];

        for (int j = 0; j < 2; j++) {

            x_razine.insert(x[j]);

            for (int k = 0; k < 2; k++) {

                y_po_x_razinama[x[j]].insert(y[k]);

                lijevo[pair<int, int>(x[j], y[k])] = bool(j==0);

                pair<int, int> tocka = pair<int, int>(x[j], y[k]);
                if (dolje_t.count(tocka) == 0) dolje_t[tocka] = 0;
                if (k == 0) dolje_t[tocka]++;
                else dolje_t[tocka]--;


                if (j == 1) continue;
                pair<int, pair<int, int>> duzina = pair<int, pair<int, int>>(y[k], pair<int, int>(x[0], x[1]));
                duzine[duzina.first].insert(duzina.second);
                if (dolje_d.count(duzina) == 0) dolje_d[duzina] = 0;
                if (k == 0) dolje_d[duzina]++;
                else dolje_d[duzina]--;
                
            }

        }


    }

    int A;
    cin >> A;

    while (1) {

        int x = *(x_razine.begin());
        x_razine.erase(x);

        #ifdef debug
        cout << "x = " << x << '\n';
        #endif

        int faktor = 0;
        int y0 = *(y_koordinate.begin());
        int m = 0;

        for (int y: y_po_x_razinama[x]) {

            pair<int, int> tocka = pair<int, int>(x, y);

            // if(dolje_t[tocka]) m++;
            // else m--;
            if (m == 0) y0 = y;
            m += dolje_t[tocka];

            if (m == 0) {
                faktor += y - y0 + 1;
                y0 = y;
            }

            if (lijevo[tocka]) y_koordinate.insert(y);
            else y_koordinate.erase(y);

        }

        #ifdef debug
        cout << "povrsina na ovoj x koordinati: " << faktor << '\n';
        #endif

        P += faktor;

        if (x_razine.empty()) break;

        faktor = 0;
        y0 = *(y_koordinate.begin());
        m = 0;

        for (int y: y_koordinate) {

            for (auto d: duzine[y]) {

                pair<int, pair<int, int>> duzina = pair<int, pair<int, int>>(y, pair<int, int>(d.first, d.second));

                // if (dolje_d[duzina]) m++;
                // else m--;
                if (m == 0) y0 = y;
                m += dolje_d[duzina];

                if (m == 0) {
                    faktor += y - y0 + 1;
                    y0 = y;
                }

            }

        }

        #ifdef debug
        cout << "relevantne y koordinate: "; for (int y: y_koordinate) cout << y << ' '; cout << '\n';
        cout << "faktor za ovaj sloj: " << faktor << '\n';
        #endif

        P += faktor * (*(x_razine.begin()) - x - 1);

    }

    #ifdef debug
    cout << "P = " << P << '\n';
    #endif

    if (P == A) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
