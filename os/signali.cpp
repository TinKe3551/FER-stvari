#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <csignal>
#include <map>


using namespace std;


int K_Z[5] = {0};
deque<string> suSto;
priority_queue<int> pokrenute_obrade;
map<string, int> ostalo;


void ispis_stanja(int T_P, string radnja) {

    cout << "radnja: " << radnja << '\n';

    cout << "K_Z: ";
    for (int i: K_Z) cout << i;
    cout << '\n';

    string TPbin = "";
    for (int i = 1; i < T_P; i++) TPbin += "0";
    TPbin += "1";
    for (int i = 0; i < 5 - T_P; i++) TPbin += "0";
    cout << "T_P: " << TPbin << '\n';

    cout << "sistemski stog (od najkasnije dodanog do najranije dodanog elementa):\n";
    for (string i: suSto) {
        cout << i << '\n';
    }

    

}


void obrada_signala(int signal) {

    string prioritet;

    switch (signal) {

        case SIGHUP:
        prioritet = "1";
        break;

        case SIGUSR1:
        prioritet = "2";
        
        case SIGQUIT:
        prioritet = "3";

        case SIGTRAP:
        prioritet = "4";

        case SIGABRT:
        prioritet = "5";

        default:
        break;
    
    }

    if (signal == SIGINT) ispis_stanja(5, "obrada nekog signala valjda");

    
}


int main(void) {

    signal(SIGINT, obrada_signala);

    int PID = getpid();
    cout << "signali poredani od najmanjeg do najvećeg prioriteta:\n";
    cout << "1 SIGHUP\n";
    cout << "2 SIGUSR1\n";
    cout << "3 SIGQUIT\n";
    cout << "4 SIGTRAP\n";
    cout << "5 SIGABRT\n";
    cout << "\nPID" << PID << '\n';

    ostalo["GP"] = false;
    ostalo["t"] = -1;

    for (;;) {
        
        if (!ostalo["GP"]) {
            
            ostalo["t"]++;
            ispis_stanja(0, "U glavnom programu");
            ostalo["GP"] = 1;

        }
        
    }

    return 0;

}