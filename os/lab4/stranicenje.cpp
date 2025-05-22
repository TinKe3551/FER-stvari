#include <bits/stdc++.h>


void izvjestaj() {

}


int main(void) {

    using namespace std;

    int n_proc;
    int n_str;
    int n_okv;
    int vel_str;
    int vel_prog;
    int vel_mem;

    cout << "količina procesa: ";
    cin >> n_proc;

    cout << "veličina procesa u stranicama: ";
    cin >> n_str;

    cout << "količina raspoloživih okvira: ";
    cin >> n_okv;

    cout << "veličina stranica u riječima: ";
    cin >> vel_str;

    vel_prog = vel_str * n_str;
    vel_mem = vel_str * n_okv;

    srand(time(nullptr) + clock());

    int okviri[n_okv][2]; // {broj procesa, broj stranice)
    int A_zast[n_proc][n_str + 1];

    int i = 0;
    int n_koristenih_okvira = 0;
    while (1) {

        sleep(rand() % 3 + 1);

        int proc = rand() % n_proc;
        int trazena_adr = rand() % vel_prog + 1 + proc * vel_prog;
        int trazena_str = trazena_adr / vel_str;

        cout << "proces " << proc + 1 << " traži pristup adresi " << trazena_adr;

        if (n_koristenih_okvira < n_okv) {

            okviri[i][0] = proc;
            okviri[i][1] = trazena_str;

            i = (i + 1) % n_okv;

            for (int j = 0; j < n_okv; j++) {
                cout << j << ". okvir: proc " << okviri[j][0] + 1 << " str " << okviri[j][1] 
                << " (" << A_zast[okviri[j][0]][okviri[j][1]] << '\n';
            }

        }

        bool pogodak = false;
        for (int j = 0; j < n_okv && !pogodak; j++) {
            if (okviri[j][0] == proc && okviri[j][1] == trazena_str) {
                cout << "pogodak\n";
                pogodak = true;
            }
        }
        if (pogodak) continue;

        while (A_zast[okviri[i][0]][okviri[i][1]] != 0) {
            A_zast[okviri[i][0]][okviri[i][1]] = 0;
            i = (i + 1) % n_okv;
        }

    }

}