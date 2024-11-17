#include <iostream>
#include <vector>


void test_case(std::vector<std::string> &results) {

    int n;
    std::cin >> n;

    std::string seq;
    std::cin >> seq;

    int c0 = 0;
    int c1 = 0;
    int prev = 1;

    for (int i = 0; i < n; i++) {

        if (prev == 1 && seq[i] == '0') {
            c0++;
            prev = 0;
        }
        
        else if (prev == 0 && seq[i] == '0') {
            prev = 0;
        }

        else {
            c1++;
            prev = 1;
        }

    }

    #ifdef debug
    std::cout << c0 << " " << c1 << '\n';
    #endif

    if (c1 > c0) results.push_back("yes");
    else results.push_back("no");

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int cases;
    std::cin >> cases;

    std::vector<std::string> results;

    for (int i = 0; i < cases; i++) {
        test_case(results);
    }

    for (auto i: results) {
        std::cout << i << '\n';
    }

}