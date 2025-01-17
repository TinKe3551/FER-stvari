#include <iostream>
#include <bits/stdc++.h>


#define vpb 9223372036854775783
#define verbint 1


using namespace std;


map<int, vector<int>> susjedstva;
vector<int> boje;
set<long long> stanja;


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


bool provjeri(bool &obojiv, int &n) {

    if (obojiv) return true;

    for (int i = 0; i < n; i++) {

        for (int j: susjedstva[i]) {

            if (boje[i] == boje[j]) {
                return false;
            }

        }

    }

    obojiv = true;

    #ifdef debug
    cout << "----------------\n";
    cout << "pronađen način bojanja: ";
    for (int i: boje) cout << i << " ";
    cout << '\n';
    #endif

    return true;

}


void boji(bool &obojiv, int &n, int &k, int dubina, int &kol_poziva) {

    kol_poziva++;

    if (provjeri(obojiv, n)) return;

    #ifdef verbose
    if (stanja.size() % verbint == 0) {
        cout << "----------------\n";
        cout << dubina << ". razina rekurzije\n";
    }
    #endif

    long long stanje = hash_kod(n, k);

    #ifdef verbose
    if (stanja.size() % verbint == 0) {
        cout << "kod stanja: " << stanje << '\n';
        cout << "boje: "; for (int i: boje) cout << i << " "; cout << '\n';
        cout << "stanje već prije zabilježeno: " << stanja.count(stanje) << '\n';
        cout << "dosada zabilježeno stanja: " << stanja.size() << '\n';
    }
    #endif

    if (stanja.count(stanje) > 0) return;
    stanja.insert(stanje);

    bool obojan = true;

    set<int> promijeniti;

    for (int i = 0; i < n; i++) {

        for (int j: susjedstva[i]) {

            if (boje[i] == boje[j]) {
                
                obojan = false;

                promijeniti.insert(i);
                promijeniti.insert(j);

            }

        }

    }

    for (int i: promijeniti) {

        boje[i]++;
        if (boje[i] < k) boji(obojiv, n, k, dubina + 1, kol_poziva);
        boje[i]--;

        boje[i]--;
        if (boje[i] > 0) boji(obojiv, n, k, dubina + 1, kol_poziva);
        boje[i]++;

    }

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

    int max_deg = 0;
    bool potpun = true;

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

        if (deg > max_deg) max_deg = deg;
        if (deg < n - 1) potpun = false;

    }

    #ifdef verbose
    
    cout << "najveći stupanj: " << max_deg << '\n';

    if (potpun) cout << "graf je potpun\n";
    else cout << "graf nije potpun\n";

    for (int i = 0; i < n; i++) {

        cout << i << ":";
        for (int j: susjedstva[i]) cout << " " << j;

        cout << '\n';

    }
    #endif


    bool obojiv = k >= max_deg;
    if (potpun && k < n) {
        cout << 0;
        return 0;
    }

    int kol_poziva = 0;

    boji(obojiv, n, k, 0, kol_poziva);

    cout << obojiv << '\n';

    #ifdef debug
    cout << "količina poziva funkcije: " << kol_poziva << '\n';
    #endif

    return 0;

}


