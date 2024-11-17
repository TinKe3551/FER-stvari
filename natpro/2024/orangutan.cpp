#include <iostream>
#include <vector>


int main(void) {

    int testcases;
    std::cin >> testcases;

    int results[testcases];

    int min;
    int max;

    for (int i = 0; i < testcases; i++) {

        int n;
        std::cin >> n;

        min = 9999;
        max = -1;

        for (int j = 0; j < n; j++) {
            int in;
            std::cin >> in;
            if (in > max) max = in;
            if (in < min) min = in;
        }

        results[i] = (max - min) * ((n + 1) / 2);

    }

    for (int i = 0; i < testcases; i++) {
        std::cout << results[i] << '\n';
    }

}