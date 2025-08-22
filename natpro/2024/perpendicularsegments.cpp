#define output_type std::vector<std::vector<int>>

#include <iostream>
#include <vector>


output_type testcase() {

    int X, Y, K;
    std::cin >> X;
    std::cin >> Y;
    std::cin >> K;
    std::vector<std::vector<int>> result;

    #ifdef debug
    std::cout << X << " " << Y << "\n";
    #endif

    if (X > Y) {
        result.push_back({0, 0, Y, Y});
        result.push_back({0, Y, Y, 0});
    }
    else {
        result.push_back({0, 0, X, X});
        result.push_back({0, X, X, 0});
    }

    return result;

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    bool multiple_test_cases = true;

    int cases = 1;
    if (multiple_test_cases) std::cin >> cases;

    std::vector<output_type> results;
    for (int i = 0; i < cases; i++) results.push_back(testcase());

    for (auto i: results) {
        for (auto j: i) {
            for (int k = 0; k < 3; k++) {
                std::cout << j[k] << " ";
            }
            std::cout << j[3] << "\n";
        }
    }

    return 0;
}
