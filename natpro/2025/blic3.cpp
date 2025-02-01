#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(void) {

    set<int> x_razine;
    map<int, set<int>> y_po_x_razinama;

    set<int> y_koordinate;
    map<pair<int, int>, bool> lijevo;
    map<pair<int, int>, bool> dolje_t;

    map<int, set<pair<int, int>>> duzine;
    map<pair<int, pair<int, int>>, bool> dolje_d;

    long long P = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        int x1, y1, x2, y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;

        x_razine.insert(x1);
        x_razine.insert(x2);

        y_po_x_razinama[x1].insert(y1);
        y_po_x_razinama[x1].insert(y2);
        y_po_x_razinama[x2].insert(y1);
        y_po_x_razinama[x2].insert(y2);

        lijevo[pair<int, int>(x1, y1)] = true;
        lijevo[pair<int, int>(x1, y2)] = true;
        lijevo[pair<int, int>(x2, y1)] = false;
        lijevo[pair<int, int>(x2, y2)] = false;

        dolje_t[pair<int, int>(x1, y1)] = true;
        dolje_t[pair<int, int>(x1, y2)] = false;
        dolje_t[pair<int, int>(x2, y1)] = true;
        dolje_t[pair<int, int>(x2, y2)] = false;

        duzine[y1].insert(pair<int, int>(x1, x2));
        duzine[y2].insert(pair<int, int>(x1, x2));

        dolje_d[pair<int, pair<int, int>>(y1, pair<int, int>(x1, x2))] = true;
        dolje_d[pair<int, pair<int, int>>(y2, pair<int, int>(x1, x2))] = false;


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

            if(dolje_t[tocka]) m++;
            else m--;

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

                if (dolje_d[duzina]) m++;
                else m--;

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
