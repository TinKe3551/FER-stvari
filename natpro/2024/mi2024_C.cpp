#include <iostream>
#include <bits/stdc++.h>


using namespace std;


unordered_set<int> used;


pair<int, int> coords(int n) {
    pair<int, int> c;
    c.first = (n - 1) % 3 + 1;
    c.second = (n - 1) / 3 + 1;
    return c;
}


int neighbors(int n) {
    int nc = 0;
    pair<int, int> c1 = coords(n);
    for (int i: used) {
        pair<int, int> c2 = coords(i);
        if (abs(c1.first - c2.first) <= 1 && abs(c1.second - c2.second) <= 1) nc++;
    }
    return nc;
}


int main(void) {

    cout << 5 << endl;

    int t;
    cin >> t;

    used.insert(5);
    used.insert(t);

    while (t != 0 && t != -1) {

        int min = 9999;
        int choice = -1;

        for (int i = 1; i <= 9; i++) {

            if (used.count(i) == 0 && used.count(10 - i) == 0) {
                
                int n = neighbors(i);

                if (n < min) {
                    choice = i;
                    min = n;
                }
            }
            
        }

        cout << choice << endl;
        used.insert(choice);


        cin >> t;
        used.insert(t);

    }

    return 0;

}