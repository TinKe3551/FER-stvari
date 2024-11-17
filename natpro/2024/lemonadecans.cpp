#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


void testcase(std::vector<int> &results) {

    std::cout << "--------\n";

    std::unordered_map<int, int> slots;
    std::vector<int> amounts;

    int n, k;
    std::cin >> n;
    std::cin >> k;

    int empty = 0;

    int cans = 0;
    int presses = 0;

    for (int i = 0; i < n; i++) {

        int input;
        std::cin >> input;

        if (slots.count(input) == 0) {
            slots[input] = 0;
            amounts.push_back(input);
        }

        slots[input]++;
    }
    amounts.push_back(0);
    sort(amounts.begin(), amounts.end());

    for (int i = 1; i < amounts.size(); i++) {
        std::cout << amounts[i] << " " << slots[amounts[i]] << '\n';

        int max_loops = amounts[i] - amounts[i - 1];

        int cans_per_loop = n - empty;

        int loops = (k - cans) / cans_per_loop;
        if (loops > max_loops) loops = max_loops;

        presses += n * loops;
        cans += cans_per_loop * loops;

        if (k - cans <= cans_per_loop && loops < max_loops) {
            presses += k - cans + empty;
            cans += k - cans;
        }

        if (cans == k) {
            results.push_back(presses);
            return;
        }

        empty += slots[amounts[i]];

    }

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int cases;
    std::cin >> cases;

    std::vector<int> results;

    for (int i = 0; i < cases; i++) {

        testcase(results);

    }

    std::cout << "results:\n";

    for (int i: results) {
        std::cout << i << '\n';
    }

}