#define output_type int

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


output_type testcase() {

    int n;
    std::cin >> n;

    int a1;
    std::cin >> a1;

    int a2;

    std::unordered_map<int, int> diff_counts;
    std::priority_queue<int> diffs;

    int last_app;

    for (int i = 1; i < n; i++) {
        
        std::cin >> a2;

        int diff = a2 - a1;
        a1 = a2;


        if (diff_counts.count(diff) == 0) {


            diff_counts.emplace(diff, 1);
            diffs.emplace(diff);

        }
        else {


            diff_counts[diff]++;

        }

        if (diff >= diffs.top()) last_app = i;

    }

    #ifdef debug
    std::cout << "--------\n";
    #endif


    if (n == 1) return 1;

    int mdiff = diffs.top();
    int mdiff2;
    if (!diffs.empty()) {
        diffs.pop();
        mdiff2 = diffs.top();
    }
    else {
        mdiff2 = mdiff;
    }


    


    if (diff_counts[mdiff] == 1) return mdiff2;
    else return mdiff;

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


    for (auto i: results) std::cout << i << '\n';

    return 0;
}