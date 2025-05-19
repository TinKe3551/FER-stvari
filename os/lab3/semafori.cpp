#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/shm.h>
#include <semaphore.h>


using namespace std;


sem_t *sem_kupci_ulazak = (sem_t*) malloc(sizeof(sem_t));
sem_t *sem_sastojci = (sem_t*) malloc(sizeof(sem_t));


string sastojci[3] = {
        "kruh",
        "sir",
        "šunka"
};

int *stol;

// za vrste kupaca 0, 1 i 2 informacija o tome je li u trgovini prisutan kupac te vrste
int *kv0;
int *kv1;
int *kv2;


void proc_trgovac()
{

    vector<string> trgovac_sastojci;

    usleep(500000);


    while (1) {

        trgovac_sastojci.clear();

        sleep(1);

        // cekaj_semafor_za_sastojke_na_stolu();
        sem_wait(sem_sastojci);

        // postavi_sastojke_na_stol();
        srand(time(nullptr));
        int vrsta = rand() % 3;


        for (int i = 0; i < 3; i++) {
            if (i != vrsta)
                trgovac_sastojci.push_back(sastojci[i]);
        }

        cout << "trgovac: " << trgovac_sastojci[0] << " i " << trgovac_sastojci[1] << '\n';

        // postavi_semafor_za_sastojke_na_stolu();
        sem_post(sem_sastojci);


    }

}


void proc_kupac(int vrsta_kupca, int broj_kupca)
{

    string kupac_sastojak = sastojci[vrsta_kupca];

    cout << "kupac " << broj_kupca << ": " << kupac_sastojak << '\n';

    // cekaj_semafor_za_uci_u_trgovinu(); // svaka vrsta kupaca  ima svoj semafor za uci u trgovinu
    sem_wait(sem_kupci_ulazak);

    // if (u trgovini nema kupac iste vrste) uđi();

    // while (nema potrebnih sastojaka) {
    //     cekaj_semafor_za_sastojke_na_stolu();
    //     pogledaj_sastojke();
    //     if (jos nema sastojaka) postavi_semafor_za_sastojke_na_stolu();
    // }

    // uzmi_sastojke();
    // postavi_semafor_za_sastojke_na_stolu();

    cout << "kupac " << broj_kupca << " sastavlja sendvič i jede\n\n";

    // postavi_semafor_za_uci_u_trgovinu();
    sem_post(sem_kupci_ulazak);

    return;

}


int main(void)
{

    // semafor za kupce koji još nisu ušli u trgovinu
    int ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    shmctl (ID, IPC_RMID, NULL);
    sem_kupci_ulazak = (sem_t*) shmat(ID, NULL, 0);
    sem_init(sem_kupci_ulazak, 1, 1);
    sem_post(sem_kupci_ulazak);

    // semafor za trgovca i kupce koji su u trgovini
    ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    shmctl(ID, IPC_RMID, NULL)
    sem_init(sem_sastojci, 1, 1);
    sem_post(sem_sastojci);

    

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

    sem_destroy(sem_kupci_ulazak);
    shmdt(sem_kupci_ulazak);

    sem_destroy(sem_sastojci);
    shmdt(sem_sastojci);

    return 0;

}
