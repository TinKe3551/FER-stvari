#include <bits/stdc++.h>
#include <ctime>
#include <pthread.h>
#include <unistd.h>


using namespace std;


int main(void) {

    cout << "prodavac je na pauzi\n";

    int lol = 1;

    int glavni_pid = getpid();

    while (lol > 0) {

        int t = clock();

        // printf("glavni proces %d", getpid());

        lol = fork();

        usleep(1000000 - (t - clock()));

    }

    cout << "kupac " << getpid() << " krepava od gladi\n";
    cout << "glavni pid: " << glavni_pid << '\n';

    return 0;

}