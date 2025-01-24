#include <iostream>
#include <bits/stdc++.h>


#define vpb 9223372036854775783
#define interval 1000000


using namespace std;


map<int, vector<int>> susjedstva;
vector<int> boje;
unordered_set<long long> stanja;


long long hash_kod(int &n, int &k) {

    long long h = 0;

    long long m = 1;

    map<int, int> preslikavanje;
    int slj = 0;

    #ifdef verbose
    cout << "preslikane boje: ";
    #endif
    
    for (int i = 0; i < n; i++) {

        if (preslikavanje.count(boje[i]) == 0) preslikavanje[boje[i]] = slj++;
        //if (preslikavanje.count(boje[i]) == 0) preslikavanje[boje[i]] = boje[i];
        int j = preslikavanje[boje[i]];

        #ifdef verbose
        cout << j << " ";
        #endif

        m *= k;
        m %= vpb;
        h += (m * j) % vpb;

    }

    #ifdef verbose
    cout << '\n';
    #endif

    return h;

}


int main(void) {
    
    string  dat;

    #ifndef debug
    cout << "naziv datoteke sa grafom > ";
    cin >> dat;
    #endif

    #ifdef debug
    dat = "graf.txt";
    #endif

    freopen(dat.c_str(), "r", stdin);

    int n, k;
    cin >> n;
    cin >> k;

    // čitanje matrice

    for (int i = 0; i < n; i++) {

        string redak;
        cin >> redak;

        susjedstva[i + 1] = {};
        boje.push_back(0);

        int deg = 0;

        for (int j = 0; j < n; j++) {

            if (redak[j] == '1') {
                susjedstva[i].push_back(j);
                deg++;
            }

        }

    }

    // inicijalizacija varijabli za pretraživanje obojivosti

    bool obojiv = false;

    stack<pair<int, int>> izmjene;

    izmjene.emplace(pair<int, int>(0, 0));

    set<int> neispravni; // vrhovi koji imaju istu boju kao barem jedan njihov susjedni vrh

    int kol_stanja = 0;
    double t = clock();

    // pretraživanje obojivosti

    while (!izmjene.empty() && !obojiv) {

        kol_stanja++;

        // if (kol_stanja % interval == 0) {

        //     if ((clock() - t) / CLOCKS_PER_SEC > n) {

        //         cout << 0 << '\n';
        //         return 0;

        //     }

        // }

        pair<int, int> izmj = izmjene.top();
        izmjene.pop();
        
        boje[izmj.first] += izmj.second;

        long long kod_stanja = hash_kod(n, k);
        
        #ifdef verbose
        cout << "--------------------------------\n";
        cout << "broj obiđenih stanja: " << kol_stanja << '\n';
        cout << "boje: "; for (int i: boje) cout << i << " "; cout << '\n';
        cout << "broj stanja za obići: " << izmjene.size() << '\n';
        cout << "je li ovakvo stanje već obiđeno prije: " << stanja.count(kod_stanja) << '\n';
        cout << "broj jedinstvenih obiđenih stanja: " << stanja.size() << '\n';
        #endif

        if (stanja.count(kod_stanja) > 0) continue;
        stanja.insert(kod_stanja);

        neispravni.clear();
        obojiv = true;

        for (int i = 0; i < n; i++) {

            for (int j: susjedstva[i]) {

                if (boje[i] == boje[j]) {
                    neispravni.insert(i);
                    neispravni.insert(j);
                    obojiv = false;
                }

            }

        }

        for (int i: neispravni) {
            if (boje[i] + 1 < k) {
                izmjene.emplace(pair<int, int>(i, -1));
                izmjene.emplace(pair<int, int>(i, 1));
            }
            if (boje[i] > 0) {
                izmjene.emplace(pair<int, int>(i, 1));
                izmjene.emplace(pair<int, int>(i, -1));
            }
        }

    }

    #ifdef debug
    if (obojiv) {
        cout << "pronađen način bojanja: "; for (int i: boje) cout << i << " "; cout << '\n';
    }
    #endif

    cout << obojiv << '\n';

    return 0;

}


