#include <iostream>
#include <deque>


using namespace std;


int main(void) {

    deque<string> bla;
    string blabla = "blablabla";

    for (int i = 0; i < blabla.size(); i++) {
        bla.emplace_back(blabla[i]);
    }

    for (auto i: bla) {
        cout << i << "\n";
    }

    return 0;

}