#include <iostream>
#include <vector>
#include <unordered_map>


int main(void) {

    #ifdef debug
    freopen("input", "r", stdin);
    #endif

    int n;
    std::cin >> n;

    std::unordered_map<int, int> numbers;
    int max = 0;

    for (int i = 0; i < n; i++) {

        int input;
        std::cin >> input;

        if (numbers.count(input) == 0) numbers[input] = 0;
        numbers[input]++;

        if (input > max) max = input;
    }
    
    
    std::vector<int> twopows;
    for (int i = 2; i < max * 4; i *= 2) twopows.push_back(i);

    int remove = 0;

    for (auto& num: numbers) {

       #ifdef debug
       std::cout << num.first << " ";
       #endif

        bool do_remove = true;

        for (int i = twopows.size() - 1; i >= 0; i--) {

            int other = twopows[i] - num.first;

            #ifdef debug
            std::cout << other;
            #endif

            if (numbers.count(other) == 0) {;}
            else if (other == num.first && num.second == 1) {;}
            else {
                do_remove = false;

                #ifdef debug
                std::cout << "yes";
                #endif
            }

            #ifdef debug
            std::cout << " ";
            #endif

        }

        if (do_remove) remove += num.second;
        
        #ifdef debug
        std::cout << remove << "\n";
        #endif

    }

    std::cout << remove << "\n";

}