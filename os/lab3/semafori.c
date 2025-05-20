#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>

#define SEM_STOL "SEM_STOL"
#define SEM_KUPCI0 "SEM_KUPCI0"
#define SEM_KUPCI1 "SEM_KUPCI1"
#define SEM_KUPCI2 "SEM_KUPCI2"

sem_t *sem;
sem_t *sem_ulazak_kupci1;
sem_t *sem_ulazak_kupci2;

sem_t *sem_sastojci;

char* sastojci[] = {
        "kruh",
        "sir",
        "šunka"
};

int *stol;


void stanje() {
    // printf("stol: %p\n", (void*)sem_sastojci);
    // printf("kupci0: %p\n", (void*)sem_ulazak_kupci0);
    // printf("kupci1: %p\n", (void*)sem_ulazak_kupci1);
    // printf("kupci2: %p\n", (void*)sem_ulazak_kupci2);
    // printf("sastojci na stolu: %d\n", *stol);
    return;
}



void proc_trgovac()
{

    char* trgovac_sastojci[2];

    while (1) {

        // sleep(1);

        // cekaj_semafor_za_sastojke_na_stolu();
        sem_wait(sem_sastojci);

        // printf("trgovac dolazi do stola\n");
        stanje();

        // usleep(500000);

        // postavi_sastojke_na_stol();

        if (*stol == -1) {

            // TODO iz nekog razloga trgovac uvijek stavlja istu vrstu proizvoda kada koristim srand() i rand() pa to treba popraviti
            // zasada koristim ovu zakrpu
            int vrsta = (clock() % 3) % 3;

            int i = 0;

            for (int j = 0; j < 3; j++) {
                if (j != vrsta) trgovac_sastojci[i++] = sastojci[j];
            }


            printf("trgovac: %s i %s\n", trgovac_sastojci[0], trgovac_sastojci[1]);

            *stol = vrsta;

            printf("stol: %d\n", *stol);

        }

        // postavi_semafor_za_sastojke_na_stolu();
        // printf("trgovac odlazi od stola\n");
        sem_post(sem_sastojci);

    }

}


void proc_kupac(int vrsta_kupca, int broj_kupca)
{

    char* kupac_sastojak = sastojci[vrsta_kupca];

    printf("novi kupac %d (%d): %s\n", broj_kupca, vrsta_kupca, kupac_sastojak);
    stanje();

    // cekaj_semafor_za_uci_u_trgovinu();
    switch (vrsta_kupca) {

        case 0:
            sem_wait(sem);
            break;

        case 1:
            sem_wait(sem_ulazak_kupci1);
            break;

        case 2:
            sem_wait(sem_ulazak_kupci2);
            break;
        
        default:
            break;

    }

    // printf("kupac %d (%d) ulazi u trgovinu\n", broj_kupca, vrsta_kupca);

    // while (nema potrebnih sastojaka) {
    //     cekaj_semafor_za_sastojke_na_stolu();
    //     pogledaj_sastojke();
    //     if (jos nema sastojaka) postavi_semafor_za_sastojke_na_stolu();
    // }
    int sastojci_prisutni = 0;

    while (!sastojci_prisutni) {

        sem_wait(sem_sastojci);

        // printf("kupac %d (%d) dolazi do stola\n", broj_kupca, vrsta_kupca);
        
        // usleep(500000);

        // cout << "kupac " << broj_kupca << " (" << vrsta_kupca << ")" << " vidi: " << *stol << '\n';

        if(*stol == vrsta_kupca)
            sastojci_prisutni++;

        else {
            // printf("kupac %d (%d) odlazi od stola\n", broj_kupca, vrsta_kupca);
            sem_post(sem_sastojci);
        }

    }

    // uzmi_sastojke();
    printf("kupac %d (%d) sastavlja sendvič i jede\n", broj_kupca, vrsta_kupca);
    *stol = -1;
    
    // postavi_semafor_za_sastojke_na_stolu();
    sem_post(sem_sastojci);
    // printf("kupac %d (%d) odlazi sa stola\n", broj_kupca, vrsta_kupca);

    // printf("kupac %d (%d) odlazi iz trgovine\n", broj_kupca, vrsta_kupca);

    // postavi_semafor_za_uci_u_trgovinu();
    switch (vrsta_kupca) {

        case 0:
            sem_post(sem);
            break;

        case 1:
            sem_post(sem_ulazak_kupci1);
            break;

        case 2:
            sem_post(sem_ulazak_kupci2);
            break;
        
        default:
            break;

    }

    return;

}


int main(void)
{
    // semafor za kupce vrste 0 koji još nisu ušli u trgovinu
    int ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem = (sem_t*) shmat(ID, NULL, 0);
    shmctl (ID, IPC_RMID, NULL);

    sem_init(sem, 1, 1);
    sem_post(sem);

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

    // debug, provjera ispravnosti semafora
    // if (fork() == 0) {
    //     sem_wait(sem_sastojci);
    //     while (1) sleep(1);
    // }
    // if (fork() == 0) {
    //     sem_wait(sem_ulazak_kupci0);
    //     while (1) sleep(1);
    // }
    // if (fork() == 0) {
    //     sem_wait(sem_ulazak_kupci1);
    //     while (1) sleep(1);
    // }
    // if (fork() == 0) {
    //     sem_wait(sem_ulazak_kupci2);
    //     while (1) sleep(1);
    // }

    if (f > 0) { // proces trgovca

        proc_trgovac();

    }

    else if (f == 0) { // proces koji generira procese kupaca

        int broj_kupca = 0;

        for(int abc = 0; abc < 20; abc++) {

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
                srand(clock());
                int vrsta_kupca = rand() % 3;

                proc_kupac(vrsta_kupca, broj_kupca);

            }

            // da ne bi slucajno i procesi kupaca krenuli
            // generirati jos procesa kupaca
            exit(0);

        }

    }

    // sem_destroy(sem_ulazak_kupci0);
    shmdt(sem);

    // sem_destroy(sem_sastojci);
    shmdt(sem_sastojci);

    return 0;

}
