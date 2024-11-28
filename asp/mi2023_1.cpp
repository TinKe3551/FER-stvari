#include <iostream>

using std::cin, std::cout, std::string;

int brojIzStringa(string niz) {

    int n = 0;

    if (niz[0] == '\0') {
        return 0;
    }

    else if (niz[1] == '\0') {
        return niz[0] - '0';
    }

    else {
        n += 10 * brojIzStringa(&niz[2]);
        n += niz[0] - '0';
        return n;
    }

}

int main(void) {
    
    freopen("input", "r", stdin);

    string unos;
    cin >> unos;

    cout << brojIzStringa(unos) << '\n';

    return 0;

}