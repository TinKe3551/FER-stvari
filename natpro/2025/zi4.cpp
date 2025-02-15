#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int main(void) {

    int n, m;
    cin >> n;
    cin >> m;

    unordered_map<int, unordered_set<int>> povezani;
    unordered_set<int> pregledani;
    vector<int> pocetni;
    int najv = 0;

    for (int i = 0; i < n; i++) {
        int v1, v2;
        cin >> v1;
        cin >> v2;
        povezani[v1].insert(v2);
        povezani[v2].insert(v1);
    }

    for (int i = 1; i <= n; i++) pocetni.push_back(i);

    for(int p: pocetni) {

        if (pregledani.count(p) > 0) continue;

        queue<int> vrhovi;
        vrhovi.emplace(p);
        int vel = 0;

        #ifdef debug
        cout << "\n----------------";
        #endif

        while (!vrhovi.empty()) {

            int v1 = vrhovi.front();
            vrhovi.pop();

            #ifdef debug
            cout << '\n' << v1;
            #endif

            if (pregledani.count(v1) > 0) continue;
            pregledani.emplace(v1);
            vel++;

            #ifdef debug
            cout << ": ";
            #endif

            for (int v2: povezani[v1]) {
                vrhovi.emplace(v2);
                
                #ifdef debug
                cout << v2 << ' ';
                #endif
            }

        }

        najv = max(najv, vel);

    }

    #ifdef debug
    cout << "\n----------------\n";
    #endif

    cout << najv << '\n';

    return 0;

}