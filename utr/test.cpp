#include <bits/stdc++.h>


using namespace std;


int main(void) {

    string a = "aaaAaaaa";
    string b = "bbb";

    int i = 3;

    cout << a << "\n";

    a = a.substr(0, i) + b + a.substr(i + 1);

    cout << a << "\n";

    a = a.substr(0, i) + 'A' + a.substr(i + b.size());

    cout << a << endl;

    return 0;

}