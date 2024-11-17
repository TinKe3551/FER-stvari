#include <iostream>
#include <vector>


using std::cin, std::cout, std::vector;


int testcase() {

    int n;
    cin >> n;

    int pillars[n + 10];
    for (int i = 1; i <= n; i++) cin >> pillars[i];

    int max = 0;
    int cur = 0;
    
    for (int i = 1; i <= n; i++) {
        if (pillars[i] == pillars[i - 1]) cur++;
        else cur = 1;
        if (cur > max) max = cur;
    }

    return n - max;
}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int cases;
    cin >> cases;

    int results[cases];
    for (int i = 0; i < cases; i++) {
        results[i] = testcase();
    }

    for (auto i: results) cout << i << '\n';

    return 0;
}