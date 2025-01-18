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

    bool obojiv = false;

    stack<pair<int, int>> izmjene;
    stack<bool> pretrazi;

    izmjene.emplace(new pair<int, int>(0, 0));

    set<int> neispravni; // vrhovi koji imaju istu boju kao barem jedan njihov susjedni vrh

    while (!izmjene.empty() && obojiv) {

        pair<int, int> izmj = izmjene.top();
        izmjene.pop();
        
        boje[izmj.first] += izmj.second;

        long long stanje = hash_kod(n, k);
        if (stanja.count(stanje) > 0) continue;
        stanja.insert(stanje);

        neispravni.clear();
        obojiv = true;

        for (int i = 0; i < n; i++) {

            for (int j: susjedstva[i]) {

                if (boje[i] == boje[j]) {
                    neispravni.insert(i);
                    neispravni.insert(j);
                }

            }

        }

    }

    cout << obojiv << '\n';

    return 0;

}


