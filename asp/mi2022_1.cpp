#include <iostream>


using namespace std;


int zamijeniParne(int A[], int n) {

    if (n <= 1) return 0;

    int z = 0;

    if (A[0] % 2 == 0 && A[n - 1] % 2 == 0) {

        int tmp = A[0];
        A[0] = A[n - 1];
        A[n - 1] = tmp;
        z += 1 + zamijeniParne(&A[1], n - 2);
    }

    else if (A[0] % 2 == 1) {
        z += zamijeniParne(&A[1], n - 1);
    }

    else if (A[n - 1] % 2 == 1) {
        z += zamijeniParne(&A[0], n - 1);
    }

    else {
        z += zamijeniParne(&A[1], n - 2);
    }

    return z;

}


int main(void) {

    int A[] = {3, 1, 10, 2, 5, 6, 7, 8, 9, 1};
    int z = zamijeniParne(A, size(A));

    for (int i: A) cout << i << " ";
    cout << '\n';

    cout << z << '\n';

    return 0;

}
