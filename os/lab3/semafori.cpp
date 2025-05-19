#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/shm.h>
#include <semaphore.h>


using std::vector;
using std::cout;
using std::string;


sem_t *sem_ulazak_kupci0;
sem_t *sem_ulazak_kupci1;
sem_t *sem_ulazak_kupci2;

sem_t *sem_sastojci;


string sastojci[3] = {
        "kruh",
        "sir",
        "šunka"
};

int *stol;


void proc_trgovac()
{

    vector<string> trgovac_sastojci;

    usleep(500000);

    int a = 2;

    while (1) {

        trgovac_sastojci.clear();

        // sleep(1);

        // cekaj_semafor_za_sastojke_na_stolu();
        sem_wait(sem_sastojci);

        // postavi_sastojke_na_stol();

        if (*stol == -1) {

            // TODO iz nekog razloga trgovac uvijek stavlja istu vrstu proizvoda pa to treba popraviti
            // zasada koristim ovu zakrpu
            int vrsta = (time(nullptr) + a++ % 3) % 3;


            for (int i = 0; i < 3; i++) {
                if (i != vrsta)
                    trgovac_sastojci.push_back(sastojci[i]);
            }

            cout << "trgovac: " << trgovac_sastojci[0] << " i " << trgovac_sastojci[1] << '\n';

            *stol = vrsta;
            cout << "stol: " << *stol << "\n\n";

        }

        // postavi_semafor_za_sastojke_na_stolu();
        sem_post(sem_sastojci);


    }

}


void proc_kupac(int vrsta_kupca, int broj_kupca)
{

    string kupac_sastojak = sastojci[vrsta_kupca];

    cout << "kupac " << broj_kupca << ": " << kupac_sastojak << '\n';

    // cekaj_semafor_za_uci_u_trgovinu();
    switch (vrsta_kupca) {

        case 0:
            sem_wait(sem_ulazak_kupci0);
            break;

        case 1:
            sem_wait(sem_ulazak_kupci1);
            break;

        case 2:
            sem_wait(sem_ulazak_kupci2);
            break;
        
        default:
            cout << "????\n";
            break;

    }

    // while (nema potrebnih sastojaka) {
    //     cekaj_semafor_za_sastojke_na_stolu();
    //     pogledaj_sastojke();
    //     if (jos nema sastojaka) postavi_semafor_za_sastojke_na_stolu();
    // }
    int sastojci_prisutni = 0;

    while (!sastojci_prisutni) {

        sem_wait(sem_sastojci);

        // cout << "kupac " << broj_kupca << " (" << vrsta_kupca << ")" << " vidi: " << *stol << '\n';

        if(*stol == vrsta_kupca)
            sastojci_prisutni++;

        else 
            sem_post(sem_sastojci);

    }

    // uzmi_sastojke();
    cout << "kupac " << broj_kupca << " sastavlja sendvič i jede\n\n";
    *stol = -1;
    
    // postavi_semafor_za_sastojke_na_stolu();
    sem_post(sem_sastojci);

    // postavi_semafor_za_uci_u_trgovinu();
    switch (vrsta_kupca) {

        case 0:
            sem_post(sem_ulazak_kupci0);
            break;

        case 1:
            sem_post(sem_ulazak_kupci1);
            break;

        case 2:
            sem_post(sem_ulazak_kupci2);
            break;
        
        default:
            cout << "????\n";
            break;

    }

    return;

}


int main(void)
{

    // semafor za kupce vrste 0 koji još nisu ušli u trgovinu
    int ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_ulazak_kupci0 = (sem_t*) shmat(ID, NULL, 0);
    shmctl (ID, IPC_RMID, NULL);

    sem_init(sem_ulazak_kupci0, 1, 1);
    sem_post(sem_ulazak_kupci0);

    // semafor za kupce vrste 1 koji još nisu ušli u trgovinu
    ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_ulazak_kupci1 = (sem_t*) shmat(ID, NULL, 0);
    shmctl (ID, IPC_RMID, NULL);

    sem_init(sem_ulazak_kupci1, 1, 1);
    sem_post(sem_ulazak_kupci1);

    // semafor za kupce vrste 2 koji još nisu ušli u trgovinu
    ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_ulazak_kupci2 = (sem_t*) shmat(ID, NULL, 0);
    shmctl (ID, IPC_RMID, NULL);

    sem_init(sem_ulazak_kupci2, 1, 1);
    sem_post(sem_ulazak_kupci2);

    // semafor za trgovca i kupce koji su u trgovini
    ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_sastojci = (sem_t*) shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);

    sem_init(sem_sastojci, 1, 1);
    sem_post(sem_sastojci);

    // preko ove varijable određuje se koji su sastojci na stolu
    // -1 - stol je prazan
    // 0 - sir i šunka
    // 1 - kruh i šunka
    // 2 - kruh i sir
    ID = shmget(IPC_PRIVATE, sizeof(int), 0600);
    stol = (int*) shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);
    *stol = -1;

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

    sem_destroy(sem_ulazak_kupci0);
    shmdt(sem_ulazak_kupci0);

    sem_destroy(sem_sastojci);
    shmdt(sem_sastojci);

    return 0;

}
