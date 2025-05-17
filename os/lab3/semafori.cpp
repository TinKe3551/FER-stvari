#include <bits/stdc++.h>


using namespace std;

string sastojci[3] = {
        "kruh",
        "sir",
        "šunka"
};


void proc_trgovac() 
{

    vector<string> trgovac_sastojci;

    usleep(500000);

    while (1) {

        sleep(1);

        // cekaj_semafor_za_sastojke_na_stolu();
        // postavi_sastojke_na_stol();

        int vrsta = rand() % 3 + 1;

        for (int i = 0; i < 3; i++) {
            if (i != vrsta)
                trgovac_sastojci.push_back(sastojci[i]);
        }

        cout << "trgovac: " << trgovac_sastojci[0] << " i " << trgovac_sastojci[1] << '\n';

        // postavi_semafor_za_sastojke_na_stolu();



    }

}


void proc_kupac(int vrsta_kupca, int broj_kupca)
{

    string kupac_sastojak = sastojci[vrsta_kupca];

    cout << "kupac " << broj_kupca << ": " << kupac_sastojak << '\n';
    
    // cekaj_semafor_za_uci_u_trgovinu(); // svaka vrsta kupaca  ima svoj semafor za uci u trgovinu



    // while (nema potrebnih sastojaka) {
    //     cekaj_semafor_za_sastojke_na_stolu();
    //     pogledaj_sastojke();
    //     postavi_semafor_za_sastojke_na_stolu();
    // }

    cout << "kupac " << broj_kupca << " sastavlja sendvič i jede\n\n";

    // postavi_semafor_za_uci_u_trgovinu();


    return;

}


int main(void)
{

    int glavni_pid = getpid();

    int f = fork();

    if (f > 0) { // proces trgovca

        proc_trgovac();

    }

    else if (f == 0) { // proces koji generira procese kupaca

        int broj_kupca = 0;

        

        while (1) {

            broj_kupca++;

            int f2 = fork();

            if (f2 > 0) {

                sleep(1);

                // samo proces za generiranje kupaca
                // smije opet ulaziti u petlju
                continue;

            }

            else if (f2 == 0) { // proces kupca
                
                // nasumični odabir vrste kupca
                srand(time(nullptr));
                int vrsta_kupca = rand() % 3;                

                proc_kupac(vrsta_kupca, broj_kupca);

            }

            else {
                cout << "???\n";
            }

            // da ne bi slucajno i procesi kupaca krenuli
            // generirati jos procesa kupaca
            return 0;

        }

    }

    else {
        cout << "??\n";
    }

    return 0;

}
