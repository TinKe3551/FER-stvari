#include <iostream>


using std::cin, std::cout, std::string;


string testcase() {



    return "bruh";
}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int t;
    cin >> t;

    string r[t];
    for (int i = 0; i < t; i++) r[i] = testcase();

    for (auto i: r) cout << i << '\n';

    return 0;
}