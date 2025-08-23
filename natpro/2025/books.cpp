#include <bits/stdc++.h>


int main(void) {

    using namespace std;

    int n;
    cin >> n;

    int t;
    cin >> t;

    int books_times[n];

    for (int i = 0; i < n; i++) {
        cin >> books_times[i];
    }

    int max_books = 0;
    int books = 0;
    int time = 0;

    int i = 0;
    int j = 0;

    while (j < n) {

        if (time + books_times[j] > t) {

            time -= books_times[i];
            i++;

            books--;
        }

        else {

            time += books_times[j];
            j++;

            books++;
            if (books > max_books) {
                max_books = books;
            }

        }

        #ifdef debug
        cout << books << " " << time << "\n";
        #endif

    }

    cout << max_books << "\n";

    return 0;

}
