#include <iostream>


int main(void) {

    using namespace std;

    srand(time(nullptr));

    int a = ((rand() % 100) | 1 ) ^ 1;

    cout << a << endl;

}