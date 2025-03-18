#include <iostream>
#include <deque>
#include <string>
#include <csignal>


using namespace std;


int K_Z[5] = {0};
deque<string> suSto;


void ispis_stanja(int T_P) {

    cout << "K_Z: ";
    for (int i: K_Z) cout << i;
    cout << '\n';

    cout << "T_P: ";
    for (int i = 1; i < T_P; i++) cout << 0;
    cout << 1;
    for (int i = 0; i < 5 - T_P; i++) cout << 0;
    cout << '\n';

    cout << "sistemski stog (od najkasnije dodanog do najranije dodanog elementa):\n";
    for (string i: suSto) {
        cout << i << '\n';
    }

    

}


void obrada_signala(int signal) {
    if (signal == SIGINT) ispis_stanja(5);
    exit(1);
}


int main(void) {

    signal(SIGINT, obrada_signala);

    for (;;) {
        
        
        
    }

    return 0;

}