#include <iostream>
#include <vector>
#include <array>


void find_lowest_dist(int &n, int &d, std::vector<int> &line, int begin) {

    for (int i = begin; i < n; i++) {

        int new_d = 0;

        if (line[i] == line[n - i - 1]) continue;

        int temp = line[i];
        line[i] = line[n - i - 1];
        line[n - 1 - i] = temp;

        for (int j = 0; j < n; j++) if (line[j] == line[j + 1]) new_d++;

        if (new_d == d) {
            std::vector<int> another_line = line;
            find_lowest_dist(n, d, another_line, i + 1);

            int temp = line[i];
            line[i] = line[n - i - 1];
            line[n - 1 - i] = temp;
            
        }

        else if (new_d < d) {
            d = new_d;
        }

    }

}


void testcase(std::vector<int> &results) {

    int n;
    std::cin >> n;

    std::vector<int> line;
    int val;
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        line.push_back(val);
    }

    int d = 0;
    for (int i = 0; i < n - 1; i++) if (line[i] == line[i + 1]) d++;
    
    find_lowest_dist(n, d, line, 0);

    results.push_back(d);

}


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int cases;
    std::cin >> cases;

    std::vector<int> results;

    for (int i = 0; i < cases; i++) testcase(results);
    for (auto i: results) std::cout << i << '\n';

    return 0;
}