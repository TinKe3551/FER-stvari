#include <iostream>
#include <vector>


void testcase(std::vector<int> &results) {

    int a, b;
    std::cin >> a;
    std::cin >> b;

    b = b - a;
    if (b <= 0) {
        results.push_back(a);
        return;
    }

    a -= b;
    if (a < 0) a = 0;

    results.push_back(a);

}


int main(void) {

    int cases;
    std::cin >> cases;

    std::vector<int> results;

    for (int i = 0; i < cases; i++) {

        testcase(results);

    }

    for (int i: results) {
        std::cout << i << '\n';
    }

}