#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>


std::set<int> brojevi;
std::set<int> za_pregledati;

int pot_grupe[21] = {0};

int pozivi[2];


int log2(int n) {
    int l = -1;
    while (n > 0) {
        n >>= 1;
        l++;
    }
    return l;
}


int najv_gar() {
    int ng = 1;
    for (int i = 0; i < 20; i++) {
        if (pot_grupe[i] == 1) ng <<= 1;
        else break;
    }
    return ng - 1;
}


void dodaj(int b) {

    pozivi[0]++;

    if (b == 0) return;

    if (brojevi.count(b) == 0) {

        brojevi.insert(b);
        za_pregledati.insert(b);

        pot_grupe[log2(b)] = 1;

        pozivi[1]++;

    }

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int n;
    std::cin >> n;

    int kuce[n] = {0};
    int trazeno[n] = {0};

    for (int i = n - 1; i >= 0; i--) std::cin >> kuce[i];
    for (int i = n - 1; i >= 0; i--) std::cin >> trazeno[i];

    int dobri = 0;

    for (int i = 0; i < n; i++) {

        std::set<int> pregledaj;
        std::unordered_set<int> otkriveni;

        dodaj(kuce[i]);

        int ng = najv_gar();

        if (trazeno[i] == 0 || brojevi.count(trazeno[i]) > 0 || trazeno[i] <= ng) {
            dobri++;
            continue;
        }

        int l = log2(trazeno[i]);

        do {

            pregledaj = za_pregledati;
            otkriveni = {};

            for (int b1: pregledaj) {

                if (b1 <= ng) {
                    za_pregledati.erase(b1);
                    continue;
                }

                int l1 = log2(b1);

                for (int b2: brojevi) {

                    if (log2(b2) > l1 + 1) break;

                    otkriveni.insert(b1 ^ b2);

                    if (otkriveni.count(trazeno[i]) > 0) break;

                }

                if (otkriveni.count(trazeno[i]) > 0) break;

                za_pregledati.erase(b1);

            }

            for (int b: otkriveni) dodaj(b);

        } while (!otkriveni.empty() && brojevi.count(trazeno[i]) == 0);

        dobri += brojevi.count(trazeno[i]);

    }

    #ifdef debug
    for (int i: pozivi) std::cout << i << " ";
    #endif
    
    std::cout << dobri << "\n";

    return 0;
}