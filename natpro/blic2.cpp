#include <iostream>
#include <unordered_set>
#include <unordered_map>

#define kol_prostih 1000100


int prosti[kol_prostih];

void preprostcess() {

    int k = 1;

    for (int i = 2; i * i < kol_prostih; i++) {

        if (prosti[i] != 0) continue;

        k *= i;

        for (int j = i * i; j < kol_prostih; j += k) {

            if (prosti[j] == 0) prosti[j] = i;

        }

    }

}


std::unordered_set<int> prosti_faktori (int n) {

    std::unordered_set<int> faktori;
    
    while (prosti[n] != 0) {
        faktori.insert(prosti[n]);
        n /= prosti[n];
    }

    faktori.insert(n);

    return faktori;

}


int main(void) {

    #ifdef debug
    freopen("~/FER-stvari/natpro/input", "r", stdin);
    #endif

    preprostcess();

    int n;
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::unordered_map<int, int> moguci;

    for (int i: a) {

        for (int j: prosti_faktori(i)) {

            if (moguci.count(j) == 0) moguci[j] = 0;
            moguci[j]++;

        }

    }

    int k = 0;
    int x = 0;

    for (auto i: moguci) {

        if (i.second > x) {
            k = i.first;
            x = i.second;
        }

    }

    std::cout << k << " " << x << "\n";

    return 0;
}