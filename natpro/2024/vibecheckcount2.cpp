#include <iostream>
#include <set>


int pot_grupe[21];
std::set<int> brojevi;
std::set<int> za_pregledati;

int pozivi[2];


int log2(int n) {
    int l = -1;
    while (n > 0) {
        n >>= 1;
        l++;
    }
    return l;
}


bool dodaj(int b) {

    pozivi[0]++;

    if (b == 0) return false;

    if (brojevi.count(b) == 0) {
        brojevi.insert(b);
        za_pregledati.insert(b);
        pot_grupe[log2(b)] = 1;
        pozivi[1]++;
        return true;
    }

    return false;

}


void osvjezi(int &tr) {

    int l = 0;
    while (pot_grupe[l] == 1 && l < 20) l++;
    l--;

    // std::cout << l << " ";

    if (l <= pot_grupe[20]) {
        l = pot_grupe[20];
        tr = (tr >> l) << l;
        return;
    }

    // std::cout << "ide" << "\n";
    // std::cout << "prije > " << brojevi.size() << " " << za_pregledati.size() << "\n";
    // for (int i: brojevi) std::cout << i << " ";
    // std::cout << "\n";

    pot_grupe[20] = l;

    tr = (tr >> l) << l;

    std::set<int> brojevi2;
    for (int i: brojevi) {
        brojevi2.insert((i >> l) << l);
        // std::cout << i << " " << ((i >> l) << l) << "\n";
    }
    brojevi.clear();
    for (int i: brojevi2) brojevi.insert(i);

    std::set<int> za_pregledati2 = za_pregledati;
    za_pregledati.clear();
    for (int i: za_pregledati2) dodaj((i >> l) << l);

    // std::cout << "poslije > " << brojevi.size() << " " << za_pregledati.size() << "\n";
    // for (int i: brojevi) std::cout << i << " ";
    // std::cout << "\n";
    

}


int pregledaj (int kuca, int trazeno) {

    osvjezi(trazeno);

    int l = pot_grupe[21];
    dodaj((kuca >> l) << l);

    if (trazeno == 0) return 1;
    if (brojevi.count(trazeno) > 0) return 1;

    std::set<int> pregledaj;
    std::set<int> otkriveni;

    bool nastavi;
    do {

        nastavi = false;

        osvjezi(trazeno);
        if (trazeno == 0) return 1;

        pregledaj = za_pregledati;
        otkriveni = {};

        for (int b1: pregledaj) {

            for (int b2: brojevi) {

                otkriveni.insert(b1 ^ b2);

            }

            za_pregledati.erase(b1);

        }

        for (int b: otkriveni) nastavi = nastavi || dodaj(b);

    } while(nastavi);

    return brojevi.count(trazeno);

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int n;
    std::cin >> n;

    int kuce[n];
    for (int i = n - 1; i >= 0; i--) std::cin >> kuce[i];

    int trazeno[n];
    for (int i = n - 1; i >= 0; i--) std::cin >> trazeno[i];

    int dobri = 0;
    for (int i = 0; i < n; i++) {
        dobri += pregledaj(kuce[i], trazeno[i]);
    }

    #ifdef debug
    for (int i: pozivi) std::cout << i << " ";
    #endif
    
    std::cout << dobri << "\n";

    return 0;
}