#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(void) {
    vector<int> a = {1, 1, 1, 2};
    int pr = a[0];
    int i0 = 0;
    int tr;
    for (int i = 1; i < a.size(); i++) {
        tr = a[i];
        if (tr != pr) {
            cout << pr << " " << i0 << " " << i - 1 << "\n";
            pr = tr;
            i0 = i;
        }
    }
    cout << tr << " " << i0 << " " << a.size() - 1 << "\n";
}