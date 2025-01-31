#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(void) {

    set<int> x_razine;
    map<int, set<int>> y_po_x_razinama;
    set<int> y_koordinate;
    map<pair<int, int>, bool> lijevo;
    map<pair<int, int>, bool> dolje;
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

        dolje[pair<int, int>(x1, y1)] = true;
        dolje[pair<int, int>(x1, y2)] = false;
        dolje[pair<int, int>(x2, y1)] = true;
        dolje[pair<int, int>(x2, y2)] = false;

    }

    while (x_razine.size() > 1) {

        int x = *(x_razine.begin());

        for (int y: y_po_x_razinama[x]) {

            pair<int, int> tocka = pair<int, int>(x, y);

            if (lijevo[tocka]) y_koordinate.insert(y);
            else y_koordinate.erase(y);

        }

        x_razine.erase(x);

        cout << "x = " << x << '\n';
        cout << "relevantne y koordinate: "; for (int y: y_koordinate) cout << y << ' '; cout << '\n';

    }

    return 0;
}