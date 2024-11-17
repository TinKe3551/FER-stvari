#include <iostream>
#include <set>


int pot_grupe[21];
std::set<int> brojevi[20];
std::set<int> za_pregledati[20];


void dodaj(int n) {

    int l = pot_grupe[20];

    if (brojevi[l].count((n >> l) << l) > 0) return;

    for (int i = 0; i < 20; i++) {
        brojevi[i].insert((n >> l) << l);
    }
}


int provjeri(int kuca, int trazeno) {

    dodaj(kuca);

    if (brojevi[pot_grupe[20]].count(trazeno) > 0) return 1;

}


int main(void) {

    for (int i = 0; i < 20; i++) brojevi[i].insert(0);

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int n;
    std::cin >> n;

    int kuce[n];
    for (int i = n - 1; i >= 0; i--) std::cin >> kuce[i];

    int trazeno[n];
    for (int i = n - 1; i >= 0; i--) std::cin >> kuce[i];

    int dobri = 0;

    for (int i = 0; i < n; i++) {
        dobri += provjeri(kuce[i], trazeno[i]);
    }

    std::cout << dobri;

}