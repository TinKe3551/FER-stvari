#include <bits/stdc++.h>


using namespace std;


void kupac() {}


int main(void) {

    int glavni_pid = getpid();

    int f = fork();

    if (f > 0) { // proces trgovca

        

    }

    else if (f == 0) { // proces koji generira procese kupaca

        while (1) {

            int f2 = fork();

            if (f2 > 0) {

                usleep(1000000);
                continue;

            }

            else if (f2== 0) { // proces kupca

                kupac();

            }

            // da ne bi slucajno i procesi kupaca krenuli
            // generirati jos procesa kupaca
            break;

        }

    }

}
