#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>
#include <fcntl.h>


#define SEM_STOL "SEM_STOL"
#define SEM_KUPCI0 "SEM_KUPCI0"
#define SEM_KUPCI1 "SEM_KUPCI1"
#define SEM_KUPCI2 "SEM_KUPCI2"


char* sastojci[] = {
    "kruh",
    "šunka",
    "sir"
};

int* stol;


void proc_trgovac() {

    sem_t* sem_stol = sem_open(SEM_STOL, 0);

    while (1) {

        sem_wait(sem_stol);
        // printf("trgovac je došao do stola\n");

        if (*stol == -1) {

            *stol = rand() % 3;

            printf("\ntrgovac na stol stavlja:\n");
            for (int i = 0; i < 3; i++) {
                if (i != *stol) {
                    printf("%s\n", sastojci[i]);
                }
            }

            printf("\n");

        }
        // usleep(500000);

        // printf("trgovac odlazi od stola\n");
        sem_post(sem_stol);

    }

}


void proc_kupac(int broj_kupca, int vrsta_kupca) {

    printf("novi kupac %d (%s)\n", broj_kupca, sastojci[vrsta_kupca]);

    sem_t* sem_stol = sem_open(SEM_STOL, 0);
    sem_t* sem_trgovina;
    switch (vrsta_kupca) {
        case 0:
            sem_trgovina = sem_open(SEM_KUPCI0, 0);
            break;
        case 1:
            sem_trgovina = sem_open(SEM_KUPCI1, 0);
            break;
        case 2:
            sem_trgovina = sem_open(SEM_KUPCI2, 0);
            break;
        default:
            break;
    }

    sem_wait(sem_trgovina);

    int imam_sastojke = 0;

    while (!imam_sastojke) {

        sem_wait(sem_stol);

        // printf("kupac %d (%s) dolazi do stola\n", broj_kupca, sastojci[vrsta_kupca]);

        if (*stol == vrsta_kupca) {
            *stol = -1;
            imam_sastojke++;
        }

        else {
            // printf("kupac %d (%s) odlazi od stola\n", broj_kupca, sastojci[vrsta_kupca]);
            sem_post(sem_stol);
        }

    }

    printf("kupac %d (%s) slaže sendvič i jede\n", broj_kupca, sastojci[vrsta_kupca]);

    sem_post(sem_stol);
    sem_post(sem_trgovina);

    return;

}


sem_t* stavi_semafor(char* ime) {
    
    // za slučaj da je semafor otprije otvoren bez da je nakon toga zatvoren
    sem_t* sem = sem_open(ime, O_CREAT, 0666, 1234);
    sem_close(sem);
    sem_unlink(ime);

    // ovo je zapravo semafor koji će se koristiti
    sem = sem_open(ime, O_CREAT, 0666, 1);

    return sem;

}


int main(void) {
    
    sem_t* sem_stol = stavi_semafor(SEM_STOL);
    sem_t* sem_kupci0 = stavi_semafor(SEM_KUPCI0);
    sem_t* sem_kupci1 = stavi_semafor(SEM_KUPCI1);
    sem_t* sem_kupci2 = stavi_semafor(SEM_KUPCI2);
    
    int ID = shmget(IPC_PRIVATE, sizeof(int), 0600);
    stol = (int*) shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);
    *stol = -1;

    int f = fork();

    if (f > 0) {
        proc_trgovac();
    }

    else if (f == 0) {

        for (int i = 0;; i++) {

            int f2 = fork();

            if (f2 > 0) {

                sleep(1);

                continue;

            }

            else {

                srand(clock());
                int vrsta_kupca = rand() % 3;

                proc_kupac(i + 1, vrsta_kupca);

            }

            return 0;

        }

    }

    return 0;

}