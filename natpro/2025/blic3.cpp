#include <bits/stdc++.h>
#define kol_prostih 500069


using namespace std;


int prosti[kol_prostih];


void preprostcess() {

    for (int i = 2; i * i < kol_prostih; i++) {

        if (prosti[i] != 0) continue;

        for (int j = i * i; j < kol_prostih; j += i) {

            if (prosti[j] == 0) prosti[j] = i;

        }

    }

}


map<int, int> prosti_faktori(int n) {

    map<int, int> faktori;
    
    while (prosti[n] != 0) {
        
        if (faktori.count(prosti[n]) == 0) faktori[prosti[n]] = 0;
        faktori[prosti[n]]++;

        n /= prosti[n];

    }

    if (faktori.count(n) == 0) faktori[prosti[n]] = 0;
    faktori[n]++;

    return faktori;

}


int primjer() {

    #ifdef verbose
    cout << "----------------\n";
    #endif

    int kol_operacija = 0;

    map<int, pair<int, int>> maks_kol_p_f;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        int a;
        cin >> a;

        map<int, int> faktori = prosti_faktori(a);

        for (auto f_k: faktori) {

            int faktor = f_k.first;
            int kolicina = f_k.second;

            if (faktor < 2) continue;

            if (maks_kol_p_f.count(faktor) == 0) maks_kol_p_f[faktor] = pair<int, int>(0, 0);

            if (kolicina % 2 == 0) {

                if (maks_kol_p_f[faktor].first < kolicina) {
                    maks_kol_p_f[faktor].first = kolicina;
                }

            }

            else {

                if (maks_kol_p_f[faktor].second < kolicina) {
                    maks_kol_p_f[faktor].second = kolicina;
                }

            }

        }

    }

    for (auto f_k: maks_kol_p_f) {

        int faktor = f_k.first;
        int parna_kol = f_k.second.first;
        int neparna_kol = f_k.second.second;

        #ifdef verbose
        cout << faktor << ' ' << parna_kol << ' ' << neparna_kol << '\n';
        #endif

        if (neparna_kol == 0) continue;

        if (parna_kol == 0) {
            kol_operacija++;
            continue;
        }

        if (neparna_kol < parna_kol) {
            kol_operacija += neparna_kol + 1;
            continue;
        }

        // neparna_kol > parna_kol
        kol_operacija += parna_kol + 1;

    }

    return kol_operacija;

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    preprostcess();

    int t;
    cin >> t;

    int rezultati[t] = {0};

    for (int i = 0; i < t; i++) {
        rezultati[i] = primjer();
    }

    #ifdef verbose
    cout << "================\n";
    #endif

    for(int i: rezultati) {
        cout << i << '\n';
    }

}