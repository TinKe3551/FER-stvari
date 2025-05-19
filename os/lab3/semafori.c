#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>


sem_t *sem_stol;
sem_t *sem_kupci0;
sem_t *sem_kupci1;
sem_t *sem_kupci2;

int *stol;

char* sastojci[] = {
    "kruh",
    "šunka",
    "sir"
};


void proc_trgovac()
{
    while(1) {

        sem_wait(sem_stol);

        if (*stol == -1) {
            
        }

    }

    return;
}


void proc_kupac()
{
    return;
}


int main(void)
{
    // semafor za čitanje i pisanje u stanje stola
    int ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_stol = shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);

    // semafor za kupce vrste 0 (kruh)
    ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_kupci0 = shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);

    // semafor za kupce vrste 1 (šunka)
    ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_kupci1 = shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);

    // semafor za kupce vrste 2 (sir)
    ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_kupci2 = shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);

    // varijabla za stanje na stolu
    // -1 stol je prazan
    // 0 šunka i sir
    // 1 kruh i sir
    // 2 kruh i šunka
    ID = shmget(IPC_PRIVATE, sizeof(int), 0600);
    stol = shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);
    *stol = -1;

    int f = fork();

    if (f > 0) { // proces trgovca

        proc_trgovac();

    }

    else if (f == 0) {

        int broj_kupca = 0;

        while (1) {

            broj_kupca++;

            int f2 = fork();

            if (f2 > 0) { // proces koji generira precese kupaca

                sleep(1);

                // samo ovaj proces smije opet ulaziti u petlju
                continue;

            }

            else if (f2 == 0) { // procesi kupaca

                // nasumični odabir vrste kupca
                srand(clock());
                int vrsta_kupca = rand() % 3;

                proc_kupac(vrsta_kupca, broj_kupca);

            }

            // da ne bi slučajno procesi kupaca krenuli generirati još procesa kupaca
            return 0;

        }

    }

    sem_destroy(sem_stol);
    shmdt(sem_stol);
    sem_destroy(sem_kupci0);
    shmdt(sem_kupci0);
    sem_destroy(sem_kupci1);
    shmdt(sem_kupci1);
    sem_destroy(sem_kupci2);
    shmdt(sem_kupci2);

    return 0;
}