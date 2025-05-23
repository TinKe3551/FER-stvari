#include <bits/stdc++.h>


int main(void) {

    using namespace std;

    int n_proc; // koliko procesa
    int n_str; // koliko stranica po procesu
    int n_okv; // koliko okvira
    int vel_str; // koliko riječi po stranici
    int vel_prog; // koliko riječi po programu
    int vel_mem; // koliko riječi u primarnoj memoriji

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

    int okviri[n_okv][2]; // {broj procesa, broj stranice)
    int A_zast[n_proc][n_str + 1];

    int i = 0;
    int n_kor_okv = 0;
    while (1) {

        sleep(3);

        int proc = rand() % n_proc;
        int trazena_adr = rand() % vel_prog + 1;
        int trazena_str = (trazena_adr - 1) / vel_str + 1;
        trazena_adr += proc * vel_prog;

        cout << "\nproces " << proc + 1 << " traži pristup adresi " << trazena_adr
        << " (" << trazena_str << ". stranica)\n";

        bool pogodak = false;
        for (int j = 0; j < n_kor_okv && !pogodak; j++) {
            if (okviri[j][0] == proc && okviri[j][1] == trazena_str) {
                pogodak = true;
            }
        }

        if (pogodak) {
            cout << "++pogodak++\n";
            A_zast[proc][trazena_str] = 1;
        }

        else if (n_kor_okv < n_okv) {

            cout << "--promašaj--\n";

            okviri[i][0] = proc;
            okviri[i][1] = trazena_str;

            i = (i + 1) % n_okv;

            n_kor_okv++;

            A_zast[proc][trazena_str] = 1;

        }

        else {

            cout << "--promašaj--\n";

            while (A_zast[okviri[i][0]][okviri[i][1]] != 0) {
                A_zast[okviri[i][0]][okviri[i][1]] = 0;
                i = (i + 1) % n_okv;
            }

            okviri[i][0] = proc;
            okviri[i][1] = trazena_str;
            A_zast[proc][trazena_str] = 1;
            i = (i + 1) % n_okv;

        }

        for (int j = 0; j < n_kor_okv; j++) {

            if (i == j) cout << "> ";

            cout << j + 1 << ". okvir: proc " << okviri[j][0] + 1 << " str " << okviri[j][1] 
            << " (A=" << A_zast[okviri[j][0]][okviri[j][1]] << ")\n";

        }

    }

    return 0;

}
