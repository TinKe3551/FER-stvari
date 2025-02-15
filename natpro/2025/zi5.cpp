#include <iostream>
#include <bits/stdc++.h>


using namespace std;


// int preproc()


int main(void) {

    unordered_map<int, unordered_set<int>> podv;
    unordered_map<int, int> nadv;

    int n;
    cin >> n;
    unordered_set<int> vrhovi;

    for (int i = 1; i < n; i++) {

        int v1, v2;
        cin >> v1;
        cin >> v2;

        nadv[v2] = v1;

    }

    for (int v1 = 1; v1 <= n; v1++) {

        vrhovi.insert(v1);
        
        if (nadv.count(v1) == 0) continue;
        
        int v2 = nadv[v1];
        podv[v2].insert(v1);

        while (nadv.count(v2) > 0) {
            v2 = nadv[v2];
            podv[v2].insert(v1);
        }


    }

    #ifdef debug
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j: podv[i]) cout << j << ' ';
        cout << endl;
    }
    #endif

    int x, y;

    while(true) {

        cout << "----------------\n";

        x = *(vrhovi.begin());

        for (int v: vrhovi) {

            double t0 = vrhovi.size();
            t0 /= 2;
            double t1 = podv[x].size();
            double t2 = podv[v].size();

            #ifdef debug
            cout << t0 << '\n';
            cout << x << ' ' << t1 << '\n';
            cout << v << ' ' << t2 << '\n';
            cout << "\n";
            #endif
            
            if (abs(t2 - t0) <= abs(t1 - t0)) x = v;

        }

        cout << x << endl;

        cin >> y;

        if (y == -1) break;

        if (podv[x].count(y) == 0) {
            for (int v: podv[x]) vrhovi.erase(v);
            vrhovi.erase(x);
        }

        else {
            vrhovi = podv[x];
        }

    }

    return 0;

}