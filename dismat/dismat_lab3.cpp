#include <iostream>
#include <bits/stdc++.h>


using namespace std;


map<int, vector<int>> susjedstva;
vector<int> boje;

//jebem ti ja git

bool slj(int n, int k) {

    for (int i = 0; i < n; i++) {

        boje[i]++;
        boje[i] %= k;

        if (boje[i] > 0) break;

    }

    // u početnom stanju popisa boja, u njemu se nalaze samo nule
    // ako se popis opet nađe u takvom stanju, to znači
    // da su sve moguće kombinacije boja isprobane

    
    for (int i = 0; i < n; i++) {
        // barem jedan broj različit od nule
        if (boje[i] != 0) return true;
    }

    // samo nule
    return false;

}


int main(void) {
    
    string  dat;

    #ifndef debug
    cin >> dat;
    #endif

    #ifdef debug
    dat = "graf.txt";
    #endif

    freopen(dat.c_str(), "r", stdin);

    int n, k;
    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++) {

        string redak;
        cin >> redak;

        susjedstva[i + 1] = {};
        boje.push_back(0);

        for (int j = 0; j < n; j++) {

            if (redak[j] == '1') susjedstva[i + 1].push_back(j + 1);

        }

    }

    #ifdef debug
    for (int i = 0; i < n; i++) {

        cout << i << ":";
        for (int j: susjedstva[i]) cout << " " << j;

        cout << '\n';

    }
    #endif


    bool obojiv = false;

    while (slj(n, k) && !obojiv) {

        for (int i: boje) cout << i << " ";
        cout << '\n';

        obojiv = true;

        for (int i = 0; i < n && obojiv; i++) {

            for (int j: susjedstva[i]) {

                if (boje[i] != boje[j]) continue;

                obojiv = false;
                break;

            }

        }

    }

    cout << (int)obojiv << endl;

    return 0;

}