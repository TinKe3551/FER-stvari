#include <iostream>


using std::cin, std::cout, std::string;


string testcase() {

    int n;
    cin >> n;

    int sticks[n + 10];
    for (int i = 1; i <= n; i++) cin >> sticks[i];

    for (int i = 1; i <= n; i++) {

        int e = sticks[i];
        int b = i;
        if (b > e) {
            int temp = b;
            b = e;
            e = temp;
        }

        for (int j = b; j <= e; j++) {
            // cout << sticks[i] << " " << sticks[j] << '\n';
            if (abs(sticks[i] - sticks[j]) > 1) return "no";
        }
        
    }

    return "yes";
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